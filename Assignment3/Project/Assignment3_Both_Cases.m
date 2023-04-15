clc;
clear all;
format short;

delay = 86.5/1000;
h =delay*1.1; 
numStates =2000;

%DEfine A
A = [-520 -220 0 0 0 ;
     220 -500 -999994 0 2*10.^8;
     0 1 0 0 0;
     0 0 66667 -0.1667 -1.3333*10.^7;
     0 0 0 1 0
];

B = [1000 ; 0 ;0 ;0; 0];
C = [0 0 0 0 1 ];

%Prepare for augment
A_disc  = expm(A*h);
sys_cont = ss(A, B, C, 0);

sys_disc = c2d(sys_cont, h); % the output can be changed
A_disc = sys_disc.a;
B_disc =sys_disc.b;

inv_A = inv(A_disc);

r_1_0 = (h - delay)*B;
r_1_t = delay*B;


%augment the matrix including both old input and state.
A_augment = [A_disc r_1_t ;zeros(1,6)]; % should be (4+1)x (4+1)
B_augment = [r_1_0;1];  % should be (4+1, 1)
C_augment = [C 0];

% build Q matrix. should panalize state 3 and 4
Q = eye(6);
Q(3,3) =4^13;
Q(4,4) =0.04;
Q(1,1) =140;
Q(1,2) =130;
Q(1,5) =250;
Q(2,2) =70;
Q(4,2) =4.1;
Q(4,2) =-10;
Q(3,2) =-10;
Q(5,2) =30;
Q(5,5) =40;
Q(5,3) =30;
Q(5,1) =30;


%compute LQR
[X, L, G] = dare(A_augment,B_augment, Q, 0.5);

gamma = [B_augment A_augment*B_augment A_augment^2*B_augment A_augment^3*B_augment A_augment^4*B_augment A_augment^5*B_augment];
if (det(gamma)== 0)
disp('unControllable')
else
disp('Controllable')
end

%place poles
%K = -acker(A_augment,B_augment,alphas);
K =-G;
% forward gain
F = 1/(C_augment*inv(eye(6)-A_augment-B_augment*K)*B_augment);

r = 0.002; % reference

x_ = [0; 0 ;0 ;0 ;0;0 ];
tol = 1e-3; % set a tolerance for convergence
error = Inf; % initialize error to a large value
t_converge = 0; % initialize the time at which convergence is achieved


output_x = zeros(numStates, length(x_)); % to store values
input(2) = 0; input(1)=0; 
time(2) = h; time(1) =0; % time initial conditions
error = 0;
length_itter = length(x_)/h;
condition_to_stop =10;
for i=2:length_itter

    y(i) = C_augment*x_;
    u  =K*[x_] +F*r;

    x_ = A_augment*x_ + B_augment*u;
    output_x(i+1,:) = x_';
    
    %check constraints
    if(checkConditions(x_, u,[3,4], 35, 12))
       disp('Conditioned falied');
    end
    
    %Stores the input and time
    input(i+1) = u;
    time(i+1) = time(i) + h;
    
    % compute error and check for convergence
    error = abs(output_x(i+1, 1) - r);
    if error < tol && t_converge == 0 % check if converged
        t_converge = time(i+1); % record the time of convergence
    end

    % break the loop if converged
    if t_converge > 0
        condition_to_stop =condition_to_stop-1;
        if(condition_to_stop==0)
        break
        end
    end
end


max_input = max(input);
min_input = min(input);

plot(time(1:i), y, 'b');
hold on;
plot(time(1:i+1), input, 'r')
hline = refline([0 r]);

% Add text to the figure to show the maximum and minimum input values
text(time(1), max_input, ['Max Input: ' num2str(max_input)], 'HorizontalAlignment', 'left', 'VerticalAlignment', 'top')
text(time(1), min_input, ['Min Input: ' num2str(min_input)], 'HorizontalAlignment', 'left', 'VerticalAlignment', 'bottom')

legend('State', 'Input', 'Reference Line', 'Location', 'best')
title('System Response');
xlabel('Time (sec)');
ylabel('x1');
ylim([0, 2*r]); % set y-axis limit



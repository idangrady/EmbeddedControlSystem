
clc;
clear all;
format short;

km=4.4*10^(-2);
j1 =3.75*10^(-6);
j2 =  3.75*10^(-6);
b =1*10^(-5);
d=3.125*10^(-5);
k = 0.2656;
h =0.0029; 
delay = h/3;
numStates =2000;

%DEfine A
A = [0 0 1 0;
    0 0 0 1 ;
    -k/j1 k/j1 -(d+b)/j1 (d+b)/j1;
    k/j2 -k/j2 (d+b)/j2 -(b+d)/j2];

B = [0 ; 0 ;km/j1 ;0];
C = [1 0 0 0 ];

%Prepare for augment
A_disc  = expm(A*h);
sys_cont = ss(A, B, C, 0);
sys_disc = c2d(sys_cont, h); % the output can be changed
A_disc = sys_disc.a;
B =sys_disc.b;

inv_A = inv(A_disc);
r_1_t = inv_A*(A_disc - expm(A*(h-delay)))*B; % compute the r1 for the augmented matrix
r_1_0 = inv_A*(expm(A*(h-delay)) - 1)*B; % compute the r1 for the augmented matrix

%augment the matrix including both old input and state.
A_augment = [A_disc r_1_t ;zeros(1,5)]; % should be (4+1)x (4+1)
B_augment = [r_1_0;1];  % should be (4+1, 1)
C_augment = [C 0];

% build Q matrix. should panalize state 3 and 4
Q = eye(5);
Q(3,3) =0.07;
Q(3,1) =0;
Q(5,1) =0;
Q(1,2) =0;
Q(4,4) =0.1;

%compute LQR
[X, L, G] = dare(A_augment,B_augment, Q, 0.5);

gamma = [B_augment A_augment*B_augment A_augment^2*B_augment A_augment^3*B_augment A_augment^4*B_augment];
if (det(gamma)== 0)
disp('unControllable')
else
disp('Controllable')
end

%place poles
alphas = [0.6 0.6 0.1 0.1 0.2];
%K = -acker(A_augment,B_augment,alphas);
K =-G;
% forward gain
F = 1/(C_augment*inv(eye(5)-A_augment-B_augment*K)*B_augment);

r = 1; % reference

x_ = [0; 0 ;0 ;0 ;0 ];
tol = 1e-3; % set a tolerance for convergence
error = Inf; % initialize error to a large value
t_converge = 0; % initialize the time at which convergence is achieved


output_x = zeros(numStates, length(x_)); % to store values
input(2) = 0; input(1)=0; 
time(2) = h; time(1) =0; % time initial conditions
error = 0;

for i=2:length(x_)/h

    y(i) = C_augment*x_;
    u  =K*[x_] +F*r;
   

    x_ = A_augment*x_ + B_augment*u;
    output_x(i+1,:) = x_';
    
    %check constraints
    checkConditions(x_, u,[3,4], 50, 1);
    
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
        break
    end
end


plot(time(1:i), y, 'b');
hold
plot(time(1:i+1), input, 'r')
hline = refline([0 r]);
legend('State', 'Input', 'Reference Line', 'Location', 'best')
title('System Response');
xlabel('Time (sec)');
ylabel('x1');
ylim([0, 2*r]); % set y-axis limit

disp('Load MIL_PIL_Simulation_2022')

disp('Finished')






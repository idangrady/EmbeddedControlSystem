%open MIL_PIL_Simulation_2022.slx;
clc;
clear;


%constants
km=4.4*10^(-2);
j1 =3.75*10^(-6);
j2 =  3.75*10^(-6);
b =1*10^(-5);
d=3.125*10^(-5);
k = 0.2656;
numStates =2000;

%design1
h_rotary = 0.0029;
delay = h_rotary/3;

A = [0 0 1 0;
    0 0 0 1 ;
    -k/j1 k/j1 -(d+b)/j1 (d+b)/j1;
    k/j2 -k/j2 (d+b)/j2 -(b+d)/j2];
B = [0 ; 0 ;km/j1 ;0];
C = [1 0 0 0 ];
inv_A =[

      0             0        j2/(b*d - j1*j2)   j1/(j1*j2 - b*d);
      0             0       -j2/(b*d - j1*j2)  -j1/(j1*j2 - b*d);
      0             0      -(d+b)/(b*d - j1*j2) (j1 + j2)/(b*d - j1*j2);
      0             0       (b+d)/(b*d - j1*j2) -(j1 + j2)/(b*d - j1*j2);
];


sys_cont = ss(A, B, C, 0);
sys_disc = c2d(sys_cont, h_rotary);
phi = sys_disc.a;
Gamma =sys_disc.b;
%C = sys_disc.c;

%Gamma0 = inv_A*(expm(A*(h_rotary-delay))-1)*B;
%Gamma1 = inv_A*(expm(A*h_rotary)-expm(A*(h_rotary-delay)))*B;

Gamma0 = (h_rotary - delay)*B;
Gamma1 = delay*B;

phi_aug = [phi Gamma1;0 0 0 0 0];
Gamma_aug = [Gamma0; 1];
C_aug = [C 0];

alpha = [0.6,0.6,0.6,0.6,0.6];

K = -acker(phi_aug,Gamma_aug,alpha);
F =  1/(C_aug*inv(eye(5)-phi_aug-Gamma_aug*K)*Gamma_aug);

r = 1; % reference

x_ = [0; 0 ;0 ;0 ;0 ];
tol = 1e-3; % set a tolerance for convergence
error = Inf; % initialize error to a large value
t_converge = 0; % initialize the time at which convergence is achieved


output_x = zeros(numStates, length(x_)); % to store values
input(2) = 0; input(1)=0; 
time(2) = h_rotary; time(1) =0; % time initial conditions
error = 0;

for i=2:length(x_)/h_rotary

    y(i) = C_aug*x_;
    u  =K*[x_] +F*r;
   

    x_ = phi_aug*x_ + Gamma_aug*u;
    output_x(i+1,:) = x_';
    
    %check constraints
    checkConditions(x_, u,[3,4], 50, 1);
    
    %Stores the input and time
    input(i+1) = u;
    time(i+1) = time(i) + h_rotary;
    
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

assignment1_2022_Simulink_init_Dualrotary(delay,h_rotary,K,F);


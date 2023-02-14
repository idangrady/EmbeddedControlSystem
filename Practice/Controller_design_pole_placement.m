

clc;
clear all;
format short;

d = 3.125*10^(-5);
b =10^(-5);
k =0.2656; 
km = 4.4*10^(-2);
j1 = 3.75*10^(-6);
j2 = 3.75*10^(-6);

A=[0 0 1 0 ;
    0 0 0 1;
    -k/j1 k/j1 -(d+b)/j1 (d+b)/j1;
    k/j2 -k/j2 (d+b)/j2 -(d+b)/j2]

B=[0  0  km/j1 0]';
C=[1 0 0 0];

eigs(A)
sysc = ss(A,B,C,0);

T_period = 0.5;
delay = 0.1;
sysd = c2d(sysc, T_period); phi = sysd.a; Gamma = sysd.b; C = sysd.c;

% eye(2) + A*T_period
Gamma0 = inv(A)*(expm(A*(T_period-delay))-expm(A*0))*B;
% (T_period - delay)*B
Gamma1 = inv(A)*(expm(A*T_period)-expm(A*(T_period-delay)))*B;
% (delay)*B
PHi_o = expm(A*T_period);
R1_t = delay*B;
R0_t = (T_period-delay)*B;

PHI_OG = [PHi_o R1_t; zeros(1,5)]
R_0_og = [R0_t;1]
phi_aug = [phi  Gamma1;zeros(1,5)];

Gamma_aug = [Gamma0; 1];
C_aug = [C 0];

gamma = [Gamma_aug phi_aug*Gamma_aug phi_aug^2*Gamma_aug phi_aug^3*Gamma_aug phi_aug^4*Gamma_aug];
det(gamma)
if det(gamma) == 0
    disp('Uncontrollable')
else
    disp('Controllable');
end

H = (phi_aug - eye(3)*0.2)^3
K = - [0 0 1]*inv(gamma)*H;
% K = -acker(Aaug, Baug, [0.9 0.9 0.9]) 
Acl = (phi_aug + Gamma_aug*K);
F = 1/(C_aug*inv(eye(3)-Acl)*Gamma_aug);

% K = -acker(phi,Gamma,[0.9 0.9])
% F = 1/(C*inv(eye(2)-phi-Gamma*K)*Gamma)

x1(2) = 45; x1(1) = 45;
x2(2) = 0.0; x2(1) = 0.0;
input(2) = 0; input(1) = 0;
time(2) = T_period; time(1) = 0;
i = 2;
r = 90.0;
for i=2:40/T_period
    
    u = K*[x1(i);x2(i);input(i-1)] + r*F;
%     u = K*[x1(i);x2(i)] + r*F;
    xkp1 = phi*[x1(i);x2(i)]+ Gamma1*input(i-1) + Gamma0*u;
    x1(i+1) = xkp1(1);
    x2(i+1) = xkp1(2);
    input(i+1) = u;    
    time(i+1) = time(i) + T_period;   
end

plot(time, x1, 'r');
% hold;
% figure
% plot(time, input, 'r');
max(abs(input))

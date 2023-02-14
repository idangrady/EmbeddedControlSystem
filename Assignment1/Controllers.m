
clc;
clear all;
format short;

km=4.4*10^(-2);
j1 =3.75*10^(-6);
j2 =  3.75*10^(-6);
b =1*10^(-5);
d=3.125*10^(-5);
k = 0.2656;

A = [0 0 1 0;
    0 0 0 1 ;
    -k/j1 k/j1 -(d+b)/j1 (d+b)/j1;
    k/j2 -k/j2 (d+b)/j2 -(b+d)/j2];


B = [0 ; 0 ;km/j1 ;0];
C = [1 0 0 0];

sys_cont = ss(A, B, C, 0);
h =0.005; 
sys_disc = c2d(sys_cont, h); % the output can be changed
phi = sys_disc.a;

Gamma = sys_disc.b;
gamma = [Gamma phi*Gamma phi^2*Gamma phi^3*Gamma];
det(gamma)

alphas = [0.1 0.1 0.1 0.1];
K = -acker(phi,Gamma,alphas);
% forward gain
F = 1/(C*inv(eye(4)-phi-Gamma*K)*Gamma);

r = 1; % reference

x1(2) = 10.0; x1(1) = 10.0; 
x2(1) = 11.0; x2(2) = 11.0; 
x3(2)=20.0; x3(1) = 20.0;
x2(1)=20.0; x4(2) = 20.0;

tol = 1e-3; % set a tolerance for convergence
error = Inf; % initialize error to a large value
t_converge = 0; % initialize the time at which convergence is achieved


input(2) = 0; input(1)=0; time(2) = h; time(1) =0;
error = 0;
for i=2:2/h
u_unbounded  =K*[x1(i); x2(i) ;x3(i); x4(i)] +F*r;
u = min(max(u_unbounded, -1), 1); % Apply saturation to u
x3(i) = min(x3(i), 50); % Apply saturation to x3 max(u_unbounded, -50)
x4(i) = min(x4(i), 50); % Apply saturation to x4 max(u_unbounded

xkpl = phi*[x1(i); x2(i) ;x3(i); x4(i)] + Gamma*u;
x1(i+1) = xkpl(1);
x2(i+1) = xkpl(2);
x3(i+1) = xkpl(3);
x4(i+1) = xkpl(4);
input(i+1) = u;
time(i+1) = time(i) + h;

% compute error and check for convergence
error = abs(x1(i+1) - r);
if error < tol && t_converge == 0 % check if converged
    t_converge = time(i+1); % record the time of convergence
end

% break the loop if converged
if t_converge > 0
    break
end
end
% plot results
plot(time(1:i+1), x1(1:i+1), 'b');
hold
plot(time(1:i+1), input, 'r')
hline = refline([0 r]);
legend('State', 'Input', 'r')
title('System Response');
xlabel('Time (sec)');
ylabel('x1');
ylim([0, 2*r]); % set y-axis limit




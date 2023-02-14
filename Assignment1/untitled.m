
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

%Assume poles are in -1
r = 1; % constraint 1

x1(2) = 10.0; x1(1) = 10.0; 
x2(1) = 11.0; x2(2) = 11.0; 
x3(2)=20.0; x3(1) = 20.0;
x2(1)=20.0; x4(2) = 20.0;

input(2) = 0; input(1)=0; time(2) = h; time(1) =0;
error = 0;
for i=2:2/h
u =K*[x1(i); x2(i) ;x3(i); x4(i)] +F*r;
xkpl = phi*[x1(i); x2(i) ;x3(i); x4(i)] + Gamma*u;
x1(i+1) = xkpl(1);
x2(i+1) = xkpl(2);
x3(i+1) = xkpl(3);
x4(i+1) = xkpl(4);
input(i+1) =u;
time(i+1)=time(i)+h;
if(computeError()>0)
end

plot(time, x1, 'b');
max(input);


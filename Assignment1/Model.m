

km=4.4*10^-2;
j1 =3.75*10^-6;
j2 =  3.75*10^-6;
b =1*10^-5;
d=3.125*10^-5;
i =1;
k = 0.2656;

A = [0 0 1 0;
    0 0 0 1 ;
    -k/j1 k/j1 -(d+b)/j1 (d+b)/j1;
    k/j2 -k/j2 (d+b)/j2 -(b+d)/j2];

B = [0 ; 0 ;km/j1 ;0];
C = [1 0 0 0];
delay = 0.1;

h1 =0.02;
h2 = 2*h1;

sys_cont = ss(A,B,C,0);
sys_disc = c2d(sys_cont, h1);



phi = sys_disc.a
Gamma  = sys_disc.b
C = sysd.c;


Gamma0 = inv(A)*(expm(A*(T_period-delay))-expm(A*0))*B;
gamma =[Gamma phi*Gamma phi^2 *Gamma phi^3*Gamma]
det(gamma)


K = -acker(phi,Gamma,alpha)

%%

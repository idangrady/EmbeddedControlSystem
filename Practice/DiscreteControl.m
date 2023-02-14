A = [0 1 ; 0 0 ];
B = [0;1];
C = [1 0];

h = 0.05; % sampling HOD 

sys_cont= ss(A,B,C,0);
sys_disc = c2d(sys_cont, h);

phi = sys_disc.A
gamma = sys_disc.B

eigs(phi)
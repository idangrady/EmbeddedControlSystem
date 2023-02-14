

A = [0 1 0 0 ; 0 0 5 0 ; 0 0 0 1; 0 0 0 0];
B =[0 0 0 1];
B = transpose(B);
C = [1 0 0 0];

%poles -2 -2 -3 -3 

eigs(A)
gamma = [B A*B A^2*B A^3*B];
g_inv = inv(gamma);

if det(gamma)==0 
    disp('uncontrollable')
else
    disp('controllable')
end

%conpute H based on the poles

H = (A+ 2*eye(4)) *(A+ 2*eye(4))*(A+ 3*eye(4))*(A+ 3*eye(4));
K = -transpose(B)*g_inv*H;
eigs(A+B*K)






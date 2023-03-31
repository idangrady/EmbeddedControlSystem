%% Run Coppelia Simulation
clc(); clear();
format long;
addpath '../..'                     % for helper functions (ILC, PID etc)
addpath '../../functions'

sim = remApi('remoteApi');          % use Coppelia remote API
sim.simxFinish(-1);                 % close any previous connections

% 'defines' for commonly used commands
op_blocking = sim.simx_opmode_blocking;
op_oneshot = sim.simx_opmode_oneshot;
op_streaming = sim.simx_opmode_streaming;
op_buffer = sim.simx_opmode_buffer;

% establish new connection, port 19997 connection default
clientID = sim.simxStart('127.0.0.1', 19997, true, true, 5000, 5);

% if code passes this block, simulation is running
if (clientID < 0)
    disp("CoppeliaSim connection could not be established. Exiting.");
    return;
end

sim.simxSynchronous(clientID, true);
sim.simxStartSimulation(clientID, op_blocking);
disp("CoppeliaSim simulation started successfully.");

% retrieve all handles
[returnCode, motor] = sim.simxGetObjectHandle(clientID, 'Prismatic_joint', op_blocking);
[returnCode, base] = sim.simxGetObjectHandle(clientID, 'cube_base', op_blocking);
[returnCode, slide] = sim.simxGetObjectHandle(clientID, 'cube_slide', op_blocking);
[returnCode, cam] = sim.simxGetObjectHandle(clientID, 'Vision_sensor', op_blocking);
[returnCode, chip] = sim.simxGetObjectHandle(clientID, 'chip_0', op_blocking);

% retrieve simulation params & initialize data streams
[returnCode, pos_cube] = sim.simxGetObjectPosition(clientID, slide, base, op_streaming);
[returnCode, max_f] = sim.simxGetJointMaxForce(clientID, motor, op_streaming);
[returnCode, pos_joint] = sim.simxGetJointPosition(clientID, motor, op_streaming);
[returnCode, chip_pos] = sim.simxGetObjectPosition(clientID, chip, base, op_streaming);
[returnCode, resolution, image] = sim.simxGetVisionSensorImage2(clientID, cam, 0, op_streaming);

% initialize parameters
[returnCode] = sim.simxSetJointTargetVelocity(clientID, motor, 0, op_blocking);
[returnCode] = sim.simxSetJointMaxForce(clientID, motor, 0, op_blocking);
[returnCode] = sim.simxSetJointPosition(clientID, motor, 0, op_blocking);
sim.simxGetPingTime(clientID);

% check to see if initialization has worked
[returnCode, pos_cube] = sim.simxGetObjectPosition(clientID, slide, base, op_buffer);
[returnCode, force] = sim.simxGetJointMaxForce(clientID, motor, op_buffer);
[returnCode, pos_joint] = sim.simxGetJointPosition(clientID, motor, op_buffer);
%disp("cube: " + (pos_cube(2)-0.1) + ", max_f: " + max_f + ", joint: " + pos_joint);

% Initialize controller settings
f = 0;
N = 200;             % discrete samples per iteration
ILC_iterations = 1;     % ILC disabled, single trace
Ts = 0.005;             % sampling rate (must be equal to Coppelia)
t = 0:Ts:((N-1)*Ts);
cam_pos = 0.03;         % location of camera object in CoppeliaSim

prev_sign = 1;          % for dynamics calculations
prev_pos = pos_joint;
damping_const = 1;

% Initialize data objects (for plotting)
p_cube = zeros(1,N);
p_joint = zeros(1,N);
u = zeros(1,N);
sum_forces = zeros(1,N);
speed_trace = zeros(1,N);
vision_trace = zeros(1,N);

% % Initialize data objects
% [r,e,u,in,x,y,time] = ...
%     initialize_loop(N);

% Initialize PID controller C(z)
% NOTE:
% PID-controller is tuned based on transfer function of data-based P(z)
% See preparation report for more details.
% Feel free to tune PID to your liking (k1, k2, k3 values).
% Derivation of discrete PID can be found in pid_implementation_derivation.m


% Make sure motor can move only from here
[returnCode] = sim.simxSetJointTargetVelocity(clientID, motor, 0.1, op_blocking);

total_force = 0.2;

for j=1:ILC_iterations
    
    for k=1:N
        % Calculate time (can also be done outside loop)
        time(k) = (k-1) * Ts;

        % Sense encoder position
        [returnCode, pos_joint] = sim.simxGetJointPosition(clientID, motor, op_buffer);
        p_joint(k) = pos_joint;
        force(k) = 0.2;    
        
        [returnCode] = sim.simxSetJointTargetVelocity(clientID, motor, sign(total_force) * 0.1, op_blocking);
        
        [returnCode] = sim.simxSetJointMaxForce(clientID, motor, abs(total_force), op_blocking);

        % execute simulation step
        sim.simxSynchronousTrigger(clientID); sim.simxGetPingTime(clientID);
    end

end

% ensure final command has been executed and stop simulation
sim.simxGetPingTime(clientID); 
% pause();
sim.simxStopSimulation(clientID, op_blocking);

% also kill all data streams
sim.simxGetObjectPosition(clientID, slide, base, sim.simx_opmode_discontinue);
sim.simxGetJointMaxForce(clientID, motor, sim.simx_opmode_discontinue);
sim.simxGetJointPosition(clientID, motor, sim.simx_opmode_discontinue);

sim.simxFinish(clientID);
sim.delete();

%% Plot position, speed and controller output plots
figure(1);
plot(t(1:k), p_joint(1:k), 'DisplayName', 'Linear Encoder');
hold on;
plot(t(1:k), vision_trace(1:k), 'DisplayName', 'Vision Sensor');
xlabel('Time [s]') 
ylabel('Chip Position [m]') 
grid on;
hold off;
legend;
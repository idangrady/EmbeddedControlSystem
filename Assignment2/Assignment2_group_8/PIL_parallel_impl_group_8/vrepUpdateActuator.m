function output = vrepUpdateActuator(input)

% vrepParam = [
%   1 clientID      -> vrepParam(1)
%   2 cam           -> vrepParam(2)
%   3 motor         -> vrepParam(3)
%   4 chip          -> vrepParam(4)
%   5 base          -> vrepParam(5) ]

vrepParam = input(4:end);
force_lock = input(2);
force = input(1);

damping_constant = 1;
sim_step = 0.015;

global vrep;
global prev_sign;
global total_force;
global time;
global counter;
global prev_pos;
global sampling_period;

% Initial Data
if (time == 0)
    [returnCode, chip_pos] = vrep.simxGetObjectPosition(vrepParam(1), vrepParam(4), vrepParam(5), vrep.simx_opmode_buffer);
    chip_pos = double((chip_pos(2)-1.4 + 0.025/2)) + 0.001;
    prev_pos = chip_pos;
    total_force = 0;
    prev_sign = 0;
end

%log data out
[returnCode, chip_pos_out] = vrep.simxGetObjectPosition(vrepParam(1), vrepParam(4), vrepParam(5), vrep.simx_opmode_buffer);
chip_pos_out = double((chip_pos_out(2)-1.4 + 0.025/2)) + 0.001;

if (force_lock == 1)

% execute simulation steps, each step is 5 ms
for iter = 1:(sampling_period/sim_step)
    [returnCode, chip_pos] = vrep.simxGetObjectPosition(vrepParam(1), vrepParam(4), vrepParam(5), vrep.simx_opmode_buffer);
    chip_pos = double((chip_pos(2)-1.4 + 0.025/2)) + 0.001;
    speed = (chip_pos - prev_pos)/sim_step;
    applied_force = total_force - speed*damping_constant;
    speed*damping_constant
    prev_pos = chip_pos;
    % reverse motor direction if force/PID-output changes signs
    if (sign(applied_force) ~= sign(prev_sign))
        [returnCode] = vrep.simxSetJointTargetVelocity(vrepParam(1), vrepParam(3), sign(applied_force) * 0.1, vrep.simx_opmode_blocking);
    end
    prev_sign = sign(applied_force);
    
    [returnCode] = vrep.simxSetJointMaxForce(vrepParam(1), vrepParam(3), abs(applied_force), vrep.simx_opmode_blocking);
    vrep.simxSynchronousTrigger(vrepParam(1)); vrep.simxGetPingTime(vrepParam(1));
end


total_force = force;
counter = counter + 1;
time = time + sampling_period;
end
output = [chip_pos_out, time, counter];

end
 function vrepParam = vrepStart(u)
    clc(); clear();
    
    global vrep;
%% MATLAB controller with V-REP simulation
    
    vrep = remApi('remoteApi');          % use Coppelia remote API
    vrep.simxFinish(-1);                 % close any previous connections
    
    % 'defines' for commonly used commands
    op_blocking = vrep.simx_opmode_blocking;
    op_oneshot = vrep.simx_opmode_oneshot;
    op_streaming = vrep.simx_opmode_streaming;
    op_buffer = vrep.simx_opmode_buffer;
    
    % establish new connection, port 19997 connection default
    clientID = vrep.simxStart('127.0.0.1',19997,true,true,5000,5);
    
    if (clientID>-1)
        disp('Connected to remote API server');
        %switch on synchronous mode
        vrep.simxSynchronous(clientID,true);
        %% Commands before first simstep
        % start the co-simulation:
        vrep.simxStartSimulation(clientID,op_blocking);

        %% initial co-simulation configuration
        % Handle V-REP objects
        [returnCode, motor] = vrep.simxGetObjectHandle(clientID, 'Prismatic_joint', op_blocking);
        [returnCode, base] = vrep.simxGetObjectHandle(clientID, 'cube_base', op_blocking);
        [returnCode, slide] = vrep.simxGetObjectHandle(clientID, 'cube_slide', op_blocking);
        [returnCode, cam] = vrep.simxGetObjectHandle(clientID, 'Vision_sensor', op_blocking);
        [returnCode, chip] = vrep.simxGetObjectHandle(clientID, 'chip_0', op_blocking);
        
        %% retrieve simulation params & initialize data streams
        [returnCode, pos_cube] = vrep.simxGetObjectPosition(clientID, slide, base, op_streaming);
        [returnCode, max_f] = vrep.simxGetJointMaxForce(clientID, motor, op_streaming);
        [returnCode, pos_joint] = vrep.simxGetJointPosition(clientID, motor, op_streaming);
        [returnCode, chip_pos] = vrep.simxGetObjectPosition(clientID, chip, base, op_streaming);
        [returnCode, resolution, image] = vrep.simxGetVisionSensorImage2(clientID, cam, 0, op_streaming);
        
        %% initialize parameters
        [returnCode] = vrep.simxSetJointTargetVelocity(clientID, motor, 0, op_blocking);
        [returnCode] = vrep.simxSetJointMaxForce(clientID, motor, 0, op_blocking);
        [returnCode] = vrep.simxSetJointPosition(clientID, motor, 0, op_blocking);
        vrep.simxGetPingTime(clientID);

    end
    
    vrepParam = double([clientID, cam, motor, chip, base]);
 end
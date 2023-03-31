function total_force = vrepUpdateActuator(input)
 
    % vrepParam = [
%   1 clientID      -> vrepParam(1)
%   2 cam           -> vrepParam(2)
%   3 motor         -> vrepParam(3)

  vrepParam = input(2:end);
  total_force = input(1);
  
  global vrep;
  global prev_sign;
  
  % reverse motor direction if force/PID-output changes signs
  if (sign(total_force) ~= sign(prev_sign))
    [returnCode] = vrep.simxSetJointTargetVelocity(vrepParam(1), vrepParam(3), sign(total_force) * 0.1, vrep.simx_opmode_blocking);
  end
  prev_sign = sign(total_force);
  [returnCode] = vrep.simxSetJointMaxForce(vrepParam(1), vrepParam(3), abs(total_force), vrep.simx_opmode_blocking);
  
  % execute simulation step
  vrep.simxSynchronousTrigger(vrepParam(1)); vrep.simxGetPingTime(vrepParam(1));
 end       
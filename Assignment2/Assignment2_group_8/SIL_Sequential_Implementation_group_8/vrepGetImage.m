 function out_image = vrepGetImage(vrepParam)
    
    % vrepParam = [
%   1 clientID      -> vrepParam(1)
%   2 cam           -> vrepParam(2)
%   3 motor         -> vrepParam(3)
    global vrep;

    [returnCode,pingTime]=vrep.simxGetPingTime(vrepParam(1));
    % get updated camera image  
    [returnCode,resolution,image]=vrep.simxGetVisionSensorImage2(vrepParam(1),vrepParam(2),0,vrep.simx_opmode_buffer);
    
%     imshow(image)
    gray = rgb2gray(image);
    out_image = double(gray);
    
 end
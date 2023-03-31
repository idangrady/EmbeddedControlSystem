 function output = vrepGetImage(vrepParam)
    
    % vrepParam = [
%   1 clientID      -> vrepParam(1)
%   2 cam           -> vrepParam(2)
%   3 motor         -> vrepParam(3)
%   4 chip          -> vrepParam(4)
%   5 base          -> vrepParam(5) ]

    global vrep;
    
%     [returnCode,pingTime]=vrep.simxGetPingTime(vrepParam(1));
    % get updated camera image  
    [returnCode,resolution,image]=vrep.simxGetVisionSensorImage2(vrepParam(1),vrepParam(2),0,vrep.simx_opmode_buffer);
    
    imwrite(image,'test.png');
    image = rgb2gray(image);
 
    out_image = double(image);
    output = out_image;
 end
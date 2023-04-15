
% to meet the constraints for the input and states

function [bool] = checkConditions(x_, u,states, cond_state, cond_input)
    bool = false;
    for i=1:length(states)
        cur_state = states(i);
        if (x_(cur_state)> cond_state)
            disp(cur_state);
            disp('state  constraint failed');
            bool = true;
        end
    end

    if(abs(u)>=cond_input)
     disp('input constraint failed')
     bool = true;
    end    
end
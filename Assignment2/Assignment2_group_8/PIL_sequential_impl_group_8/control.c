#include <stdlib.h>
#include <control.h>
#include <memory_access.h>
#include <mapping.h>
#include <config.h>


float pPart = 0.0, iPart = 0.0, dPart = 0.0;
float Err = 0, prev_Err = 0;

//#define K_P                 ((float)70)             //
//#define K_D                 ((float)10)             //change the gains
//#define K_I                 ((float)50)  

void PID_controller()
{
    
    
    uint8_t lock = read_lock(CONTROLLER_LOCK_LOCATION);
    
    if (lock == LOCK)
    {
        
        float control_input[1];
        
        float current_pos[1], desired_pos[1];
        
        
        
        
        read_float(desired_pos, DESIRED_POS_LOCATION, 1);
        read_float(current_pos, CURRENT_POS_LOCATION, 1);
        
        Err = desired_pos[0] - current_pos[0]; //error
        float diff_Err = Err - prev_Err;
        
        pPart = K_P *  Err;
        
        if (abs(Err) < (abs(desired_pos[0] * 0.1))) {
            iPart = iPart + K_I * SAMPLING_TIME * Err;
        }
        else {
            iPart = 0.0;
        }
        dPart = K_D * diff_Err * INV_SAMPLING_TIME;
        control_input[0] =  (pPart + iPart + dPart);
        
        prev_Err = Err;
        
        
        write_float(control_input, FORCE_LOCATION, 1);
        write_lock(LOCK, FORCE_LOCK_LOCATION);
        write_lock(UNLOCK, CONTROLLER_LOCK_LOCATION);
        
        
        
        
    }
}

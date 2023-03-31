#include <stdlib.h>
#include "control.h"

#define SAMPLING_TIME       0.005
#define INV_SAMPLING_TIME   200
#define K_P                 0.01
#define K_D                 0.001
#define K_I                 0

volatile float pPart = 0.0, iPart = 0.0, dPart = 0.0;
volatile float Err = 0, prev_Err = 0;

float PID_controller(float desired_pos, float current_pos)
{
    float control_input =desired_pos;
    int diff_Err = Err - prev_Err;
    
    Err = desired_pos - current_pos;
    pPart = K_P *  Err;
    if (abs(Err) < abs(desired_pos*0.1)) {
        iPart +=  K_I * SAMPLING_TIME *  Err;
    }
    else {
        iPart = 0;
    }
    dPart = K_D * diff_Err * INV_SAMPLING_TIME;
    control_input =  (pPart + iPart + dPart);
    prev_Err = Err;
    
    return control_input;
}
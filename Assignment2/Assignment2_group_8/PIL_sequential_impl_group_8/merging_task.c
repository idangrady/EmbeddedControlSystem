#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory_access.h>
#include <mapping.h>
#include <config.h>
#include "merging_task.h"


void merging_task ()

{
    uint8_t lock = read_lock(MERGING_LOCK_LOCATION);
    if (lock == LOCK)
    {
        
        float     pi = 0.0175f;
        float     left_edge[1];
        float     right_edge[1];
        float     left_edge_theta[1];
        float     right_edge_theta[1];
        float     current_pos[1] = {0};
        float   data_peaks[MAX_PEAK_NUMBER*2] = {0};
        float   data_peaks_test[MAX_PEAK_NUMBER*2] = {0};
        float     data_peaks_0[1];
        float     data_peaks_1[1];
        float     data_peaks_2[1];
        float     data_peaks_3[1];
        float     desiredPos[1] = {DESIRED_POS};
        float     test_edge[1]={0};
        
        
        read_float(data_peaks_test, DATA_PEAK_LOCATION_0, 4);
        
        
        data_peaks[0] = data_peaks_test[0];
        data_peaks[1] = data_peaks_test[1];
        data_peaks[2] = data_peaks_test[2];
        data_peaks[3] = data_peaks_test[3];
        
        
        
        left_edge_theta[0]   = (data_peaks[1 + MAX_PEAK_NUMBER])* pi;
        right_edge_theta[0] = (data_peaks[0 + MAX_PEAK_NUMBER])*pi;
        
        
        
        left_edge[0] = data_peaks[1]/cosf(left_edge_theta[0]) - (IMG_HEIGHT/2)*sinf(left_edge_theta[0])/cosf(left_edge_theta[0]);
        
        right_edge[0] = data_peaks[0]/cosf(right_edge_theta[0]) - (IMG_HEIGHT/2)*sinf(right_edge_theta[0])/cosf(right_edge_theta[0]);
        
        
        
        
        if (left_edge[0] < 0.0f)
            left_edge[0] = 0.0f;
        if (right_edge[0] > (IMG_WIDTH - 1))
            right_edge[0] = (IMG_WIDTH - 1);
        
        current_pos[0] = (int)((left_edge[0] + right_edge[0]) / 2.0f);
        
        
        
        write_float(desiredPos, DESIRED_POS_LOCATION, 1);
        write_float(current_pos, CURRENT_POS_LOCATION, 1);
        
        write_lock(UNLOCK, PICTURE_LOCK_LOCATION);
        write_lock(UNLOCK, MERGING_LOCK_LOCATION);
        write_lock(LOCK, CONTROLLER_LOCK_LOCATION);
        
    }
    
}
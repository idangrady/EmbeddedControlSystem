#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <config.h>
#include "merging_task.h"


float merging_task (int16_t data_peaks_0[1], int16_t data_peaks_1[1] , int16_t data_peaks_2[1], int16_t data_peaks_3[1])
{
    
    float     pi = 0.0175f;
    float     left_edge;
    float     right_edge;
    float     left_edge_theta;
    float     right_edge_theta;
    float     current_pos;
    int16_t  data_peaks[MAX_PEAK_NUMBER*2] = {0};
    
    data_peaks[0] = data_peaks_0[0];
    data_peaks[1] = data_peaks_1[0];
    data_peaks[2] = data_peaks_2[0];
    data_peaks[3] = data_peaks_3[0];
    
    
    
    left_edge_theta   = (float)(data_peaks[1 + MAX_PEAK_NUMBER])* pi;
    right_edge_theta  = (float)(data_peaks[0 + MAX_PEAK_NUMBER])*pi;
    
    
    
    left_edge = data_peaks[1]/cosf(left_edge_theta) - (IMG_HEIGHT/2)*sinf(left_edge_theta)/cosf(left_edge_theta);
    right_edge = data_peaks[0]/cosf(right_edge_theta) - (IMG_HEIGHT/2)*sinf(right_edge_theta)/cosf(right_edge_theta);
    
    
    
    if (left_edge < 0.0f)
        left_edge = 0.0f;
    if (right_edge > (IMG_WIDTH - 1))
        right_edge = (IMG_WIDTH - 1);
    
    current_pos = (int)((left_edge + right_edge) / 2.0f);
    
    return current_pos;
}
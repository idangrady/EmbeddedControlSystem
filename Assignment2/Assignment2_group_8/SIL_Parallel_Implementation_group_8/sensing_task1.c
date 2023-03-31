#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <config.h>
#include "sensing_task1.h"


#define THETA_MIN           	(1)
#define THETA_MAX           	(5)
#define NUMBER_OF_THETA     	(THETA_MAX - THETA_MIN +1)

void sensing_task(uint8_t rcv_img_data[IMG_SIZE], int16_t data_peaks_0[1], int16_t data_peaks_1[1], int16_t data_peaks_2[1], int16_t data_peaks_3[1])



{
    
    
    float cost[NUMBER_OF_THETA] = {0.9998f,    0.9994f ,   0.9986f ,  0.9976f ,   0.9962f ,   1.0000f};
    float sint[NUMBER_OF_THETA] = {0.0175f ,   0.0349f ,  0.0523f  ,  0.0698f ,  0.0872f  ,      0};
    
    
    uint8_t     isDone = 0;
    uint8_t     peakIdx = 0;
    int16_t     ex = -90;
    int16_t     k;
    int16_t     rhoToRemove;
    int16_t     maxVal;
    int16_t     jPeak;
    uint8_t     d1;
    int16_t     rhoMin;
    int16_t     rhoMax;
    int16_t     thetaMax;
    int16_t     thetaMin;
    int16_t     threshold = HOUGH_THRESHOLD;
    int16_t     desiredPos[1] = {DESIRED_POS};
    
    uint16_t     eq;
    uint16_t      h[2000] = {0};
    float     left_edge;
    float     right_edge;
    float     left_edge_theta;
    float     right_edge_theta;
    int16_t 	 peakCoordinates[MAX_PEAK_NUMBER*2] = {0};
    int16_t 	 data_peaks[MAX_PEAK_NUMBER*2] = {0};
    int16_t      current_pos;
    int16_t      thetaIdx;
    
    float pPart = 0.0, iPart = 0.0, dPart = 0.0;
    float Err = 0, prev_Err = 0;
    float desired_pos = 44;
    float control_input = 0;
    float pi = 0.0175f;
    float test_datapeak;
    int16_t  MAX_NEGATIVE_RHO;
    int16_t  NUMBER_OF_RHO ;
    int16_t  HOUGH_AREA_SIZE  ;
    
    
    MAX_NEGATIVE_RHO    = IMG_HEIGHT*sint[0];
    
    if (MAX_NEGATIVE_RHO<0)
    {
        MAX_NEGATIVE_RHO = round((-1)*MAX_NEGATIVE_RHO);
    }
    else
    {
        MAX_NEGATIVE_RHO = round(MAX_NEGATIVE_RHO);
    }
    
    NUMBER_OF_RHO       =  round((IMG_WIDTH*cost[NUMBER_OF_THETA-1] + IMG_HEIGHT*sint[NUMBER_OF_THETA-1] + MAX_NEGATIVE_RHO));
    HOUGH_AREA_SIZE     =  round((NUMBER_OF_RHO * NUMBER_OF_THETA));
    
    
    int16_t j = 0;
    for (int x = 0; x < IMG_WIDTH; x++) {
        for (int y = 0; y < IMG_HEIGHT; y++) {
            if (rcv_img_data[y + IMG_HEIGHT * x]==1) {
                for (thetaIdx = 0; thetaIdx < NUMBER_OF_THETA; thetaIdx++) {
                    eq  =   lroundf(x * cost[thetaIdx] +  y * sint[thetaIdx] + MAX_NEGATIVE_RHO);
                    h[eq + NUMBER_OF_RHO * thetaIdx]++;
                    j++;
                }
            }
        }
    }
    
    
    while (!isDone) {
        maxVal = -1;
        jPeak = -1;
        rhoToRemove = -1;
        
        for (ex = 0; ex < NUMBER_OF_THETA; ex++) {
            for (k = 0; k < NUMBER_OF_RHO; k++) {
                d1 = h[k + NUMBER_OF_RHO * ex];
                
                if (d1 > maxVal) {
                    rhoToRemove = k;
                    jPeak = ex;
                    maxVal = d1;
                    isDone = 1;
                }
            }
        }
        if ((jPeak != -1) && (h[(rhoToRemove + NUMBER_OF_RHO * jPeak)] >= threshold)) {
            peakIdx++;
            peakCoordinates[peakIdx - 1] = (rhoToRemove - MAX_NEGATIVE_RHO);
            peakCoordinates[peakIdx + MAX_PEAK_NUMBER -1] = (jPeak + THETA_MIN);
            
            
            rhoMin = rhoToRemove - PADDING_SIZE_RHO;
            rhoMax = rhoToRemove + PADDING_SIZE_RHO;
            thetaMax = jPeak + PADDING_SIZE_THETA;
            thetaMin = jPeak - PADDING_SIZE_THETA;
            
            if (rhoMin < 0) {
                rhoMin = 0;
            }
            if (rhoMax > NUMBER_OF_RHO - 1) {
                rhoMax = NUMBER_OF_RHO - 1;
            }
            if (thetaMin < 0) {
                thetaMin = 0;
            }
            if (thetaMax > NUMBER_OF_THETA - 1) {
                thetaMax = NUMBER_OF_THETA - 1;
            }
            
            for (ex = thetaMin; ex <= thetaMax; ex++) {
                for (k = rhoMin; k <= rhoMax; k++) {
                    h[(k + NUMBER_OF_RHO * ex)] = 0;
                }
            }
            isDone = (peakIdx == MAX_PEAK_NUMBER);
        }
        else {
            isDone = 1;
        }
    }
    
    
    
    
    
    
    // Assign peak
    if (peakIdx != 0) {
        for (ex = 0; ex < peakIdx; ex++) {
            data_peaks[ex] = peakCoordinates[ex];
            data_peaks[ex + MAX_PEAK_NUMBER] = peakCoordinates[ex + MAX_PEAK_NUMBER];
        }
    }
    
    
    
    // Sorting
    for (int a = 0; a < MAX_PEAK_NUMBER - 1; a++)
    {
        for (int b = a + 1; b < MAX_PEAK_NUMBER; b++)
        {
            if( data_peaks[b] > data_peaks[a])
            {
                int temp = data_peaks[a];
                int temp1 = data_peaks[a + MAX_PEAK_NUMBER];
                // Swap a and b
                data_peaks[a] = data_peaks[b];
                data_peaks[a + MAX_PEAK_NUMBER] =  data_peaks[b + MAX_PEAK_NUMBER];
                data_peaks[b] = temp;
                data_peaks[b + MAX_PEAK_NUMBER] =  temp1;
            }
        }
    }
    
    
    
    
    data_peaks_0[0] =   data_peaks[0];
    data_peaks_1[0] =   data_peaks[1];
    data_peaks_2[0] =   data_peaks[2];
    data_peaks_3[0] =   data_peaks[3];
    
    
    
}

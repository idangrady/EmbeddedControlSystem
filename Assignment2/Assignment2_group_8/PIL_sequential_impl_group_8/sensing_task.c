#include <sensing_task.h>
#include <memory_access.h>
#include <mapping.h>


#define THETA_MIN           	(-5)
#define THETA_MAX           	(5)
#define NUMBER_OF_THETA     	(THETA_MAX - THETA_MIN +1)

const float cost[NUMBER_OF_THETA] = {0.996195 , 0.997564, 0.998630, 0.999391, 0.999848, 1.000000, 0.999848, 0.999391, 0.998630, 0.997564, 0.996195};
const float sint[NUMBER_OF_THETA] = {-0.087156, -0.069756, -0.052336, -0.034899, -0.017452, 0.000000, 0.017452, 0.034899, 0.052336, 0.069756, 0.087156};

#define DISTANCE_BETWEEN_CHIPS  (7)

uint8_t rcv_img_data[IMG_SIZE] = {0};

void hough_transform()
{
    
    
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
    uint8_t     threshold = HOUGH_THRESHOLD;
    float       desiredPos[1] = {DESIRED_POS};
    float       current_pos[1] = {0};
    int16_t     eq;
    uint8_t     h[2000] = {0};
    float       left_edge;
    float       right_edge;
    float       left_edge_theta;
    float       right_edge_theta;
    int16_t 	peakCoordinates[MAX_PEAK_NUMBER*2] = {0};
    int16_t 	data_peaks[MAX_PEAK_NUMBER*2] = {0};
    uint8_t 	picture_lock = read_lock(PICTURE_LOCK_LOCATION);
    int16_t  MAX_NEGATIVE_RHO;
    int16_t  NUMBER_OF_RHO ;
    int16_t  HOUGH_AREA_SIZE  ;
    
    
    float data_peaks_test[4]={0};
    
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
    
    
    if (picture_lock == LOCK)
    {
        read_byte (rcv_img_data, PICTURE_LOCATION, IMG_SIZE);
        for (int x = 0; x < IMG_WIDTH; x++) { // 88
            for (int y = 0; y < IMG_HEIGHT; y++) { // 142
                if (rcv_img_data[y + IMG_HEIGHT * x]==1) {
                    for (int thetaIdx = 0; thetaIdx < NUMBER_OF_THETA; thetaIdx++) {
                        eq  =   lroundf(x * cost[thetaIdx] +  y * sint[thetaIdx] + MAX_NEGATIVE_RHO); // + IMG_HEIGHT*sind(THETA_MIN)
                        h[eq + NUMBER_OF_RHO * thetaIdx]++;
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
        
        
        
        data_peaks_test[0]=(float)(data_peaks[0]);
        data_peaks_test[1]=(float)(data_peaks[1]);
        data_peaks_test[2]=(float)(data_peaks[2]);
        data_peaks_test[3]=(float)(data_peaks[3]);

        write_float(data_peaks_test, DATA_PEAK_LOCATION_0, 4);
        
        write_lock(LOCK, MERGING_LOCK_LOCATION);
        
        
    }
    
}
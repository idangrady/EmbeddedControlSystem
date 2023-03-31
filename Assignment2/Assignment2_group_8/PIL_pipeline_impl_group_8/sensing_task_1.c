#include <sensing_task.h>
#include <memory_access.h>
#include <mapping.h>

#if defined(THETA_neg_5_pos_5)
#define NUMBER_OF_THETA     	(11)
#define THETA_MIN           	(-5)
#define THETA_MAX           	(5)
#define HALF_NUMBER_OF_THETA    (6)
const float cost[NUMBER_OF_THETA] = {0.996195 , 0.997564, 0.998630, 0.999391, 0.999848, 1.000000, 0.999848, 0.999391, 0.998630, 0.997564, 0.996195};
const float sint[NUMBER_OF_THETA] = {-0.087156, -0.069756, -0.052336, -0.034899, -0.017452, 0.000000, 0.017452, 0.034899, 0.052336, 0.069756, 0.087156};
#define MAX_NEGATIVE_RHO    	(13)   // IMG_HEIGHT*sind(THETA_MIN)
#define NUMBER_OF_RHO       	(113)   // (IMG_WIDTH*cosd(THETA_MAX) + IMG_HEIGHT*sind(THETA_MAX) + MAX_NEGATIVE_RHO)
#define HOUGH_AREA_SIZE     	(NUMBER_OF_THETA * NUMBER_OF_RHO)  // NUMBER_OF_RHO * NUMBER_OF_THETA
#define DISTANCE_BETWEEN_CHIPS  (7)
#endif

uint8_t rcv_img_data[IMG_SIZE] = {0};
float pPart = 0.0, iPart = 0.0, dPart = 0.0;
float Err = 0, prev_Err = 0;
uint32_t init[1];


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
    float       current_pos[1] = {0};
    uint8_t     hough_space[HOUGH_AREA_SIZE] = {0};
    int16_t     peakCoordinates[MAX_PEAK_NUMBER*2] = {0};
    float     	data_peaks_tile_1[MAX_PEAK_NUMBER] = {0};
    float       diff_Err;
    float       control_input[1] = {0};
    uint8_t 	picture_lock = read_lock(PICTURE_LOCK_LOCATION_MEM_01);
    int16_t rho;
    float check[1];
    uint32_t sensing_diff[1];
    
    if (picture_lock == LOCK)
    {
        read_byte (rcv_img_data, PICTURE_LOCATION_MEM_01, IMG_SIZE);
        
        // Map pixel to hough space
        for (int x = 0; x < IMG_WIDTH; x++) { // 88
            for (int y = 0; y < IMG_HEIGHT; y++) { // 142
                if (rcv_img_data[y + IMG_HEIGHT * x]==1) {
                    for (int thetaIdx = 0; thetaIdx < NUMBER_OF_THETA; thetaIdx++) { // Loop from THETA_MIN to THETA_MAX
                        rho =   lroundf(x * cost[thetaIdx] +  y * sint[thetaIdx] + MAX_NEGATIVE_RHO); // + IMG_HEIGHT*sind(THETA_MIN)
                        hough_space[rho + NUMBER_OF_RHO * thetaIdx]++;
                    }
                }
            }
        }
        
        
        
        
        while (!isDone) {
            maxVal = -1;
            jPeak = -1;
            rhoToRemove = -1;
            
            // Find the maximum value in hough space
            for (ex = 0; ex < NUMBER_OF_THETA; ex++) {
                for (k = 0; k < NUMBER_OF_RHO; k++) {
                    d1 = hough_space[k + NUMBER_OF_RHO * ex];
                    
                    if (d1 > maxVal) {
                        rhoToRemove = k;
                        jPeak = ex;
                        maxVal = d1;
                        isDone = 1;
                    }
                }
            }
            // Proceed if the maximum value is bigger than the threshold
            if ((jPeak != -1) && (hough_space[(rhoToRemove + NUMBER_OF_RHO * jPeak)] >= HOUGH_THRESHOLD)) {
                peakIdx++;
                peakCoordinates[peakIdx - 1] = (rhoToRemove - MAX_NEGATIVE_RHO); // + Offset
                peakCoordinates[peakIdx + MAX_PEAK_NUMBER -1] = (jPeak + THETA_MIN); // + Offset
                
                // Remove area of (2*PADDING_SIZE_RHO+1) x (2*PADDING_SIZE_THETA+1) whose center is the peak point
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
                        hough_space[(k + NUMBER_OF_RHO * ex)] = 0;
                    }
                }
                isDone = (peakIdx == MAX_PEAK_NUMBER);
            }
            else {
                isDone = 1;
            }
        }
        
        // Find actual distance
        for (int a = 0; a < MAX_PEAK_NUMBER; a++)
        {
            float theta   = (float)peakCoordinates[a+MAX_PEAK_NUMBER]*PI/180.0;
            float distance = peakCoordinates[a]/cos(theta) - (IMG_HEIGHT/2)*sin(theta)/cos(theta);
            
            if (distance < 0.0)
                distance = 0.0;
            if (distance > (IMG_WIDTH - 1))
                distance = (IMG_WIDTH - 1);
            //Assign the distance to data peak array
            data_peaks_tile_1[a] = distance;
        }
        
        // Calculate center point
        current_pos[0] = (int)(data_peaks_tile_1[0] + data_peaks_tile_1[1]) / 2.0;

        ///
        write_float(current_pos, CURRENT_POS_LOCATION_MEM_01, 1);
        
        
        Err = DESIRED_POS - current_pos[0]; //error
        diff_Err = Err - prev_Err;
        prev_Err = Err;
        
        pPart = K_P * (float) Err;
        if (abs(Err) < (abs(DESIRED_POS * 0.2))) {
            iPart = iPart + K_I * SAMPLING_TIME * Err;
        }
        else {
            iPart = 0.0;
        }
        dPart = K_D * diff_Err * INV_SAMPLING_TIME;
        control_input[0] =  (pPart + iPart + dPart);
        
        ///
        write_float(control_input, FORCE_LOCATION_MEM_01, 1);
        write_lock(UNLOCK, PICTURE_LOCK_LOCATION_MEM_01);
        write_lock(LOCK, FORCE_LOCK_LOCATION_MEM_01);
        

        
        
        
        
        
    }
    
    
}

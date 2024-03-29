#ifndef CONFIG_H
#define CONFIG_H

// Sensing
#define WAITING_TIME        ((uint32_t)200000) // Cycles ~ 5 ms
#define IMG_WIDTH           (88) // Pixels
#define HALF_WIDTH          (44) // Pixels
#define IMG_HEIGHT          (142) // Pixels
#define IMG_SIZE            (12496) // Pixels
#define HALF_IMG            (6248)
#define HOUGH_THRESHOLD     (25)
#define PADDING_SIZE_THETA  (3) // Pixels
#define PADDING_SIZE_RHO    (3) // Pixels
#define MAX_PEAK_NUMBER     (2)
#define DESIRED_POS         (40) // Pixels
#define PIXEL_RATIO         (0.001) // 1 milimeter
#define THETA_neg_5_pos_5
// #define THETA_0_pos_5
// #define THETA_0_pos_30
#define ms_35               ((uint32_t)1400000)
#define ms_36               ((uint32_t)1440000)
#define ms_37               ((uint32_t)1480000)
#define ms_38               ((uint32_t)1520000)
#define ms_39               ((uint32_t)1560000)



// Controller
#define DAMPING_CONST       ((float)1.0)
#define SAMPLING_TIME       ((float)0.020)
#define INV_SAMPLING_TIME   ((float)50.00)
#define K_P                 ((float)40.00) 
#define K_D                 ((float)0.8) 
#define K_I                 ((float)30)
#define PI                  (3.1416)
#endif
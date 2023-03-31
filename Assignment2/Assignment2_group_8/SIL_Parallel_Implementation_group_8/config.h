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
#define DESIRED_POS         (0.04) // Pixels
#define PIXEL_RATIO         (0.001) // 1 milimeter
#define THETA_neg_5_pos_5


// Controller
#define DAMPING_CONST       ((float)1.0)
#define SAMPLING_TIME       ((float)0.02)
#define INV_SAMPLING_TIME   ((float)50.0)
#define K_P                 ((float)60) // previous values
#define K_D                 ((float)4)
#define K_I                 ((float)0)
#define PI                  (3.1416)
#endif

#ifndef FROMSHAREDMEMORY_HOUGH_COMB_H
#define FROMSHAREDMEMORY_HOUGH_COMB_H
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <config.h>

void sensing_task(uint8_t rcv_img_data[IMG_SIZE], int16_t data_peaks_0[1], int16_t data_peaks_1[1], int16_t data_peaks_2[1], int16_t data_peaks_3[1]);


#endif
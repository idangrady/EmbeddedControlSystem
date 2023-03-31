#ifndef MAPPING_H
#define MAPPING_H

#include <memmap.h>
#include <config.h>

#define LOCK                        1
#define UNLOCK                      0

/// Memory locations for Sensing task1

#define PICTURE_LOCATION            (tile0_comm1)
#define PICTURE_LOCK_LOCATION       (PICTURE_LOCATION + IMG_SIZE + 8)
#define DESIRED_POS_LOCATION        (PICTURE_LOCK_LOCATION + 4) // 4-byte aligned
#define CURRENT_POS_LOCATION        (DESIRED_POS_LOCATION + 4) 
#define CONTROLLER_LOCK_LOCATION    (CURRENT_POS_LOCATION + 4)
#define FORCE_LOCATION              (CONTROLLER_LOCK_LOCATION + 4) 
#define FORCE_LOCK_LOCATION         (FORCE_LOCATION + 4)
#define CONTROLLER_TIME_BOTTOM      (FORCE_LOCK_LOCATION + 4) 
#define CONTROLLER_TIME_TOP         (CONTROLLER_TIME_BOTTOM + 4) 
#define SENSING_TIME_BOTTOM         (CONTROLLER_TIME_TOP + 4) 
#define SENSING_TIME_TOP            (SENSING_TIME_BOTTOM + 4) 
#define DATA_PEAK_LOCATION_0        (SENSING_TIME_TOP +16)
#define MERGING_LOCK_LOCATION       (DATA_PEAK_LOCATION_0 + 16)
#define test_location_mem01         (MERGING_LOCK_LOCATION + 16)

#define SENSING0_SENSING1_MSB                       (test_location_mem01 + 4)
#define SENSING0_SENSING1_LSB                       (SENSING0_SENSING1_MSB + 4)
#define SAMPLING_PERIOD_LOCATION_MEM01              (SENSING0_SENSING1_LSB + 4)



/// Memory locations for Sensing task2

#if defined(SEND_FROM_TILE_0_TO_TILE_2)
    #define PICTURE_LOCATION_SENSING_2           (tile0_comm2)
    #define PICTURE_LOCK_LOCATION_SENSING_2      (PICTURE_LOCATION_SENSING_2 + IMG_SIZE + 8)
    #define DATA_PEAK_LOCATION_0_SENSING_2       (PICTURE_LOCK_LOCATION_SENSING_2 +16)
    #define MERGING_LOCK_LOCATION_SENSING_2      (DATA_PEAK_LOCATION_0_SENSING_2 + 4)
    #define test_location_mem02                  (MERGING_LOCK_LOCATION_SENSING_2 + 16)
#elif defined(SEND_FROM_TILE_2_TO_TILE_0)
    #define PICTURE_LOCATION_SENSING_2           (tile2_comm0)
    #define PICTURE_LOCK_LOCATION_SENSING_2      (PICTURE_LOCATION_SENSING_2 + IMG_SIZE + 8)
    #define DATA_PEAK_LOCATION_0_SENSING_2       (PICTURE_LOCK_LOCATION_SENSING_2 +16)
    #define MERGING_LOCK_LOCATION_SENSING_2      (DATA_PEAK_LOCATION_0_SENSING_2 + 4)
    #define test_location_mem02                  (MERGING_LOCK_LOCATION_SENSING_2 + 16)
#endif
#endif
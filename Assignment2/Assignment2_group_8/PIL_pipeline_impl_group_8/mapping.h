#ifndef MAPPING_H
#define MAPPING_H

#include <memmap.h>
#include <config.h>

#define LOCK                                        (1)
#define UNLOCK                                      (0)
    

// MEM01
#define PICTURE_LOCATION_MEM_01                     (tile0_comm1)
#define PICTURE_LOCK_LOCATION_MEM_01                (PICTURE_LOCATION_MEM_01 + IMG_SIZE + 8)
#define FORCE_LOCATION_MEM_01                       (PICTURE_LOCK_LOCATION_MEM_01 + 4) // 4-byte aligned
#define FORCE_LOCK_LOCATION_MEM_01                  (FORCE_LOCATION_MEM_01 + 4)
#define SENSING_TIME_BOTTOM_MEM_01                  (FORCE_LOCK_LOCATION_MEM_01 + 4) // 4-byte aligned
#define SENSING_TIME_TOP_MEM_01                     (SENSING_TIME_BOTTOM_MEM_01 + 4) // 4-byte aligned
#define CURRENT_POS_LOCATION_MEM_01                 (SENSING_TIME_TOP_MEM_01 + 4)
#define TIMER_LOCATION_MSB                          (CURRENT_POS_LOCATION_MEM_01 + 4)
#define TIMER_LOCATION_LSB                          (TIMER_LOCATION_MSB + 4)
#define SAMPLING_PERIOD_LOCATION_MEM01              (TIMER_LOCATION_LSB + 4)

// MEM12
#define SENSING1_SENSING2_MSB                       (tile1_comm2)
#define SENSING1_SENSING2_LSB                       (SENSING1_SENSING2_MSB + 4)
#define SAMPLING_PERIOD_LOCATION_MEM12              (SENSING1_SENSING2_LSB + 4)



// MEM02
#if defined(SEND_FROM_TILE_0_TO_TILE_2)
    #define PICTURE_LOCATION_MEM_02                 (tile0_comm2)
    #define PICTURE_LOCK_LOCATION_MEM_02            (PICTURE_LOCATION_MEM_02 + 8 + IMG_SIZE)
    #define FORCE_LOCATION_MEM_02                   (PICTURE_LOCK_LOCATION_MEM_02 + 4) // 4-byte aligned
    #define FORCE_LOCK_LOCATION_MEM_02              (FORCE_LOCATION_MEM_02 + 4)
    #define SENSING_TIME_BOTTOM_MEM_02              (FORCE_LOCK_LOCATION_MEM_02 + 4) // 4-byte aligned
    #define SENSING_TIME_TOP_MEM_02                 (SENSING_TIME_BOTTOM_MEM_02 + 4) // 4-byte aligned
    #define CURRENT_POS_LOCATION_MEM_02             (SENSING_TIME_TOP_MEM_02 + 4)
#elif defined(SEND_FROM_TILE_2_TO_TILE_0)
    #define PICTURE_LOCATION_MEM_02                 (tile2_comm0)
    #define PICTURE_LOCK_LOCATION_MEM_02            (PICTURE_LOCATION_MEM_02 + 8 + IMG_SIZE)
    #define FORCE_LOCATION_MEM_02                   (PICTURE_LOCK_LOCATION_MEM_02 + 4) // 4-byte aligned
    #define FORCE_LOCK_LOCATION_MEM_02              (FORCE_LOCATION_MEM_02 + 4)
    #define SENSING_TIME_BOTTOM_MEM_02              (FORCE_LOCK_LOCATION_MEM_02 + 4) // 4-byte aligned
    #define SENSING_TIME_TOP_MEM_02                 (SENSING_TIME_BOTTOM_MEM_02 + 4) // 4-byte aligned
    #define CURRENT_POS_LOCATION_MEM_02             (SENSING_TIME_TOP_MEM_02 + 4)
    #define TIMER_LOCATION_MSB_MEM_02               (CURRENT_POS_LOCATION_MEM_02 + 4)
    #define TIMER_LOCATION_LSB_MEM_02               (TIMER_LOCATION_MSB_MEM_02 + 4)
#endif





// STATE
#define STATE_INIT_TILE_1                           (0)
#define STATE_INIT_TILE_2                           (1)
#define STATE_TILE_1                                (2)
#define STATE_TILE_2                                (3)
#define STATE_RECEIVE_FROM_TILE_1                   (4)
#define STATE_RECEIVE_FROM_TILE_2                   (5)

#endif
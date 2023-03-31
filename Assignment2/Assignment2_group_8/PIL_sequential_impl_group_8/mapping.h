#ifndef MAPPING_H
#define MAPPING_H

#include <memmap.h>
#include <config.h>

#define LOCK                        1
#define UNLOCK                      0


#define PICTURE_LOCATION            (tile0_comm1)
#define PICTURE_LOCK_LOCATION       (PICTURE_LOCATION + IMG_SIZE + 8)
#define DESIRED_POS_LOCATION        (PICTURE_LOCK_LOCATION + 4) // 4-byte aligned
#define CURRENT_POS_LOCATION        (DESIRED_POS_LOCATION + 4) // 4-byte aligned
#define CONTROLLER_LOCK_LOCATION    (CURRENT_POS_LOCATION + 4)
#define FORCE_LOCATION              (CONTROLLER_LOCK_LOCATION + 4) // 4-byte aligned
#define FORCE_LOCK_LOCATION         (FORCE_LOCATION + 4) 
#define CONTROLLER_TIME_BOTTOM      (FORCE_LOCK_LOCATION + 4) // 4-byte aligned
#define CONTROLLER_TIME_TOP         (CONTROLLER_TIME_BOTTOM + 4) // 4-byte aligned
#define SENSING_TIME_BOTTOM         (CONTROLLER_TIME_TOP + 4) // 4-byte aligned
#define SENSING_TIME_TOP            (SENSING_TIME_BOTTOM + 4) // 4-byte aligned





#define DATA_PEAK_LOCATION_0                    (SENSING_TIME_TOP +16)
#define DATA_PEAK_LOCATION_1                    (DATA_PEAK_LOCATION_0 + 4)
#define DATA_PEAK_LOCATION_2                    (DATA_PEAK_LOCATION_1 + 4)
#define DATA_PEAK_LOCATION_3                    (DATA_PEAK_LOCATION_2 + 4)
#define MERGING_LOCK_LOCATION                   (DATA_PEAK_LOCATION_3 + 4)

#define test_location                     (MERGING_LOCK_LOCATION + 4)

#endif
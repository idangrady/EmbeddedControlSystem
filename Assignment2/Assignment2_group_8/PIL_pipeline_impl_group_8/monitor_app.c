#include <monitor_app.h>
#include <memory_access.h>
#include <config.h>
#define SEND_FROM_TILE_0_TO_TILE_2
#include <mapping.h>
#include <stdint.h>

// rcv_img_data : input image from coppeliasim (input u1)
// force        : output from controller (control action for acutation) (output y1)
// force_lock   : force lock required for actuation (output y2)
// counter      : input counter to the monitoring app block (input u2)
// current_pos  : printing current position from monitoring app (output y3)
// sensing_time : printing sample period (output y4)

void monitor(uint8_t rcv_img_data[IMG_SIZE], float force[1], uint8_t force_lock[1], uint32_t counter[1], float current_pos[2])
{
    static uint32_t temp_counter    =   1;
    static uint8_t state            =   STATE_INIT_TILE_1;
    static int 	counter_frame[1]       = {0};
    force_lock[0]                   =   UNLOCK;
    uint8_t forceLock_tile1;
    uint8_t forceLock_tile2;
    
    
    switch (state)
    {
        case STATE_INIT_TILE_1:
            
        write_byte(rcv_img_data, PICTURE_LOCATION_MEM_01, IMG_SIZE);
        write_lock(LOCK, PICTURE_LOCK_LOCATION_MEM_01);
        
        state = STATE_INIT_TILE_2;
        break;
        
        case STATE_INIT_TILE_2:
            
        write_byte(rcv_img_data, PICTURE_LOCATION_MEM_02, IMG_SIZE);
        write_lock(LOCK, PICTURE_LOCK_LOCATION_MEM_02);
        
        state = STATE_TILE_1;
        break;
        
     	case STATE_TILE_1:
            
        write_byte(rcv_img_data, PICTURE_LOCATION_MEM_01, IMG_SIZE);
        write_lock(LOCK, PICTURE_LOCK_LOCATION_MEM_01);
        forceLock_tile1 = read_lock(FORCE_LOCK_LOCATION_MEM_01);
        if (forceLock_tile1 == LOCK)
        {
            read_float(force, FORCE_LOCATION_MEM_01, 1);
            write_lock(UNLOCK, FORCE_LOCK_LOCATION_MEM_01);

            force_lock[0] = LOCK;

        }
        state = STATE_TILE_2;
        break;
    
        case STATE_TILE_2:
        
        write_byte(rcv_img_data, PICTURE_LOCATION_MEM_02, IMG_SIZE);
        write_lock(LOCK, PICTURE_LOCK_LOCATION_MEM_02);
        
        forceLock_tile2 = read_lock(FORCE_LOCK_LOCATION_MEM_02);
        if (forceLock_tile2 == LOCK)
        {
            read_float(force, FORCE_LOCATION_MEM_02, 1);
            write_lock(UNLOCK, FORCE_LOCK_LOCATION_MEM_02);

            force_lock[0] = LOCK;

        }
        state = STATE_TILE_1;
        break;
    }
    
    read_float(current_pos, CURRENT_POS_LOCATION_MEM_01, 1);
    read_float(current_pos+1, CURRENT_POS_LOCATION_MEM_02, 1);
    
}
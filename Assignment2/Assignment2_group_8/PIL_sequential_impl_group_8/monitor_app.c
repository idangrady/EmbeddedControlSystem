#include <monitor_app.h>
#include <memory_access.h>
#include <config.h>
#include <mapping.h>

void monitor(uint8_t rcv_img_data[IMG_SIZE], float force[1], uint8_t force_lock[1], uint32_t counter[1], float current_pos[1])
{
    
    static float temp_force[1] = {0};
    
    
    uint8_t forceLock = read_lock(FORCE_LOCK_LOCATION);
    
    
    write_byte(rcv_img_data, PICTURE_LOCATION, IMG_SIZE);
    // Write lock
    write_lock(LOCK, PICTURE_LOCK_LOCATION);
    
    
    
    
    if (forceLock == LOCK)
    {
        read_float(temp_force, FORCE_LOCATION, 1);
        write_lock(UNLOCK, FORCE_LOCK_LOCATION);
        
    }
    
    
    
    force_lock[0] = forceLock;
    force[0] = temp_force[0];
    
    read_float(current_pos, CURRENT_POS_LOCATION, 1);
    
}
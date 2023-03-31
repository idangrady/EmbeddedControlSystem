#ifndef MONITOR_APP_H
#define MONITOR_APP_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <config.h>

void monitor(uint8_t rcv_img_data[IMG_SIZE], float force[1], uint8_t force_lock[1], uint32_t counter[1], float current_pos[2]);

#endif
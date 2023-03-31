#ifndef MEMORY_ACCESS_H
#define MEMORY_ACCESS_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void read_int(int32_t OutPut[], uint32_t start_addr, uint32_t numberOfBytes);
void read_float(float OutPut[], uint32_t start_addr, uint32_t numberOfBytes);
void read_byte(uint8_t OutPut[], uint32_t start_addr, uint32_t numberOfBytes);
uint8_t read_lock(uint32_t start_addr);
void read_uint32 (uint32_t OutPut[], uint32_t start_addr, uint32_t numberOfTokens);

void write_int(int32_t InPut[], uint32_t start_addr, uint32_t numberOfTokens);
void write_float(float InPut[], uint32_t start_addr, uint32_t numberOfTokens);
void write_byte(uint8_t InPut[], uint32_t start_addr, uint32_t numberOfTokens);
void write_lock(uint8_t InPut, uint32_t start_addr);
void write_uint32 (uint32_t InPut[], uint32_t start_addr, uint32_t numberOfTokens);


#endif
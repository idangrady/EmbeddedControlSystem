#include <memory_access.h>

void read_int(int32_t OutPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    int32_t * share_addr = (int32_t *) start_addr;
    uint32_t i = 0;
            
    for ( i = 0; i < numberOfTokens; i++ )
    {
        OutPut[i] = *(share_addr + i);
    }
}

void read_uint32 (uint32_t OutPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    uint32_t * share_addr = (uint32_t *) start_addr;
    uint32_t i = 0;
            
    for ( i = 0; i < numberOfTokens; i++ )
    {
        OutPut[i] = *(share_addr + i);
    }
}

void read_float(float OutPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    float * share_addr = (float *) start_addr;
    uint32_t i = 0;
    
    for ( i = 0; i < numberOfTokens; i++ )
    {
        OutPut[i] = *(share_addr + i);
    }
}


void read_byte(uint8_t OutPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    uint8_t * share_addr = (uint8_t *) start_addr;
    uint32_t i = 0;
    
    for ( i = 0; i < numberOfTokens; i++ )
    {
        OutPut[i] = *(share_addr + i);
    }
}

uint8_t read_lock(uint32_t start_addr)
{
    uint8_t * share_addr = (uint8_t *) start_addr;
    return (uint8_t)(*share_addr);
}

void write_float(float InPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    float * share_addr = (float *) start_addr;
    uint32_t i = 0; 
    
    for (i = 0; i < numberOfTokens; i++ )
    {
       *(share_addr + i) = InPut[i];
    }
}

void write_int(int32_t InPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    int32_t * share_addr = (int32_t *) start_addr;
    uint32_t i = 0; 
    
    for (i = 0; i < numberOfTokens; i++ )
    {
       *(share_addr + i) = InPut[i];
    }
}

void write_byte(uint8_t InPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    uint8_t * share_addr = (uint8_t *) start_addr;
    uint32_t i = 0; 
    
    for (i = 0; i < numberOfTokens; i++ )
    {
       *(share_addr + i) = InPut[i];
    }
}

void write_lock(uint8_t InPut, uint32_t start_addr)
{
    uint8_t * share_addr = (uint8_t *) start_addr;
    
    while(1)
    {
        *(share_addr) = InPut;
        if (*share_addr == InPut)
        {
            break;
        }          
    }
}

void write_uint32 (uint32_t InPut[], uint32_t start_addr, uint32_t numberOfTokens)
{
    uint32_t * share_addr = (uint32_t *) start_addr;
    uint32_t i = 0; 
    
    for (i = 0; i < numberOfTokens; i++ )
    {
       *(share_addr + i) = InPut[i];
    }
}
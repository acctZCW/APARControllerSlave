//
// Created by IamZh on 2023/5/8.
//

#include "bsp_utils.h"

i16 bytes_to_i16(u8* bytes){
    i16 value;
    value = (i16) ((bytes[0] & 0xFF) | ((bytes[1] &0xFF) << 8));
    return value;
}

u16 bytes_to_u16(const u8* bytes){
    u16 value;
    value = (u16)((bytes[0] & 0xFF) | ((bytes[1] & 0xFF) << 8));
    return value;
}

void i16_to_bytes(i16 num, u8* bytes){
    bytes[0] = num & 0xFF;
    bytes[1] = (num >> 8) & 0xFF;
}

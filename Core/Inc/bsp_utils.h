//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_UTILS_H
#define APARCONTROLLERSLAVE_BSP_UTILS_H

#include "bsp_types.h"

/**
 * byte array to int16, using little endian.
 * @param bytes the pointer of byte array
 * @return 16bits interal.
 */
i16 bytes_to_i16(u8* bytes);
/**
 * int16 to byte array, using little endian.
 * @param num the signed short value.
 * @param bytes receive the bytes.
 */
void i16_to_bytes(i16 num, u8* bytes);

/**
 * byte array to u16, using little endian.
 * @param bytes the pointer of byte array
 * @return unsigned 16bits interal.
*/
u16 bytes_to_u16(const u8* bytes);

#endif //APARCONTROLLERSLAVE_BSP_UTILS_H

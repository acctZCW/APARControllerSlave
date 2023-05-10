//
// Created by IamZh on 2023/5/9.
//

#ifndef APARCONTROLLERSLAVE_BSP_EXECUTIONS_H
#define APARCONTROLLERSLAVE_BSP_EXECUTIONS_H

#include "bsp_types.h"
#include "bsp_pe44820.h"

/**
 * @brief Frame Type Enum
 */
typedef enum{
    INPUT_PE44820 = 0,
    INPUT_PE43703
}FrameType;

/**
 * parse the command and input data into pe44820
 * @param command command bytes
 * @param len the length of command
 * @return result of execution, 1 for success, other for exceptions
 */
int inputPE44820(const u8* command, u16 len);
/**
 * parse the command and input data into pe43703
 * @param command command bytes
 * @param len the length of command
 * @return result of execution, 1 for success, other for exceptions
 */
int inputPE43703(const u8* command, u16 len);

#endif //APARCONTROLLERSLAVE_BSP_EXECUTIONS_H

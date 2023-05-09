//
// Created by IamZh on 2023/5/9.
//

#ifndef APARCONTROLLERSLAVE_BSP_EXECUTIONS_H
#define APARCONTROLLERSLAVE_BSP_EXECUTIONS_H

#include "bsp_types.h"
#include "bsp_pe44820.h"

typedef enum{
    INPUT_PE44820 = 0,
    INPUT_PE43703
}FrameType;

int inputPE44820(const u8* command, u16 len);

int inputPE43703(const u8* command, u16 len);

#endif //APARCONTROLLERSLAVE_BSP_EXECUTIONS_H

//
// Created by IamZh on 2023/5/9.
//

#ifndef APARCONTROLLERSLAVE_BSP_EXECUTIONS_H
#define APARCONTROLLERSLAVE_BSP_EXECUTIONS_H

#include "bsp_types.h"
#include "bsp_pe44820.h"

int inputPE44820(const u8* command, uint16_t len, PE44820TypeDef* pe44820s, uint16_t device_num);

int inputPE43703(const u8* command);

#endif //APARCONTROLLERSLAVE_BSP_EXECUTIONS_H

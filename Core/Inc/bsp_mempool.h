//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_MEMPOOL_H
#define APARCONTROLLERSLAVE_BSP_MEMPOOL_H

#include <stdint.h>
#include "bsp_fsm.h"
#include "bsp_protocol.h"

#define BUFFER_SIZE 1024

extern uint8_t g_recvBuffer[BUFFER_SIZE];
extern FsmTypeDef g_fsm;
extern FrameTypeDef g_frame;

#endif //APARCONTROLLERSLAVE_BSP_MEMPOOL_H

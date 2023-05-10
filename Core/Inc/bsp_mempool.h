//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_MEMPOOL_H
#define APARCONTROLLERSLAVE_BSP_MEMPOOL_H

#include <stdint.h>
#include "bsp_fsm.h"
#include "bsp_protocol.h"

#define BUFFER_SIZE 1024 /*!< the size fo received buffer */

extern uint8_t g_recvBuffer[BUFFER_SIZE]; /*!< global received buffer, for serial rx */

extern FsmTypeDef g_fsm; /*!< global fsm, for global state management */
extern FrameTypeDef g_frame; /*!< global protocol frame, for storing the frame parsed by protocol module */

#endif //APARCONTROLLERSLAVE_BSP_MEMPOOL_H

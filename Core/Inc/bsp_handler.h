//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_HANDLER_H
#define APARCONTROLLERSLAVE_BSP_HANDLER_H

#include "bsp_types.h"

/**
 * definitions
 */
typedef enum{
    STATE_ERROR= 0,
    STATE_IDLE,
    STATE_PARSE,
    STATE_EXEC,
    STATE_PARSE_ERROR
} State;

typedef enum{
    EVENT_PASS = 0,
    EVENT_FAILED,
    EVENT_PROCESS
} Event;

typedef int (*ExecFn)(const u8* content, u16 len);

u8 recvHandler();

u8 parseHandler();

u8 parseErrorHandler();

u8 execHandler();

u8 execErrorHandler();

u8 registerExecFn(ExecFn fn, u8 type);


#endif //APARCONTROLLERSLAVE_BSP_HANDLER_H

//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_HANDLER_H
#define APARCONTROLLERSLAVE_BSP_HANDLER_H

#include "bsp_types.h"

/**
 * definitions
 */

/**
 * @brief state id enum
 */
typedef enum{
    STATE_ERROR= 0,
    STATE_IDLE,
    STATE_PARSE,
    STATE_EXEC,
    STATE_PARSE_ERROR,
    STATE_EXEC_ERROR
} State;

/**
 * @brief event id enum
 */
typedef enum{
    EVENT_PASS = 0,
    EVENT_FAILED,
    EVENT_PROCESS
} Event;

/**
 * @brief Execution Functions Type Definition
 */
typedef int (*ExecFn)(const u8* content, u16 len);
/**
 * @brief Receive Event Handler
 * @details Used for State: IDLE, Event:PROCESS
 * @return result of exec state ,1 for success
 */
u8 recvHandler();
/**
 * @brief Parse Event Handler
 * @details Used for State: PARSE, Event:PROCESS
 * @return result of exec state ,1 for success
 */
u8 parseHandler();
/**
 * @brief Parse Error Event Handler
 * @details Used for State: PARSE_ERROR, Event:PROCESS
 * @return result of exec state ,1 for success
 */
u8 parseErrorHandler();
/**
 * @brief Execution Event Handler
 * @details Used for State: EXEC, Event:PROCESS
 * @return result of exec state ,1 for success
 */
u8 execHandler();
/**
 * @brief Execution Error Event Handler
 * @details Used for State: EXEC_ERROR, Event:PROCESS
 * @return result of exec state ,1 for success
 */
u8 execErrorHandler();
/**
 * register exec functions into execFns table
 * @param fn the exec fn need to be registered
 * @param type the type of frame
 * @return
 */
u8 registerExecFn(ExecFn fn, u8 type);


#endif //APARCONTROLLERSLAVE_BSP_HANDLER_H

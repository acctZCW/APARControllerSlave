//
// Created by IamZh on 2023/5/8.
//

#ifndef APARCONTROLLERSLAVE_BSP_FSM_H
#define APARCONTROLLERSLAVE_BSP_FSM_H

#include "bsp_types.h"

#define STATE_NUM 10
#define EVENT_NUM 10

/**
 * type definitions
*/
typedef u8 (*EventFn)();

/**
 * @brief type definition of fsm.
 * @details define the fsm type, include state and eventFns table.
 */
typedef struct{
    u8 state;
    EventFn eventFns[STATE_NUM][EVENT_NUM];
} FsmTypeDef;


/**
 * Funcitons
 * ---------------------------------------------------
*/


/**
 * initialized the fsm.
 * @param fsm pointer of the fsm.
 * @return
 */
int fsmInit(FsmTypeDef* fsm);

/**
 * handle the event invoked by the program.
 * @param fsm finite state machine
 * @param event event id
*/
int fsmEventHandle(FsmTypeDef* fsm, u8 event);


/**
 * register the event into fsm.
 * @param fsm the finite state machine.
 * @param event the event need to be registered.
 * @param state the state id
 * @param event the event id
*/
int fsmEventRegister(FsmTypeDef* fsm, EventFn eventFn, u8 state, u8 event);

#endif //APARCONTROLLERSLAVE_BSP_FSM_H

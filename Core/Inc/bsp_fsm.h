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

typedef struct{
    u8 state;
    EventFn eventFns[STATE_NUM][EVENT_NUM];
} FsmTypeDef;


/**
 * Funcitons
 * ---------------------------------------------------
*/

int fsmInit(FsmTypeDef* fsm);

/**
 * handle the event invoked by the program.
 * @param fsm finite state machine
 * @param event event id
*/
int fsmEventHandle(FsmTypeDef* fsm, u8 event);

/**
 * trans the state of fsm.
 * @param fsm finite state machine
 * @param next_state next state
*/
void fsmStateTrans(FsmTypeDef* fsm, u8 next_state);


/**
 * register the event into fsm.
 * @param fsm the finite state machine.
 * @param event the event need to be registered.
 * @param state the state id
 * @param event the event id
*/
int fsmEventRegister(FsmTypeDef* fsm, EventFn eventFn, u8 state, u8 event);

#endif //APARCONTROLLERSLAVE_BSP_FSM_H

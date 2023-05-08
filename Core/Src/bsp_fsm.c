//
// Created by IamZh on 2023/5/8.
//

#include <memory.h>
#include "bsp_fsm.h"

int fsmInit(FsmTypeDef* fsm){
    memset(fsm->eventFns,0,STATE_NUM*EVENT_NUM*sizeof(EventFn));
    fsm->state = 0;
    return 1;
}

int fsmEventHandle(FsmTypeDef* fsm, u8 event){
    u8 state = fsm->state;
    u8 next_state = state;
    // Out of bound
    if(state >= STATE_NUM || event >= STATE_NUM) return -1;
    u8 (*eventFn)() = fsm->eventFns[state][event];
    if(eventFn != NULL){
        // if eventFn is not null, execute it and get the next state.
        next_state = eventFn();
    }
    // trans to next state.
    fsmStateTrans(fsm,next_state);
}

void fsmStateTrans(FsmTypeDef* fsm, u8 next_state){
    fsm->state = next_state;
}

int fsmEventRegister(FsmTypeDef* fsm, EventFn eventFn, u8 state, u8 event){
    if(state >= STATE_NUM || event >= EVENT_NUM) return -1;
    fsm->eventFns[state][event] = eventFn;
}
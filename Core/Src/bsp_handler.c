//
// Created by IamZh on 2023/5/8.
//

#include <memory.h>
#include "dma.h"
#include "usart.h"

#include "bsp_handler.h"
#include "bsp_protocol.h"
#include "bsp_mempool.h"


ExecFn execFns[128];

u8 registerExecFn(ExecFn fn, u8 type){
    if(type > 127 || fn == NULL) return 0;
    execFns[type] = fn;
    return 1;
}

u8 recvHandler(){
    return STATE_PARSE;
}

u8 parseHandler(){
    if(parseFrame(g_recvBuffer,&g_frame)){
        memset(g_recvBuffer,0,BUFFER_SIZE);
        return STATE_EXEC;
    } else{
        memset(g_recvBuffer,0,BUFFER_SIZE);
        return STATE_PARSE_ERROR;
    }
}

u8 execHandler(){
    HAL_UART_Transmit(&huart1,g_frame.content,g_frame.len,100);
    // How to dispatch commands to different functions?
    // do this
    ExecFn fn = execFns[g_frame.type];
    fn(g_frame.content,g_frame.len);
    return STATE_IDLE;
}

u8 parseErrorHandler(){
    // request for resend.
    HAL_UART_Transmit(&huart1,(u8*)1,1,100);
    return STATE_IDLE;
}

u8 execErrorHandler(){
    return STATE_IDLE;
}

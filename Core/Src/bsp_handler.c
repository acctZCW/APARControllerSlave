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
    int status_code = parseFrame(g_recvBuffer,&g_frame);
    memset(g_recvBuffer,0,BUFFER_SIZE);
    if(status_code == 1){

        HAL_UART_Receive_DMA(&huart1,g_recvBuffer,BUFFER_SIZE);
        HAL_UART_Transmit(&huart1,(u8*)1,1,100);
        return STATE_EXEC;
    } else{
        return STATE_PARSE_ERROR;
    }
}

u8 execHandler(){
    // exec functions dispatcher
    ExecFn fn = execFns[g_frame.type];
    int status_code = fn(g_frame.content, g_frame.len);
    if(status_code == 1) {
        HAL_UART_Transmit(&huart1,(u8*)STATUS_EXECOK,1,100);
        return STATE_IDLE;
    }
    HAL_UART_Transmit(&huart1,(u8*)status_code,1,100);
    return STATE_EXEC_ERROR;
}

u8 parseErrorHandler(){
    // request for resend.
    // code: 128
    HAL_UART_Receive_DMA(&huart1,g_recvBuffer,BUFFER_SIZE);
    HAL_UART_Transmit(&huart1,(u8*)STATUS_PARSEERROR,1,100);
    return STATE_IDLE;
}

u8 execErrorHandler(){
    // exec error occurred.
    // code: 129
    HAL_UART_Transmit(&huart1,(u8*)129,1,100);
    return STATE_IDLE;
}

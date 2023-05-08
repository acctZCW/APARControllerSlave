//
// Created by IamZh on 2023/5/8.
//

#include <memory.h>
#include "bsp_handler.h"
#include "bsp_protocol.h"
#include "bsp_mempool.h"
#include "dma.h"
#include "usart.h"

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

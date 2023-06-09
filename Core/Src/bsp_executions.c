//
// Created by IamZh on 2023/5/9.
//

#include <stdio.h>
#include "bsp_executions.h"
#include "usart.h"

int inputPE44820(const u8* command, u16 len){
    // 1 byte for addr, 1 byte for data
    if(len/2 > PE44820_NUM || len%2 != 0) return 0;
    u8 addr;
    u8 data;
    for(int i = 0; i < len/2; i++){
        addr = command[2*i];
        data = command[2*i+1];
        if(addr >= PE44820_NUM) return 0; /* unit addr overflow */
        u8 send_str[20];
        sprintf(send_str,"addr: %d, data: %d\n",addr, data);
        HAL_UART_Transmit(&huart1,send_str,20,100);
//        writePE44820(hal_pe44820s[addr],data);
    }
    return 1;
}

int inputPE43703(const u8* command, u16 len){
    return 1;
}

int inputPE44820WithSpi(const u8* command, u16 len){
    // code 131: addr out of bound
    if(len/2 > PE43703_NUM || len%2 != 0) return 131;
    u8 addr;
    u8 data;
    int status_code = 0;
    for(int i = 0; i < len/2; i++){
        addr = command[2*i];
        data = command[2*i+1];
        /* for test. */
//        u8 send_str[20];
//        sprintf(send_str,"addr: %d, data: %d\n",addr, data);
//        HAL_UART_Transmit(&huart1,send_str,20,100);
        /* test end. */
        if(addr >= PE44820_NUM) return 131;
        // change Multi-LE to SPI
        status_code = writePE44820WithSpi(hal_pe44820spi,data,addr);
    }
    return status_code;
}

int inputPE43703WithSpi(const u8* command, u16 len){
    // code 131: addr out of bound
    if(len/2 > PE43703_NUM || len%2 != 0) return 131;
    u8 addr;
    u8 data;
    int status_code = 0;
    for(int i = 0; i < len/2; i++){
        addr = command[2*i];
        data = command[2*i+1];
        /* for test. */
//        u8 send_str[20];
//        sprintf(send_str,"addr: %d, data: %d\n",addr, data);
//        HAL_UART_Transmit(&huart1,send_str,20,100);
        /* test end. */
        if(addr >= PE44820_NUM) return 131;
        // code 130: param out of bound
        if((data & 0x80) != 0) return 130;
        status_code = writePE43703WithSpi(hal_pe43703s[addr],data,addr);
    }
    return 1;
}
//
// Created by IamZh on 2023/5/9.
//

#include "bsp_executions.h"

int inputPE44820(const u8* command, uint16_t len, PE44820TypeDef* pe44820s, uint16_t device_num){
    // 1 byte for addr, 1 byte for data
    if(len/2 > device_num || len%2 != 0) return 0;
    u8 addr;
    u8 data;
    for(int i = 0; i < len/2; i++){
        addr = command[2*i];
        data = command[2*i+1];
        if(addr >= device_num) return 0; /* unit addr overflow */
        writePE44820(pe44820s[addr],data);
    }
    return 1;
}

int inputPE43703(const u8* command){
    return 1;
}
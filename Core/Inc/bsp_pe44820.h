//
// Created by IamZh on 2023/5/9.
//

#ifndef APARCONTROLLERSLAVE_BSP_PE44820_H
#define APARCONTROLLERSLAVE_BSP_PE44820_H

#include "main.h"

#define PE44820_NUM 8


typedef struct{
    GPIO_TypeDef * siPort;
    uint16_t siPin;
    GPIO_TypeDef * clkPort;
    uint16_t clkPin;
    GPIO_TypeDef * lePort;
    uint16_t lePin;
} PE44820TypeDef;

extern PE44820TypeDef hal_pe44820s[PE44820_NUM];

int writePE44820(PE44820TypeDef unit, uint8_t data);

int writePE44820WithSpi(PE44820TypeDef unit, uint8_t data, uint8_t addr);

#endif //APARCONTROLLERSLAVE_BSP_PE44820_H

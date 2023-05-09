//
// Created by IamZh on 2023/5/9.
//

#ifndef APARCONTROLLERSLAVE_BSP_PE43703_H
#define APARCONTROLLERSLAVE_BSP_PE43703_H

#include "main.h"

#define PE43703_NUM 8

typedef struct{
    GPIO_TypeDef * siPort;
    uint16_t siPin;
    GPIO_TypeDef * clkPort;
    uint16_t clkPin;
    GPIO_TypeDef * lePort;
    uint16_t lePin;
} PE43703TypeDef;

extern PE43703TypeDef hal_pe44820s[PE43703_NUM];

int writePE43703(PE43703TypeDef unit, uint8_t data);

#endif //APARCONTROLLERSLAVE_BSP_PE43703_H

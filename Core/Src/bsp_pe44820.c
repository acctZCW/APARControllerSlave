//
// Created by IamZh on 2023/5/9.
//

#include "bsp_pe44820.h"


PE44820TypeDef hal_pe44820s[PE44820_NUM] = {
        { // unit 1
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOB,GPIO_PIN_12
        },
        { // unit 2
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOB,GPIO_PIN_13
        },
        { // unit 3
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOE,GPIO_PIN_14
        },
        { // unit 4
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOE,GPIO_PIN_15
        },
        { // unit 5
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOE,GPIO_PIN_12
        },
        { // unit 6
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOE,GPIO_PIN_13
        },
        { // unit 7
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOE,GPIO_PIN_10
        },
        { // unit 8
                GPIOB,GPIO_PIN_14,
                GPIOB,GPIO_PIN_15,
                GPIOE,GPIO_PIN_11
        }
};

int writePE44820(PE44820TypeDef unit, uint8_t data){
    data = data&0xFF;

    HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_RESET);

    uint8_t w_data;
    // write data into unit.
    for(int i = 0; i < 8; i++){
        w_data = (data >> i) & 1;
        if(w_data == 1)
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_SET);
        HAL_Delay_Us(5);
//        HAL_Delay(5);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    }

    // write opt
    HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_SET);
    HAL_Delay_Us(5);
    HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);

    // write addr
    for(int i = 0; i< 3; i++){
        HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_SET);
        HAL_Delay_Us(5);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    }

    // turn off
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_SET);
    HAL_Delay_Us(10);
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_RESET);

    return 1;
}

int writePE44820WithSpi(PE44820TypeDef unit, uint8_t data, uint8_t addr){
    data = data & 0xFF;

    HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_RESET);
    uint8_t w_data;
    // write data into unit.
    for(int i = 0; i < 8; i++){
        w_data = (data >> i) & 1;
        if(w_data == 1)
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_RESET);
        HAL_Delay_Us(5);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_SET);
        HAL_Delay_Us(5);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    }

    // write addr
    for(int i = 0; i < 3; i++){
        w_data = (addr >> i) & 1;
        if(w_data == 1)
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_RESET);
        HAL_Delay_Us(5);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_SET);
        HAL_Delay_Us(5);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    }


    // latch enable
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_SET);
    HAL_Delay_Us(10);
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_RESET);

    return 1;
}
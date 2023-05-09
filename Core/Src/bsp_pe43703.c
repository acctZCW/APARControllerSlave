//
// Created by IamZh on 2023/5/9.
//

#include "bsp_pe43703.h"

int writePE43703(PE43703TypeDef unit, uint8_t data){
    data = data&0x7F;

    HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(unit.lePort,unit.lePin,GPIO_PIN_RESET);

    uint8_t w_data;
    // write data into unit.
    for(int i = 0; i < 7; i++){
        w_data = (data >> i) & 1;
        if(w_data == 1)
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(unit.siPort,unit.siPin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(unit.clkPort,unit.clkPin,GPIO_PIN_SET);
        HAL_Delay_Us(5);
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
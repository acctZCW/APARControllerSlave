# 有源相控阵控制器：从机

基于STM32 HAL库开发，尚未完成。本项目主要特点：

- 使用串口DMA+空闲中断，提高传输效率
- 使用自定义帧格式的协议传输，并添加CRC8校验码
- 利用有限状态机进行状态设计，增强鲁棒性

20230508更新：

添加FSM相关代码
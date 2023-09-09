#include <stdio.h>
#include <string.h> 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"  



#define BAUD_RATE               9600
#define DYNAMIXEL_TX_PIN        17
#define DYNAMIXEL_RX_PIN        16    
#define DYNAMIXEL_ID             1


void app_main(){ 
     const uart_port_t DYNAMIXEL_UART_NUM = UART_NUM_2;
uart_config_t dynamixel_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        
    };
    
    uart_param_config(DYNAMIXEL_UART_NUM, &dynamixel_config);
    uart_set_pin(DYNAMIXEL_UART_NUM, 17, 16, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(DYNAMIXEL_UART_NUM, 1024, 0, 0, NULL, 0);

     

    uint8_t send_command( 0XFF  0XFF 1 0X05 0X03 0X08  0X1E  00);  
    uart_write_bytes(DYNAMIXEL_TX_PIN, send_command ); 
    uint8_t recieve_commmand( 0XFF  0XFF 1  05  02 00); 
    uart_read_bytes(DYNAMIXEL_RX_PIN,recieve_commmand); 
      
}

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

static char event_str[128];

// protótipo da função para preparar a mensagem do evento
void gpio_event_msg(char *buf, uint32_t events);

void gpio_callback(uint gpio, uint32_t events) {
    //Prepara a Mensagem para ser exibida na tela
    gpio_event_msg(event_str, events);
    printf("GPIO %d %s\n", gpio, event_str);
}



int main() {
    stdio_init_all();
    sleep_ms(5000);
    printf("Hello GPIO IRQ\n");
    for (int i = 0; i < 4; i++){
        gpio_init(i);
        gpio_set_dir(i, GPIO_IN);
        gpio_set_pulls (i,true,false); 
        gpio_set_irq_enabled_with_callback(i, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, &gpio_callback);
    }
    
    // cria uma constante com o pino padrão do led
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    
   /*
    * Inicia o Pino de GPIO e o configura como saída
    */
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    // Loop infinito para o funcionamento do pisca pisca
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
}


static const char *gpio_irq_str[] = {
    "NIVEL BAIXO",   
    "NIVEL ALTO",  
    "BORDA DE DESCIDA",   
    "BORDA DE SUBIDA"   
};

void gpio_event_msg(char *buf, uint32_t events) {
    for (uint i = 0; i < 4; i++) {
        uint mask = (1 << i);
        if (events & mask) {
          
            const char *event_str = gpio_irq_str[i];
            while (*event_str != '\0') {
                *buf++ = *event_str++;
            }
            events &= ~mask;

            if (events) {
                *buf++ = ',';
                *buf++ = ' ';
            }
        }
    }
    *buf++ = '\0';
}
#include <stdio.h>                    // Biblioteca padrão para entrada e saída 
#include "pico/stdlib.h"               // Biblioteca padrão do Raspberry Pi Pico, permitindo controle de GPIO e temporização.
#include "hardware/pwm.h"              // Biblioteca para controle de PWM, necessário para controlar o servo motor.

#define MOTOR_PIN 22                   // Define o pino GPIO 22 como o pino de controle do servo motor.
#define FREQUENCIA_PWM 50              // Define a frequência do PWM como 50 Hz, que é a frequência padrão para controle de servos.

void ajustar_posicao_servo(uint canal_pwm, uint32_t largura_pulso_us) {
    uint32_t divisor_clock = 64;      // Define o divisor de clock como 64. Isso vai afetar a frequência do PWM.
    
    // Calcula o valor de 'valor_contador_pwm'
    // Esse valor é calculado com base no clock do Raspberry Pi Pico (125 MHz) e no divisor de clock.
    uint32_t valor_contador_pwm = (125000000 / divisor_clock) / FREQUENCIA_PWM - 1;

    pwm_set_wrap(canal_pwm, valor_contador_pwm);  // Define o valor máximo para o contador do PWM.
    pwm_set_clkdiv(canal_pwm, divisor_clock);    // Define o divisor de clock para o PWM.
    
    // Calcula o valor de PWM a ser enviado ao servo. O cálculo converte a largura do pulso em microssegundos para o valor PWM.
    pwm_set_gpio_level(MOTOR_PIN, (largura_pulso_us * valor_contador_pwm) / 20000); 
}

int main() {
    stdio_init_all();                 // Inicializa a comunicação serial (útil para debug ou prints).
    
    gpio_set_function(MOTOR_PIN, GPIO_FUNC_PWM);  // Configura o pino GPIO 22 para ser usado como saída PWM.
    
    uint canal_pwm = pwm_gpio_to_slice_num(MOTOR_PIN);  // Obtém o número do "slice" (canal) PWM associado ao pino GPIO 22.
    pwm_set_enabled(canal_pwm, true);   // Habilita o PWM no canal selecionado para o pino.

    while (true) {                     // Inicia um loop infinito para controlar o servo continuamente.
        ajustar_posicao_servo(canal_pwm, 2400);  // Brilho (12%) Move o servo para a posição de 180 graus (largura do pulso de 2400 microssegundos).
        sleep_ms(5000);                // Aguarda 5 segundos.

        ajustar_posicao_servo(canal_pwm, 1470);  // Brilho (7.35%) Move o servo para a posição de 90 graus (largura do pulso de 1470 microssegundos).
        sleep_ms(5000);                // Aguarda 5 segundos.

        ajustar_posicao_servo(canal_pwm, 500);   // Brilho (2.5%) Move o servo para a posição de 0 graus (largura do pulso de 500 microssegundos).
        sleep_ms(5000);                // Aguarda 5 segundos.

        // Movimento suave de 0° a 180° e de volta para 0°, repetido duas vezes.
        for (int i = 0; i < 2; i++) {  // Repete o movimento suave duas vezes.
            // Movimento suave de 0° a 180° (aumentando a largura do pulso de 500 a 2400 microssegundos).
            for (uint32_t largura_pulso = 500; largura_pulso <= 2400; largura_pulso += 5) {  // Renomeado para largura_pulso
                ajustar_posicao_servo(canal_pwm, largura_pulso);  // Ajusta o servo para o valor de largura de pulso atual.
                sleep_ms(10);                 // Aguarda 10 milissegundos entre os ajustes para uma transição suave.
            }

            // Movimento suave de 180° a 0° (diminuindo a largura do pulso de 2400 a 500 microssegundos).
            for (uint32_t largura_pulso = 2400; largura_pulso >= 500; largura_pulso -= 5) {  // Renomeado para largura_pulso
                ajustar_posicao_servo(canal_pwm, largura_pulso);  // Ajusta o servo para o valor de largura de pulso atual.
                sleep_ms(10);                 // Aguarda 10 milissegundos entre os ajustes para uma transição suave.
            }
        }
    }
}

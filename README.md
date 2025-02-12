# Controle de Servomotor por PWM com Raspberry Pi Pico W

## Descrição

Este projeto tem como objetivo controlar a posição de um servomotor utilizando o módulo PWM do microcontrolador RP2040, presente no Raspberry Pi Pico W. O controle é feito por sinais PWM com diferentes larguras de pulso, para ajustar a posição do servo entre 0º, 90º e 180º.

A simulação foi realizada no ambiente Wokwi no Virtual Studio Code.  

## Componentes Utilizados

- **Microcontrolador**: Raspberry Pi Pico W
- **Servomotor**: Micro Servo Padrão (simulado no Wokwi)
- **Simulador**: Wokwi (integrado ao VS Code)

## Requisitos da Atividade

1. **Configuração do PWM**: Frequência de aproximadamente 50Hz (Período de 20ms).
2. **Definição dos Ciclos Ativos**:
   - 2.400µs para 180° (Duty Cycle: 12%) - Aguarde 5 segundos.
   - 1.470µs para 90° (Duty Cycle: 7,35%) - Aguarde 5 segundos.
   - 500µs para 0° (Duty Cycle: 2,5%) - Aguarde 5 segundos.
3. **Movimentação Contínua do Servo**:
   - Suavidade com incremento de ±5µs e atraso de 10ms.
4. **Experimento com LED RGB**: Utilização da ferramenta BitDogLab na GPIO 11.
5. **Desenvolvimento e Versionamento**: VS Code com Pico SDK e GitHub para registro da atividade.

## Valores de PWM

A tabela abaixo mostra os valores de **Largura do Pulso** e os **Níveis PWM** para cada posição do servo (0º, 90º e 180º):

| **Posição do Servo** | **Largura do Pulso (µs)** | **Nível PWM** |
|----------------------|---------------------------|---------------|
| 0º                   | 500µs                     | 976           |
| 90º                  | 1470µs                    | 2.872         |
| 180º                 | 2400µs                    | 4.687         |

Esses valores são usados para configurar a posição do servomotor, com base na largura do pulso PWM.

## Como Rodar o Código

### 1. **Configurar o Ambiente**

Antes de rodar o código, você precisa configurar seu ambiente de desenvolvimento.

- **Instale o VS Code**: Caso ainda não tenha o Visual Studio Code instalado.
- **Instale o Pico SDK**: Siga as instruções da documentação oficial do Raspberry Pi para configurar o Pico SDK.
- **Instale a extensão do Wokwi**: Para simular o projeto online no VS Code, instale a extensão Wokwi.

### Vídeo Demonstrativo

Para assistir ao vídeo associado a esta simulação, acesse o link:
[Vídeo da Simulação](https://drive.google.com/file/d/1PzPxoAWIK5ZTWq-TgfTG_93DT0bdK0Oh/view?usp=sharing)


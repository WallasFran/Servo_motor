# Controle de Servomotor por PWM com Raspberry Pi Pico W

## Descrição da Atividade

Esta atividade tem como objetivo projetar e simular o controle do ângulo de um servomotor utilizando o módulo PWM do microcontrolador RP2040, presente no Raspberry Pi Pico W. A simulação será realizada no ambiente online Wokwi, sem necessidade de circuitos adicionais de interface.

## Componentes Utilizados

- **Microcontrolador:** Raspberry Pi Pico W
- **Servomotor:** Micro Servo Padrão - Wokwi
- **Simulador:** Wokwi (Integrado ao VS Code)

## Requisitos da Atividade

### Configuração do PWM:

- Frequência de aproximadamente 50Hz (Período de 20ms)

### Definição dos Ciclos Ativos:

- **2.400µs** para **180°** (Duty Cycle: 12%) - Aguarde 5s
- **1.470µs** para **90°** (Duty Cycle: 7,35%) - Aguarde 5s
- **500µs** para **0°** (Duty Cycle: 2,5%) - Aguarde 5s

### Movimentação Contínua do Servo:

- Suavidade com incremento de ±5µs e atraso de 10ms

### Experimento com LED RGB:

- Utilização da ferramenta BitDogLab na GPIO 12

### Desenvolvimento e Versionamento:

- VS Code com Pico SDK e GitHub para registro da atividade

## Cálculos Fundamentais

### 1. Cálculo da Frequência PWM

A frequência do PWM é dada por:

\(\text{Frequência} = \frac{\text{Clock RP2040}}{\text{Divisor de Clock} \times \text{WRAP}}\)

Onde:

- **125.000.000 Hz** (Clock do RP2040)
- **50 Hz** (Frequência desejada)
- **64** (Divisor de Clock escolhido)

Resolvendo para WRAP:

\(WRAP = \frac{125.000.000}{64 \times 50} - 1 = 39.061\)

O valor final utilizado no código será **39.061** (valor inteiro mais próximo permitido pelo RP2040).

### 2. Conversão da Largura do Pulso para Níveis PWM

A largura do pulso em níveis PWM é dada por:

\(\text{Nível PWM} = \frac{\text{Largura do Pulso} \times \text{WRAP}}{\text{Período Total}}\)

Onde o período total é 20ms = 20.000µs:

- **0° (500µs):**
  \(\frac{500 \times 39.061}{20.000} = 976\)
- **90° (1470µs):**
  \(\frac{1.470 \times 39.061}{20.000} = 2.872\)
- **180° (2400µs):**
  \(\frac{2.400 \times 39.061}{20.000} = 4.687\)

Esses valores são passados para a função `pwm_set_gpio_level()` no código.

## Como Rodar o Código

### Configurar o Ambiente:

1. Instalar o VS Code
2. Configurar o Pico SDK
3. Integrar o Wokwi

### Clonar o Repositório:

```sh
git clone <URL_DO_REPOSITORIO>
cd <NOME_DO_REPOSITORIO>
```

### Compilar e Executar:

```sh
mkdir build && cd build
cmake ..
make
```

### Carregar no Wokwi:

- Abrir o projeto no Wokwi e rodar a simulação

## Conclusão

Com este projeto, conseguimos controlar um servomotor utilizando PWM no Raspberry Pi Pico W. Através dos cálculos apresentados, garantimos que o servo recebe sinais precisos para atingir as posições desejadas. A atividade também inclui um experimento com LED RGB na GPIO 12, destacando os efeitos do PWM na iluminação.

## Vídeo Demonstrativo

Para assistir ao vídeo associado a esta simulação, acesse o link:
[Vídeo da Simulação](https://drive.google.com/file/d/1PzPxoAWIK5ZTWq-TgfTG_93DT0bdK0Oh/view?usp=sharing)


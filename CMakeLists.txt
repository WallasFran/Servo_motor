cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Inicializa o pico_sdk do local instalado
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()

set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()

set(PICO_BOARD pico_w CACHE STRING "Board type")

# Importa o SDK do Raspberry Pi Pico
include(pico_sdk_import.cmake)

project(Servo_motor C CXX ASM)

# Inicializa o SDK do Pico
pico_sdk_init()

# Adiciona o executável
add_executable(Servo_motor Servo_motor.c )

pico_set_program_name(Servo_motor "Servo_motor")
pico_set_program_version(Servo_motor "0.1")

# Habilita saída via UART e USB
pico_enable_stdio_uart(Servo_motor 1)
pico_enable_stdio_usb(Servo_motor 1)

# Adiciona as bibliotecas necessárias ao projeto
target_link_libraries(Servo_motor
    pico_stdlib
    hardware_pwm  # Adiciona suporte a PWM
)

# Adiciona diretórios de inclusão padrão
target_include_directories(Servo_motor PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Adiciona saídas extras
pico_add_extra_outputs(Servo_motor)

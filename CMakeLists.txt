# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "G:/PicoTools/Pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(S_PicoKit C CXX ASM)

set(PICO_CXX_ENABLE_EXCEPTIONS 1)

set(PICO_CXX_ENABLE_RTTI 1)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(S_PicoKit S_PicoKit.cpp )

pico_set_program_name(S_PicoKit "S_PicoKit")
pico_set_program_version(S_PicoKit "0.1")

pico_enable_stdio_uart(S_PicoKit 1)
pico_enable_stdio_usb(S_PicoKit 0)

# Add the standard library to the build
target_link_libraries(S_PicoKit pico_stdlib)

# Add any user requested libraries
target_link_libraries(S_PicoKit
        hardware_clocks
        )

pico_add_extra_outputs(S_PicoKit)


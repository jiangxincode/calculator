cmake_minimum_required(VERSION 3.14)
project(calculator C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(calculator
    src/main.c
    src/conversion.c
    src/signal_process.c)
target_link_libraries(calculator PRIVATE PkgConfig::GTK4 m)

add_executable(calculator_test
    test/test_calculator.c
    test/test_calculator.h)
target_link_libraries(calculator_test PRIVATE PkgConfig::GTK4 m)


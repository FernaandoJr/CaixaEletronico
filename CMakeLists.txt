cmake_minimum_required(VERSION 3.28)
project(CaixaEletronico C)

set(CMAKE_C_STANDARD 23)

add_executable(CaixaEletronico main.c
        Conta.c
        Conta.h
)

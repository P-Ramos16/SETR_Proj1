cmake_minimum_required(VERSION 3.10)  # Define a versão mínima do CMake
project(HelloProject)  # Nome do projeto

set(CMAKE_C_STANDARD 11)  # Define a versão da linguagem C
set(CMAKE_C_FLAGS "-Wall -Wextra")  # Adiciona flags de compilação

# Define os ficheiros-fonte do projeto
add_executable(hello main.c hello.c)



cmake_minimum_required(VERSION 3.10)  # Define a versão mínima do CMake
project(MyDLLProject)  # Nome do projeto

set(CMAKE_C_STANDARD 11)  # Define a versão do C
set(CMAKE_C_FLAGS "-Wall -Wextra")  # Adiciona flags de compilação

# Adiciona os ficheiros-fonte do projeto
add_executable(mydll 
    src/main.c
    #src/tests.c 
    src/module/MyDLL.c
)

# Especifica os diretórios para os ficheiros de cabeçalho (.h)
include_directories(src/module)


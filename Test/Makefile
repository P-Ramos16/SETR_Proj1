# Definir o compilador
CC = gcc

# Definir flags de compilação (-Wall para avisos, -Wextra para mais verificações)
CFLAGS = -Wall -Wextra -std=c11

# Definir os ficheiros do projeto
SRC = main.c hello.c
OBJ = $(SRC:.c=.o)
TARGET = hello

# Regra principal (gera o executável)
all: $(TARGET)

# Compilar os ficheiros objeto e gerar o executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra para compilar ficheiros .c em .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa ficheiros gerados
clean:
	rm -f $(OBJ) $(TARGET)


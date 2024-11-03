# Variáveis
CC = gcc
CFLAGS = -Wall
TARGET = main

# Regras
all: $(TARGET)

$(TARGET): main.o heap.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o heap.o

main.o: main.c heap.h
	$(CC) $(CFLAGS) -c main.c

ArvoreBin.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

clean:
	rm -f *.o $(TARGET)

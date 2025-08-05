TARGET = server.out
SRC = server.c
CC = gcc
CFLAGS = -Wall -Wextra

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
clean:
	rm -f $(TARGET)

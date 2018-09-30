CC = gcc
cflags = -Wall -lm

root: root.c
	$(CC) $< -o $@ $(cflags)

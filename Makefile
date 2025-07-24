CC		= gcc
CFLAGS	= -std=c11 -Wall -Wextra -Wpedantic

all: scat

scat: main.c
	$(CC) $(CFLAGS) -o $@ $<

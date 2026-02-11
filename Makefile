all: trab1

CC = gcc
override CFLAGS += -g -pthread -lm

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.c' -print)
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

trab1: $(SRCS) $(HEADERS)
	$(CC) $(SRCS) -o "$@" $(CFLAGS)

clean:
	rm -f trab1
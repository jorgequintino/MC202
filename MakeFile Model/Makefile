CC=gcc
CFLAGS=-std=c99 -Wall -Werror -Wvla -g
LDFLAGS=-lm
SRCS=cozinha.c heap.c meal.c winona9000.c
OBJS=$(SRCS:.c=.o)
EXEC=cozinha

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS)

clean:
	rm -rf $(OBJS)

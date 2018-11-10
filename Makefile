CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -lSDL2 -Isrc/include -g

# relative to src/
OBJS=src/main.o src/sdl_ressources/rendering.o src/parser.o
BIN=main

all: $(BIN)

$(BIN): $(OBJS)

clean:
	$(RM) $(OBJS) $(BIN)

CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -Isrc/include -g
LDLIBS=-lSDL2 -lSDL2_image -lm

OBJS=src/main.o src/sdl_ressources/rendering.o src/parser.o src/inputs.o src/sdl_ressources/load.o src/physics/physics.o src/physics/vector.o src/sdl_ressources/menu.o
BIN=main

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) -o $(BIN)

clean:
	$(RM) $(OBJS) $(BIN)

CC=gcc
CPPFLAGS = `pkg-config --cflags sdl2`
CFLAGS=-Wall -Wextra -pedantic -std=c99 -Isrc/include -g
LDLIBS=-lSDL2 -lSDL2_image `pkg-config --libs sdl2`

OBJS=src/main.o src/sdl_ressources/rendering.o src/parser.o
BIN=main

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) -o $(BIN)

clean:
	$(RM) $(OBJS) $(BIN)

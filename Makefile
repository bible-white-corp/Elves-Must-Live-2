CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99 -Isrc/include

VPATH=src

# relative to src/
OBJS=main.o
BIN=EML2

all: $(BIN)

$(BIN): $(OBJS)

clear:
	$(RM) $(OBJS) $(BIN)

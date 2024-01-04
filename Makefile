CC = cc -std=c11

DEBUG = 0

CFLAGS = -Iinc -Wall -Wextra -Wpedantic -Wfatal-errors -Wshadow

ifeq (1, $(DEBUG))
CFLAGS += -g
endif

default: clean run

test.exe: test.o
	@$(CC) $(CFLAGS) test.o -o test.exe

test.o: test.c
	@$(CC) $(CFLAGS) -c test.c

.PHONY: run
.PHONY: clean

run: test.exe
	./test.exe

clean:
	@rm -f *.o *.exe

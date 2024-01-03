cc=gcc

default: main.exe

main.exe: main.o sort.o
	$(cc) main.o sort.o -o main.exe

main.o: main.c
	$(cc) -c main.c

sort.o: sort/sort.c
	$(cc) -c sort/sort.c

.PHONY: run
run: main.exe
	./main.exe

.PHONY: clean
clean:
	rm -f *.o *.exe

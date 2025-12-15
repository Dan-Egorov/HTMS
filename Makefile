all: main.o text.o
	gcc main.o text.o

main.o: main.c text.h
	gcc -c main.c
text.o: text.c text.h
	gcc -c text.c

clean:
	rm -f *.o
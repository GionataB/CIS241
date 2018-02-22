program: main.o bonazzi.o
				 gcc -o program main.o bonazzi.o

main.o: main.c lab3.h
				gcc -c main.c

bonazzi.o: bonazzi.c lab3.h
					 gcc -c bonazzi.c

clean:
			rm -f *.o program

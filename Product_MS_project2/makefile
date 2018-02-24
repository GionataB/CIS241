program: main.o bonazzi.o
				 gcc -o program main.o bonazzi.o

main.o: main.c lab3.h
				gcc -c main.c

bonazzi.o: bonazzi.c project2.h
					 gcc -c bonazzi.c

file_utilities.o: file_utilities.c file_utilities.h
									gcc -c file_utilities.c
									
clean:
			rm -f *.o program

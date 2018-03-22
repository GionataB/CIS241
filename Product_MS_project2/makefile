program: main.o bonazzi.o linked_list.o file_utilities.o
				 gcc -std=c99 -o program main.o bonazzi.o linked_list.o file_utilities.o

main.o: main.c UserInterface.h
				gcc -std=c99 -c main.c -o main.o

bonazzi.o: UIbonazzi.c UserInterface.h
					 gcc -std=c99 -c UIbonazzi.c -o bonazzi.o

linked_list.o: LLbonazzi.c LinkedList.h
							 gcc -std=c99 -c LLbonazzi.c -o linked_list.o

file_utilities.o: file_utilities.c file_utilities.h
									gcc  -std=c99 -c file_utilities.c -o file_utilities.o

clean:
			rm -f *.o program

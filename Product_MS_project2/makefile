program: main.o bonazzi.o linked_list.o file_utilities.o
				 gcc -o program main.o bonazzi.o linked_list.o file_utilities.o

main.o: main.c UserInterface.h
				gcc -c main.c -o main.o

bonazzi.o: UIbonazzi.c UserInterface.h
					 gcc -c UIbonazzi.c -o bonazzi.o

linked_list.o: LLbonazzi.c LinkedList.h
							 gcc -c LLbonazzi.c -o linked_list.o

file_utilities.o: file_utilities.c file_utilities.h
									gcc -c file_utilities.c -o file_utilities.o

clean:
			rm -f *.o program

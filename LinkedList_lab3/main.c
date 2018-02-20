#include"lab3.h"

int main()
{
	int array[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	struct node *head;
	head = init();   //after this statement, a linked list has been created with only a head node

	int i;
	for (i=0;i<10;i++)
	{
		insert(head, array[i]);   //create a new node to store an array element. This new node is inserted to the end of current linked list
	}

	display(head);  //print data for all nodes in the linked list except the head node (which is empty)

	deleteAll(head);  //delete the entire linked list including the head node
}

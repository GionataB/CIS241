/*******************************************************************************
* Header file with functions' declarations for a linked list.
* @Author Gionata Bonazzi
* @Version 4 March 2018
*******************************************************************************/

#ifndef LL_PROJECT2_H
#define LL_PROJECT2_H

/*******************************************************************************
* A linked list structure. For each node, the linked list saves a name, a unit,
* a price and a quantity, as well as the pointer to the next node in the list.
* the name and the unit are strings.
* the price and the quantity are integers.
*******************************************************************************/
struct node
{
	char* name;
	char* unit;
	int price;
	int quantity;
	struct node *next;
};

/*******************************************************************************
* Initialize the head of a linked list. The head of the list contains only
* a pointer to the next node, it does not contain any data.
* @return a pointer to the head of the linked list.
*******************************************************************************/
struct node* init ();

/*******************************************************************************
* Insert a new node at the end of the linked list pointed by head.
* @param head the head to the linked list.
* @param name the name of the product saved in the node.
* @param unit the unit of the product saved in the node.
* @param price the price per item of the product saved in the node.
* @param quantity the number of items of the same product available.
*******************************************************************************/
void insert(struct node* head, char* name, char* unit, int price, int quantity);

/*******************************************************************************
* Delete the desired node from the list.
* @param head the head to the linked list.
* @param name the name of the product to delete.
*******************************************************************************/
void delete(struct node* head, char* name);

/*******************************************************************************
* Search the list for the product whose name is the same as the name provided.
* @param head the head to the linked list.
* @param name the name of the product to search.
* @return 0 if the product has been found, 1 if it was not.
*******************************************************************************/
int search(struct node* head, char* name);

/*******************************************************************************
* Search the list for the product whose name is the same as the name provided.
* @param head the head to the linked list.
* @param name the name of the product to search.
* @return The object if it is in the list, or NULL if it is not.
*******************************************************************************/
struct node* find(struct node* head, char* name);


/*******************************************************************************
* Print all the data of the given node.
* @param product the node whose data are to be printed.
*******************************************************************************/
void displayProduct(struct node* product);

/*******************************************************************************
* Print all the data of all the nodes in the list.
* @param head the pointer to the head of the list.
*******************************************************************************/
void displayAll(struct node* head);

/*******************************************************************************
* Add one to the quantity of a node.
* @param head the head to the linked list.
* @param name the name of the product to increment.
*******************************************************************************/
void purchase(struct node* head, char* name);

/*******************************************************************************
* Decrease the quantity of an item by one.
* If the quantity of the item after selling is zero, the node gets deleted.
* @param head the head to the linked list.
* @param name the name of the product to decrease.
* @return 0 if the product has been sold but remains in the list, 1 if the
*					product has been sold and removed from the list.
*******************************************************************************/
int sell(struct node* head, char* name);

/*******************************************************************************
* Count the number of nodes in the list.
* It does not count the head node.
* @param head the head to the linked list.
* @return the number of nodes in the list, except the head node.
*******************************************************************************/
int listSize(struct node* head);

/*******************************************************************************
* Save the data of all the nodes in the list on a file. If a file already
* exists, the function deletes it and create a new one.
* This allows to overwrite the informations without having to clean the file.
* @param head the head to the linked list.
* @param filename the name of the file.
* @param size the total size of the data to be saved.
*******************************************************************************/
int save(struct node* head, char* filename);

/*******************************************************************************
* Delete the entire linked list including the head.
* @param head the head to the linked list.
*******************************************************************************/
void deleteAll (struct node* head);

#endif

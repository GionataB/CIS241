#ifndef INTERFACE_P2_H
#define INTERFACE_P2_H

#include "LinkedList.h"

/*******************************************************************************
* Print a list of options that the user can select.
*******************************************************************************/
void printOptions();

/*******************************************************************************
* Asks the user for a product's name.
* @return a string containing the product's name.
*******************************************************************************/
char* askName();

/*******************************************************************************
* Delete the list and exit the program.
* @param head the head of the list.
*******************************************************************************/
void close(struct node* head);

/*******************************************************************************
* Create a list with the head 'head'.
* @param head the head of the list.
*******************************************************************************/
int makeList(struct node** head);

/*******************************************************************************
* Asks for a product, and insert it in the list.
* Display an error message if the product already exists, or a confirmation
* message if the product has been inserted.
* @param head the head of the list.
*******************************************************************************/
void insertProduct(struct node* head);//ask for the product to insert, and insert in the LL.

/*******************************************************************************
* Asks for a product, and delete it from the list.
* display an error message if the product is not in the list, or a confirmation
* message if the product has been deleted.
* @param head the head of the list.
*******************************************************************************/
void deleteProduct(struct node* head);

/*******************************************************************************
* Delete everything in the list.
* @param head the head of the list.
* @return 1 if the list has been deleted.
*******************************************************************************/
int deleteList(struct node* head);

/*******************************************************************************
* Asks for a product, and display whether the product is in the list or not.
* @param head the head of the list.
*******************************************************************************/
void searchProduct(struct node* head);

/*******************************************************************************
* Display all the products in the list.
* @param head the head of the list.
*******************************************************************************/
void displayProducts(struct node* head);

/*******************************************************************************
* Asks for a product and purchase it if it already is in the list.
* @param head the head of the list.
*******************************************************************************/
void purchaseProduct(struct node* head);

/*******************************************************************************
* Asks for a product and sell it if it is in the list.
* @param head the head of the list
*******************************************************************************/
void sellProduct(struct node* head);

/*******************************************************************************
* Saves the products on the list on a file.
* @param head the head of the list.
*******************************************************************************/
void saveList(struct node* head);

#endif

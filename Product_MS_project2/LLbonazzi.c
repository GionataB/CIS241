/*******************************************************************************
* Implementation of the functions defined inside LinkedList.h
* @Author Gionata Bonazzi
* @Version 4 March 2018
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "file_utilities.h"
#include "LinkedList.h"

struct node* init(){
  struct node *head = (struct node*) malloc(sizeof(struct node*));
  head->next = NULL;
  head->name = "";
  head->unit = "";
  return head;
}

void insert(struct node* head, char* name, char* unit, int price, int quantity){
  if(head->next == NULL){
    head->next = (struct node*) malloc(sizeof(struct node*));
    head->next->name = name;
    head->next->unit = unit;
    head->next->price = price;
    head->next->quantity = quantity;
    head->next->next = NULL;
  }
  else
    return insert(head->next, name, unit, price, quantity); //Recursion
}

void delete(struct node* head, char* name){
  if(strcmp(head->next->name, name)){
    struct node *temp = head->next;
    head->next = head->next->next;
    free(temp->name);
    free(temp->unit);
    free(temp);
  }
  else
    delete(head->next, name);
}

int search(struct node* head, char* name){
  if(head->next == NULL)
    return 1;
  if(strcmp(head->next->name, name))
    return 0;
  else
    return search(head->next, name);
}

struct node* find(struct node* head, char* name){
  if(head->next == NULL)
    return NULL;
  else if(strcmp(head->next->name, name) == 0)
    return head->next;
  else
    return find(head->next, name);
}

void displayProduct(struct node* product){
  printf("Product's name:\t%s\n", product->next->name);
  printf("Product's unit:\t%s\n", product->next->unit);
  printf("Product's price:\t%d\n", product->next->price);
  printf("Product's quantity:\t%d\n\n", product->next->quantity);
}

void displayAll(struct node* head){
  if(head->next != NULL) //starts from head->next so the head's data won't be printed
    displayProduct(head->next); //recursion
}

void purchase(struct node* head, char* name){
  struct node* temp = find(head, name);
  temp->quantity++;
}

int sell(struct node *head, char* name){
  struct node* temp = find(head, name);
  temp->quantity--;
  if(temp->quantity == 0){
    delete(head, name);
    return 1;
  }
  return 0;
}

int listSize(struct node* head){
  int size = 0;
  while(head->next != NULL){
    size++;
    head = head->next;
  }
  return size;
}

int save(struct node* head, char* filename){
  int size = 19 + (listSize(head) * 160) + 100;
  char* str = (char*) malloc(size*sizeof(char));
  strcpy(str, "Saved Linked List\n");//18 chars, constant
  char* temp;
  for(int i = 1; head->next->next != NULL; head = head->next, i++){
    strcat(str, "Element number: ");//16 chars per node, constant
    temp = (char*) malloc(4 * sizeof(char));//variable, max of 4 chars. (max 9999 nodes in the list)
    sprintf(temp, "%d", i); //Convert int to string
    strcat(str, temp);
    strcat(str, "\n");//1 char per node, constant.
    free(temp);
    strcat(str, "name: ");//6 chars per node, constant.
    strcat(str, head->next->name);//variable, max of 50 chars. (a name 50 letters long max)
    strcat(str, "\t");//1 char per node, constant
    strcat(str, "unit: ");//6 chars per node, constant
    strcat(str, head->next->unit);//variable, max of 50 chars. (a type of product 50 letters long max)
    strcat(str, "\t");//1 char per node, constant
    strcat(str, "price: ");//7 chars per node, constant
    temp = (char*) malloc(6 * sizeof(char));//variable, max of 6 chars. (999999 is the max price)
    sprintf(temp, "%d", head->next->price);
    strcat(str, temp);
    free(temp);
    strcat(str, "\t");//1 char per node, constant
    strcat(str, "quantity: ");//10 chars per node, constant
    temp = (char*) malloc(4 * sizeof(char));//variable, max of 4 chars. (max 9999 items per node)
    sprintf(temp, "%d", head->next->quantity);
    strcat(str, temp);
    strcat(str, "\n");//1 char per node, constant
  } //total: 160 chars per node.
  strcat(str, "\0");//1 char, constant
  int strSize = strlen(str); //To have a more precise size to pass to write_file.
  int fileSize = write_file(filename, str, strSize);
  free(str);
  return fileSize;
}

void deleteAll(struct node *head){
  if(head != NULL){
    deleteAll(head->next); //Recursion
    if(strcmp(head->name, "") != 0)
      free(head->name); //Assume the name is a dinamically allocated string
    if(strcmp(head->unit, "") != 0)
      free(head->unit); //Assume the unit is a dinamically allocated string
    free(head); //Free from the last element to the head.
  }
}

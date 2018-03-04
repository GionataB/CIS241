#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "file_utilities.h"
#include "project2.h"

struct node* init(){
  struct node *head = (struct node*) malloc(sizeof(struct node*));
  head->next = NULL;
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
    insert(head->next, name, unit, price, quantity); //Recursion
}

void delete(struct node* head, char* name){
  if(strcmp(head->next->name, name)){
    struct node *temp = head->next;
    head->next = head->next->next;
    free(temp);
  }
  else
    delete(head->next, name);
}

struct node* search(struct node* head, char* name){
  if(head->next == NULL){
    printf("Not Found");
    return NULL;
  }
  if(strcmp(head->next->name, name))
    printf("Found");
    return head->next;
  else
    search(head->next, name);
}

void displayProduct(struct node* product){
  printf("Product's name:\t%s\n", head->next->name);
  printf("Product's unit:\t%s\n", head->next->unit);
  printf("Product's price:\t%d\n", head->next->price);
  printf("Product's quantity:\t%d\n\n", head->next->quantity);
}

void displayAll(struct node* head){
  if(head->next != NULL){ //starts from head->next so the head's data won't be printed
    displayProduct(head->next);
    display(head->next); //Recursion
  }
}

void purchase(struct node* head, char* name){
  struct node* temp = search(head, name);
  temp->quantity++;
}

void sell(struct node *head, char* name){
  struct node* temp = search(head, name);
  temp->quantity--;
  if(temp->quantity == 0)
    delete(head, name);
}

void save(struct node* head, char* filename){
  int size = 19 + (listSize(head) * 160) + 100;//FIXME: create the method listSize, and add the constants to that.
  //FIXME: the formula for the size: 19 + (listSize() * 160);
  //FIXME: the 100 is to have a bit of room.
  char* str = (char*) malloc(size*sizeof(char));
  strcpy(str, "Saved Linked List\n");//18 chars, constant
  for(int i = 1; head->next->next != NULL; head = head->next, i++){
    strcat(str, "Element number: ");//16 chars per node, constant
    strcat(str, i);//variable, max of 4 chars. (max 9999 nodes in the list)
    strcat(str, "\n");//1 char per node, constant.
    strcat(str, "name: ");//6 chars per node, constant.
    strcat(str, head->next->name);//variable, max of 50 chars. (a name 50 letters long max)
    strcat(str, "\t");//1 char per node, constant
    strcat(str, "unit: ");//6 chars per node, constant
    strcat(str, head->next->unit);//variable, max of 50 chars. (a type of product 50 letters long max)
    strcat(str, "\t");//1 char per node, constant
    strcat(str, "price: ");//7 chars per node, constant
    strcat(str, head->next->price);//variable, max of 6 chars. (999999 is the max price)
    strcat(str, "\t");//1 char per node, constant
    strcat(str, "quantity: ");//10 chars per node, constant
    strcat(str, head->next->quantity);//variable, max of 4 chars. (max 9999 items per node)
    strcat(str, "\n");//1 char per node, constant
  } //total: 160 chars per node.
  strcat(str, "\0");//1 char, constant
  int strSize = strlen(str); //To have a more precise size to pass to write_file.
  write_file(filename, str, strSize);
  free(str);
}

void deleteAll(struct node *head){
  if(head != NULL){
    deleteAll(head->next); //Recursion
    free(head->name); //Assume the name is a dinamically allocated string
    free(head->unit); //Assume the unit is a dinamically allocated string
    free(head); //Free from the last element to the head.
  }
}

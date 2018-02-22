#include "file_utilities.h"
#include "project2.h"

struct node* init(){
  struct node *head = (struct node*) malloc(sizeof(struct node*));
  head->next = NULL;
  return head;
}

void insert(struct node *head, char* name, char* unit, int price, int quantity){
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

void delete(struct node *head, char* name){
  if(strcmp(head->next->name, name)){
    struct node *temp = head->next;
    head->next = head->next->next;
    free(temp);
  }
  else
    delete(head->next, name);
}

struct node* search(struct node *head, char* name){
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

void displayProduct(struct node *product){
  printf("Product's name:\t%s\n", head->next->name);
  printf("Product's unit:\t%s\n", head->next->unit);
  printf("Product's price:\t%d\n", head->next->price);
  printf("Product's quantity:\t%d\n\n", head->next->quantity);
}

void displayAll(struct node *head){
  if(head->next != NULL){ //starts from head->next so the head's data won't be printed
    displayProduct(head->next);
    display(head->next); //Recursion
  }
}

void purchase(struct node *head, char* name){
  struct node* temp = search(head, name);
  temp->quantity++;
}

void sell(struct node *head, char* name){
  struct node* temp = search(head, name);
  temp->quantity--;
  if(temp->quantity == 0)
    delete(head, name);
}

//FIXME: DELETE THIS
int listSize(struct node *head){
  int size = 0;
  for(; head->next != NULL; head = head->next) size++;
  return size;
}

void save(struct node *head, char* filename){
  int size = listSize(head);//FIXME: DELETE THIS
  char* str = (char*) malloc(size*sizeof(char)); //FIXME: DELETE THIS
}

void deleteAll(struct node *head){
  if(head != NULL){
    deleteAll(head->next); //Recursion
    free(head); //Free from the last element to the head.
  }
}

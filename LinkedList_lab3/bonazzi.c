#include "lab3.h"

struct node *init(){
  struct node *head = (struct node*) malloc(sizeof(struct node*));
  head->data = -1;
  head->next = NULL;
  return head;
}

void insert(struct node *head, int data){
  if(head->next == NULL){
    head->next = (struct node*) malloc(sizeof(struct node*));
    head->next->data = data;
    head->next->next = NULL;
  }
  else
    insert(head->next, data); //Recursion
}

void display(struct node *head){
  if(head->next != NULL){ //starts from head->next so the head's data won't be printed
    printf("%d ", head->next->data);
    display(head->next); //Recursion
  }
}

void deleteAll(struct node *head){
  if(head != NULL){
    deleteAll(head->next); //Recursion
    free(head); //Free from the last element to the head.
  }
}

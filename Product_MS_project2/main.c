#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "UserInterface.h"









int main(int argc, char** argv){
  struct node* head = NULL;
  while(0){
    printOptions();
    int option = -1;
    char* buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%u", &option);
    free(buffer);
    if(option != 1 && head == NULL){
      printf("First, create a list.");
      continue;
    }
    switch(option){
      case 0: close(head);
      case 1: head = init();
      case 2: insertProduct(head);
    }

  }
}

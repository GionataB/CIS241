#include <stdio.h>
#include <stdlib.h>
#include "UserInterface.h"

int main(int argc, char** argv){
  struct node* head = NULL;
  int listExists = 1;
  int option = -1;
  while(option != 0){
    option = -1; //reset the option so that there are no errors.
    printOptions(); //print the options list.
    char* buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%u", &option);
    free(buffer);
    if(option != 1 && listExists != 0){
      printf("First, create a list by selecting option 1.");
      continue;
    }
    switch(option){
      case 0: close(head);
              break;
      case 1: listExists = makeList(&head);
              break;
      case 2: insertProduct(head);
              break;
      case 3: deleteProduct(head);
              break;
      case 4: listExists = deleteList(head);
              break;
      case 5: searchProduct(head);
              break;
      case 6: displayProducts(head);
              break;
      case 7: purchaseProduct(head);
              break;
      case 8: sellProduct(head);
              break;
      case 9: saveList(head);
              break;
      default: printf("Unkown option. Choose an option from the list.");
    }
  }
}

#include <stdio.h>
#include <stdlib.h>
#include "UserInterface.h"
#include "LinkedList.h"

int main(int argc, char** argv){
  struct node* head = NULL;
  int listExists = 1;
  int option = -1;
  while(option != 0){
    option = -1; //reset the option so that there are no errors.
    printOptions(); //print the options list.
    scanf("%u", &option);
    if(option == 0 && listExists != 0){
      printf("Closing the program...\n");
      exit(0);
    }
    if(option != 1 && listExists != 0){
      printf("First, create a list by selecting option 1.\n");
      continue;
    }
    if(option == 1 && listExists == 0){
      deleteList(head);
    }
    switch(option){
      case 0: printf("Closing the program...\n");
              close(head);
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
      default: printf("Unkown option. Choose an option from the list.\n");
    }
  }
}

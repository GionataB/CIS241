#include <stdio.h>
#include <stdlib.h>
#import "UserInterface.h"
#import "LinkedList.h"

void printOptions(){
  printf("0: Close the program.\t1: Create a list.\n");
  printf("2: Insert a product.\t3: Delete a product.\n");
  printf("4: Delete the list.\t5: Search a product.\n");
  printf("6: Display products.\t7: Purchase a product.\n");
  printf("8: Sell a product.\t9: Save to file.\n");
}

char* askName(){
  printf("Please insert a name for the product: ");
  char* buffer = (char*) malloc(1024 * sizeof(char));
  fgets(buffer, 1024, stdin);
  char* name = (char*) malloc(125 * sizeof(char));
  sscanf(buffer, "%124s", name);
  name[124] = '\0';
  free(buffer);
  return name;
}

void close(struct node* head){
  deleteAll(head);
  exit(1);
}

int makeList(struct node** head){
  *head = init();
  if(*head != NULL){
    printf("List succesfully created.\n");
    return 0;
  }
  else{
    printf("Error in creating the list.\n");
    return 1;
  }
}

void insertProduct(struct node* head){
  char* name = askName();
  if(search(head, name) == 0){
    printf("The product is already in the list.\n");
    free(name);
    return;
  }
  else{
    printf("Please insert a unit for the product: ");
    char* unit = (char*) malloc(33*sizeof(char));
    char* buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%32s", unit);
    unit[32] = '\0';
    free(buffer);
    printf("Please insert a price for the product: ");
    int price = 0;
    buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%u", &price);
    free(buffer);
    if(price <= 0){
      printf("The price for a product must be a positive integer.\n");
      free(name);
      free(unit);
      return;
    }
    printf("Please insert a quantity for the product: ");
    int quantity = 0;
    buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%u", &quantity);
    free(buffer);
    if(quantity <= 0){
      printf("The quantity of a product must be a positive integer.\n");
      free(name);
      free(unit);
      return;
    }
    insert(head, name, unit, price, quantity);
    printf("Operation succesfull.\n");
  }
}

  void deleteProduct(struct node* head){
    char* name = askName();
    if(search(head, name) == 1)
      printf("The product is not in the list.\n");
    else{
      delete(head, name);
      printf("The product has been deleted.\n");
    }
    free(name);
  }

  int deleteList(struct node* head){
    deleteAll(head);
    return 1;
  }



  void searchProduct(struct node* head){
    char* name = askName();
    if(search(head, name) != 0)
      printf("The product is not in the list.\n");
    else{
      printf("The product is in the list.\n");
    }
    free(name);
  }

  void displayProducts(struct node* head){
    printf("Displaying the products in the list...\n");
    displayAll(head);
    printf("End.\n");
  }

  void purchaseProduct(struct node* head){
    char* name = askName();
    if(search(head, name) == 1)
      printf("The product is not in the list.\n");
    else
      purchase(head, name);
    free(name);
  }

  void sellProduct(struct node* head){
    char* name = askName();
    if(search(head, name) == 1)
      printf("The product is not in the list.\n");
    else{
      printf("The product has been sold.\n");
      if(sell(head, name) == 1)
        printf("The product has been completely sold and removed from the list.\n");
    }
    free(name);
  }

  void saveList(struct node* head){
    if(save(head, "Products.txt") != 0)
      printf("The list has been saved succesfully.\n");
    else
      printf("Error in saving the list to a file.\n");
  }

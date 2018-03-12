#import "UserInterface.h"

void printOptions(){
  printf("0: Close the program.\t1: Create a list.\n");
  printf("2: Insert a product.\t3: Delete a product.\n");
  printf("4: Delete the list.\t5: Search a product.\n");
  printf("6: Display products.\t7: Purchase a product.\n");
  printf("8: Sell a product.\t9: Save to file.\n");
}

void close(struct node* head){
  deleteAll(head);
  exit(1);
}

void insertProduct(struct node* head){
  printf("Please insert a name for the product: ");
  char* buffer = (char*) malloc(1024 * sizeof(char));
  fgets(buffer, 1024, stdin);
  char* name = (char*) malloc(124 * sizeof(char));
  sscanf(buffer, "%124s", name);
  if(search(head, name) == 1){
    printf("The product is already in the list.\n");
    free(buffer);
    free(name);
    return;
  }
  else{
    free(buffer);
    printf("Please insert a unit for the product: ");
    char* unit = (char*) malloc(32*sizeof(char));
    buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%32s", unit);
    free(buffer);
    printf("Please insert a price for the product: ");
    int price = 0;
    buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    sscanf(buffer, "%u", &price);
    free(buffer);
    if(price <= 0){
      printf("The price for a product must be a positive integer.");
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
      printf("The quantity of a product must be a positive integer.");
      free(name);
      free(unit);
      return;
    }
    insert(head, name, unit, price, quantity);
    printf("Operation succesfull.\n");
  }
}

  void deleteProduct(struct node* head){
    printf("Please insert a name for the product: ");
    char* buffer = (char*) malloc(1024 * sizeof(char));
    fgets(buffer, 1024, stdin);
    char* name = (char*) malloc(124 * sizeof(char));
    sscanf(buffer, "%124s", name);
    free(buffer);
    if(search(head, name) == 1)
      printf("The product is not in the list.\n");
    else{
      delete(head, name);
      printf("The product has been deleted.\n");
    }
    free(name);
  }

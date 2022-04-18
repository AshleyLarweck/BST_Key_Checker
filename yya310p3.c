#include "BinarySearchTree.h"
#include <stdio.h>
#include <string.h>

int main()
{
  FILE* fileIn;
  char command[10];
  char order[10];
  char buffer[50];
  Element element;
  double balance = 0;
  fileIn = fopen("largeInput.txt", "r");
  if(fileIn == NULL)
  {
    printf("Unable to open file.\n");
    return 1;
  }
    
  BinarySearchTree tree = newBinarySearchTree();  
  
  while(fgets(buffer, 50, fileIn) != NULL)
  {
    sscanf(buffer, "%s", command);
    
    if(strcmp(command, "CREATE") == 0)
    {
      sscanf(buffer, "%s %d", command, &element.accountNumber);
      insert(tree, element);
      //printf("%d\n", element.accountNumber);
    }
    else if(strcmp(command, "SALE") == 0)
    {
      sscanf(buffer, "%s %d %lf", command, &element.accountNumber, &balance);
     // balance = balance + search(tree, element.accountNumber);
     (search(tree, element.accountNumber))->element.accountBalance += balance;
    }
    else if(strcmp(command, "PRINT") == 0)
    {
      sscanf(buffer, "%s %s", command, order); 
      if(strcmp(order, "INORDER") == 0)
      {
        printInOrder(tree);
       // printf("\n");
      }
      else
      {
        printPreOrder(tree);
      //  printf("\n");
      }
  }
  }
  
freeBinarySearchTree(tree);

fclose(fileIn);
  
return 0;
}
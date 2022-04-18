#include "BinarySearchTree.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

BinarySearchTree newBinarySearchTree()
{
  BinarySearchTree bst = (BinarySearchTree)malloc(sizeof(BinarySearchTreeImp));
  bst->root = NULL;
  return bst;
}

void freeBinarySearchTree(BinarySearchTree tree)
{
  free(tree->root->left);
  free(tree->root->right);
  free(tree);
}

NodeT* allocateNode(Element value)
{
  NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
  newNode->element = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

NodeT* RecursiveSearch(NodeT* t, int searchVal)
{
  if(t == NULL)
  {
    return NULL;
  }
  else
  {
      if(t->element.accountNumber == searchVal)
      {
        return t;
      }
      else if(searchVal < t->element.accountNumber)
      {
        return RecursiveSearch(t->left, searchVal);
      }
      else
      {
        return RecursiveSearch(t->right, searchVal);
      }
  }
}

NodeT* search(BinarySearchTree tree, int searchVal)
{
    return RecursiveSearch(tree->root, searchVal);
}

int insert(BinarySearchTree tree, Element value)
{
  NodeT* n = allocateNode(value);
  NodeT* t;
  
  if(tree->root == NULL)
  {
    tree->root = n;
    return TRUE;
  }
  else
  {
    t = tree->root;
    while(t != NULL)
    {
        if(t->element.accountNumber == value.accountNumber)
        {
          return FALSE;
        }
        else if(value.accountNumber < t->element.accountNumber)
        {
          if(t->left == NULL)
          {
            t->left = n;
            return TRUE;
          }
          else
          {
            t = t->left;
          }
        }
        else
        {
          if(t->right == NULL)
            {
              t->right = n;
              return TRUE;
            }
            else
            {
              t = t->right;
            }
          }
        }
      }
  return FALSE;
  }


void printInOrder(BinarySearchTree tree)
{
    recursivePrintInOrder(tree->root);
}

void recursivePrintInOrder(NodeT* t)
{
  if(t == NULL )
  {
    return;
  }
  recursivePrintInOrder(t->left);
  printf("%d %.2lf \n", t->element.accountNumber, t->element.accountBalance);
  recursivePrintInOrder(t->right);
}

void printPreOrder(BinarySearchTree tree) 
{
    recursivePrintPreOrder(tree->root);
}

void recursivePrintPreOrder(NodeT* t)
{
  if(t == NULL ) 
  {
    return;
  }
  printf("%d %.2lf \n", t->element.accountNumber, t->element.accountBalance);
  recursivePrintPreOrder(t->left);
  recursivePrintPreOrder(t->right);
}
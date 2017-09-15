/*
 * @author Abdullah Alhassan
 * @version 1
 * @file binarysearchtree.cpp
 */

#include "binarysearchtree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree()
{
  mroot = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
  destroyTree(mroot);
}

bool BinarySearchTree::Search(const ItemType& theItem) const
{
  //search for theItem
  return lookup(mroot,theItem);
}

bool BinarySearchTree::lookup(Node* treeptr, const ItemType& theItem) const
{
  //base case
  if(treeptr == NULL)
    return false;

  //case 1
  //theItem equals to the node
  if(theItem == treeptr->mitem)
    return true;
  
  //case 2
  //theItem is lower than  the node
  else if(theItem < treeptr->mitem)
    return lookup(treeptr->mleftptr, theItem);

  //case 3
  //theItem is bigger than the node
  else 
    return lookup(treeptr->mrightptr, theItem);

  return false;
}

void BinarySearchTree::Insert(const ItemType& newItem)
{
  //call the helper function
  insertItem(mroot, newItem);
}


void BinarySearchTree::insertItem(Node* &treeptr, const ItemType& newItem)
{

  //base case, also checks if tree is empty
  if(treeptr == NULL){
    treeptr = new Node(newItem,NULL,NULL);
    return;
  }

  //case 1
  //theItem is lower than or equal to the node
  if(newItem <= treeptr->mitem)
    return insertItem(treeptr->mleftptr, newItem);
  
  //case 2
  //theItem is bigger than the node
  else
    return insertItem(treeptr->mrightptr, newItem);
}

Node* BinarySearchTree::FindMin() const
{
  return lookforMin(mroot);
}

Node* BinarySearchTree::lookforMin(Node* treeptr) const
{
  //The minimum value will be the most left node
  while(treeptr->mleftptr != NULL)
    treeptr = treeptr->mleftptr;  
  return treeptr;
}

Node* BinarySearchTree::FindMax() const
{
  return lookforMax(mroot);
}

Node* BinarySearchTree::lookforMax(Node* treeptr) const
{
  //The maximum value will be the most right node
  while(treeptr->mrightptr != NULL)
    treeptr = treeptr->mrightptr;  
  return treeptr;
}

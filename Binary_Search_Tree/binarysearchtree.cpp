/*
 * @author Abdullah Alhassan
 * @version 1
 * @file binarysearchtree.cpp
 */

// This file implemnets the BinarySearchTree class functions
// some cariable are used from the BinaryTree class

#include "binarysearchtree.h"
#include <iostream>

//constructor
BinarySearchTree::BinarySearchTree()
{
  mroot = NULL;
}
//Destructor
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

void BinarySearchTree::remove(const ItemType& theItem)
{
  removeItem(mroot,theItem);
}

void BinarySearchTree::removeItem(Node* &treeptr,const ItemType& theItem)
{
  //Empty Tree
  if(isEmpty()){
    cout << "Empty Tree!! \n";
    return;
  }
  
  //equal to the root node
  if(mroot->mitem == theItem){
    RemoveRootNode();
    return;
  }
  
  //search for the node
  
  //theItem is smaller than the node 
  if(theItem < treeptr->mitem && treeptr->mleftptr != NULL ){
    //check if matches the left child
    if(treeptr->mleftptr->mitem == theItem){
      RemoveMatch(treeptr,treeptr->mleftptr,true);
      
    } else{
      removeItem(treeptr->mleftptr, theItem); 
      
    }
  }
  //theItem is bigger than the 
  else if(theItem > treeptr->mitem && treeptr->mrightptr != NULL){
    //check if matches the right child
    if(treeptr->mrightptr->mitem == theItem)
      RemoveMatch(treeptr,treeptr->mrightptr,false);
    else
      removeItem(treeptr->mrightptr, theItem); 
  }
  //Base Case
  else
    cout << "the Item " << theItem << " was not found\n"; 
}

void BinarySearchTree::RemoveRootNode()
{
  //Empty Tree
  if(isEmpty()){
    cout << "Empty tree\n";
    return;
  }
  //To hold the value of the lowest item for match->righ
  int inorderSuccessor;
  
  //case 1
  // root node has 0 children
  if(mroot->mleftptr == NULL && mroot->mrightptr == NULL){
    mroot = NULL;
  }
  //case 2
  //root node has one child
  else if(mroot->mleftptr == NULL && mroot->mrightptr != NULL){
    Node* ptr = mroot;
    mroot = mroot->mrightptr;
    ptr->mrightptr = NULL;
    delete ptr;
    ptr = NULL;

  }
  else if(mroot->mleftptr != NULL && mroot->mrightptr == NULL){
    Node* ptr = mroot;
    mroot = mroot->mleftptr;
    ptr->mleftptr = NULL;
    delete ptr;
    ptr = NULL;

  }
  //case 3
  //root node has two children
  else{
    inorderSuccessor = lookforMin(mroot->mrightptr);
    removeItem(mroot,inorderSuccessor);
    mroot->mitem = inorderSuccessor;
  } 
}

void BinarySearchTree::RemoveMatch(Node* &parent, Node* &match, bool left)
{
  if(isEmpty()){
    cout << "empty tree!!\n";
    return;
  }

  Node* ptr = match;
  int inorderSuccessor;
  
  //case 1
  //has 0 children
  if(match->mleftptr == NULL && match->mrightptr == NULL){
    //ptr = match;
    if(left == true) 
      parent->mleftptr = NULL;
    else
      parent->mrightptr = NULL;
    delete ptr;
    ptr = NULL;
    return;
  }
  
  //case 2
  //has 1 child on the right
  else if(match->mleftptr == NULL && match->mrightptr != NULL){
    if(left == true)
      parent->mleftptr = match->mrightptr;
    else
      parent->mrightptr = match->mrightptr; 
    match->mrightptr = NULL;
    //ptr = match;
    delete ptr;
    ptr = NULL;
    return;
  }

  //has 1 child on the left
  else if(match->mleftptr != NULL && match->mrightptr == NULL){
    if(left == true)
      parent->mleftptr = match->mleftptr;
    else
      parent->mrightptr = match->mleftptr; 
    match->mleftptr = NULL;
    //ptr = match;
    delete ptr;
    ptr = NULL;
    return;
  }
  //case 3
  //has two children
  else{
    inorderSuccessor = lookforMin(match->mrightptr);
    removeItem(match,inorderSuccessor);
    match->mitem = inorderSuccessor;
    ptr = NULL;
    return;
  }
}

ItemType BinarySearchTree::FindMin() const
{
  return lookforMin(mroot);
}

ItemType BinarySearchTree::lookforMin(Node* treeptr) const
{
  while(treeptr->mleftptr != NULL)
    treeptr = treeptr->mleftptr;  
  return treeptr->mitem;
}

ItemType BinarySearchTree::FindMax() const
{
  return lookforMax(mroot);
}

ItemType BinarySearchTree::lookforMax(Node* treeptr) const
{
  while(treeptr->mrightptr != NULL)
    treeptr = treeptr->mrightptr;  
  return treeptr->mitem;
}

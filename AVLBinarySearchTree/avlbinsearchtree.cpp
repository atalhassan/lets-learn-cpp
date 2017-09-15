/*
 * @author Abdullah Alhassan
 * @version 1
 * @file avlbinsearchtree.cpp
 *
 * This class will be implemented based on AVL tree rules. That is
 * the tree have to be balanced after inserting a new item to the
 * tree. Keep in mind the height difference will alwayse be "Left - Right" 
 * so that if it produces a negative neumebr it will known that the Right
 * subtree is heavier than the left subtree.
 *
 */

#include "avlbinsearchtree.h"

//constructor
AVLBinSearchTree::AVLBinSearchTree()
{
  mroot = NULL;
}

//copy constructor
AVLBinSearchTree::AVLBinSearchTree(const AVLBinSearchTree& treeptr)
{
  copyTree(mroot, treeptr.mroot);
}

//copy constructor helper function
void AVLBinSearchTree::copyTree(Node* &newtreep, Node* oldtreep)
{
  if(oldtreep == NULL){
    newtreep = NULL;
    return;
  }

  newtreep = new Node(oldtreep->mitem,oldtreep->mheight,NULL,NULL);
  copyTree(newtreep->mleftptr, oldtreep->mleftptr);
  copyTree(newtreep->mrightptr, oldtreep->mrightptr);
}

//assignment operator of =
AVLBinSearchTree& AVLBinSearchTree::operator=(const AVLBinSearchTree& treeptr)
{
  copyTree(mroot, treeptr.mroot);
  return *this;
}

//destructor
AVLBinSearchTree::~AVLBinSearchTree()
{
  destroyTree(mroot);
}

void AVLBinSearchTree::destroyTree(Node* &treep)
{
  if(treep == NULL)
    return;

  destroyTree(treep->mleftptr);
  destroyTree(treep->mrightptr);
  delete treep;
  treep = NULL;
 
}


void AVLBinSearchTree::insert(const ItemType& newItem)
{
  insertItem(mroot, newItem);
}

void AVLBinSearchTree::insertItem(Node* &treeptr, const ItemType&  newItem)
{
  //Base case
  if(treeptr == NULL){
    treeptr = new Node(newItem, NULL, NULL);
    treeptr->mheight =  max( getHeight(treeptr->mleftptr), 
		       getHeight(treeptr->mrightptr) ) + 1;    
    return;
  }

  //case 1
  //theItem is lower than or equal to the node
  if(newItem <= treeptr->mitem){
    insertItem(treeptr->mleftptr, newItem);
  }
  //case 2
  //theItem is bigger than the node
  else
    insertItem(treeptr->mrightptr, newItem);
  
  //Update the height of the ancestors
  treeptr->mheight = max( getHeight(treeptr->mleftptr), 
			  getHeight(treeptr->mrightptr) ) + 1;

  //assign the balance factor
  int balanceFactor = getBalance(treeptr);

  //Left child is heavier
  if( balanceFactor > 1){
    
    int balanceFactorLeft = getBalance(treeptr->mleftptr);
    
    //Left Left rotation
    if(balanceFactorLeft > 0){
      treeptr = rotateLeft(treeptr); 
      return;
    //Left Right rotation
    } else {
      treeptr = rotateLeftRight(treeptr);
      return;
    }
  }

  //Right child is heavier
  if( balanceFactor < -1){
    
    int balanceFactorRight = getBalance(treeptr->mrightptr);
    
    //Right Left rotation
    if(balanceFactorRight > 0){
      treeptr = rotateRightLeft(treeptr);
      return;
    //Right Right rotation
    }else{
    treeptr = rotateRight(treeptr);  
    return;
    }
  }
}

ItemType AVLBinSearchTree::max(const ItemType h1, const ItemType h2)
{
  if(h1 > h2)
    return h1;
  //it does not make difference if they are equal
  return h2;
}

ItemType AVLBinSearchTree::getHeight(const Node* ptr) const
{
  if(ptr == NULL)
    return 0;
  return ptr->mheight;
}

ItemType AVLBinSearchTree::getBalance(Node* treeptr)
{
  //  if(treeptr == NULL)
  //return 0;
  //left tree height minus right tree height, if the result was negative
  //it means that the left tree is heavier, otherwise left tree is heavier
  int h1 = getHeight(treeptr->mleftptr);
  int h2 = getHeight(treeptr->mrightptr);
  int diff = h1 - h2;
  return diff;
}

//rotatoin functions

Node* AVLBinSearchTree::rotateLeft(Node* k2)
{
  Node* k1 = k2->mleftptr;
  k2->mleftptr = k1->mrightptr;
  k1->mrightptr = k2;

  //update the height start with the child
  k2->mheight = max(getHeight(k2->mleftptr), getHeight(k2->mrightptr)) + 1;
  k1->mheight = max(getHeight(k1->mleftptr), getHeight(k1->mrightptr)) + 1;
  
  return k1;

}

Node* AVLBinSearchTree::rotateRight(Node* k1)
{
  Node* k2 = k1->mrightptr;
  k1->mrightptr = k2->mleftptr;
  k2->mleftptr = k1;

  //update the height start with the child
  k1->mheight = max(getHeight(k1->mleftptr), getHeight(k1->mrightptr)) + 1;
  k2->mheight = max(getHeight(k2->mleftptr), getHeight(k2->mrightptr)) + 1;  
  
  return k2;
}

Node* AVLBinSearchTree::rotateLeftRight(Node* k3)
{
  Node* k1 = k3->mleftptr;
  k3->mleftptr = rotateRight(k1);
  return rotateLeft(k3);
}

Node* AVLBinSearchTree::rotateRightLeft(Node* k3)
{
  Node* k2 = k3->mrightptr;
  k3->mrightptr = rotateLeft(k2);
  return rotateRight(k3);
}


void AVLBinSearchTree::printTest()
{
  print(mroot);
}

void AVLBinSearchTree::print(Node* treeptr) const
{
  if(treeptr == NULL){
    return;
  }
  //print
  std::cout << "Key: " << treeptr->mitem << ", \t" << "height: " 
	    << treeptr->mheight << std::endl;
  //go left
  print(treeptr->mleftptr);
  //go right
  print(treeptr->mrightptr);
}


/*                                       
 * @author Abdullah Alhassan
 * @version 1
 * @file binarytree.cpp
 */

// An implemntation file for binarytree.h
// This file will implement all the functions
// that are in the header file.


#include"binarytree.h"
#include<iostream>

//The constructor will set all pointer variables to NULL
BinaryTree::BinaryTree()
{
  mroot = NULL;
}

BinaryTree::BinaryTree(const ItemType& rootItem) 
{
  mroot = new Node(rootItem,NULL,NULL);
}

BinaryTree::BinaryTree(const ItemType& rootItem,BinaryTree& leftTree, BinaryTree& rightTree)
{
  mroot = new Node(rootItem, leftTree.mroot, rightTree.mroot);  
}

//copy constructor
BinaryTree::BinaryTree(const BinaryTree& rhstree)
{
  copyTree(mroot,rhstree.mroot);
}

void BinaryTree::copyTree(Node* &newtreep, Node* oldtreep)
{
  if(oldtreep == NULL){
    newtreep = NULL;
    return;
  }
   
  newtreep = new Node(oldtreep->mitem,NULL,NULL);
  copyTree(newtreep->mleftptr, oldtreep->mleftptr);
  copyTree(newtreep->mrightptr, oldtreep->mrightptr);
}

//Distructor
BinaryTree::~BinaryTree()
{
  destroyTree(mroot);
}

void BinaryTree::destroyTree(Node* &treep)
{
  if(treep == NULL)
    return;

  destroyTree(treep->mleftptr);
  destroyTree(treep->mrightptr);
  delete treep;
  treep = NULL;
 
}

bool BinaryTree::isEmpty() const
{
  return mroot == NULL;
}

/****************Traverse Functions**************/

void BinaryTree::preorderTraverse() const
{
  preorder(mroot);
}

void BinaryTree::preorder(Node* treep) const
{
  if(treep == NULL)
    return;

  cout << treep->mitem << "  ";

  preorder(treep->mleftptr);
  preorder(treep->mrightptr);
  
}

void BinaryTree::inorderTraverse() const
{
  inorder(mroot);
}

void BinaryTree::inorder(Node* treep) const
{
  if(treep == NULL)
    return;
  
  inorder(treep->mleftptr);

  cout << treep->mitem<< "  ";

  inorder(treep->mrightptr);
}

void BinaryTree::postorderTraverse() const
{
  postorder(mroot);
}

void BinaryTree::postorder(Node* treep) const
{
  if(treep == NULL)
    return;
  
   postorder(treep->mleftptr);
   postorder(treep->mrightptr);
   
   cout << treep->mitem<< "  ";
}


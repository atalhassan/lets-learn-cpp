/*
 * @author Abdullah Alhassan
 * @version 1
 * @file node.cpp
 *
 * This file is an implementation file of the node class
 */

#include "node.h"

//default constructor
Node::Node()
{
  mleftptr = NULL;
  mrightptr = NULL;
  mheight = 1;
}

//overloaded constructor for the insert function in AVLBinSearchTree
Node::Node(const ItemType& nodeItem, Node* left, Node* right)
{
  mleftptr = left;
  mrightptr = right;
  mitem = nodeItem;
  mheight = 1;
}

//overloaded constructor for the copy cnstructor and the assignment operator
Node::Node(const ItemType& nodeItem, const ItemType& nodeHeight, Node* left, Node* right)
{
  mleftptr = left;
  mrightptr = right;
  mitem = nodeItem;
  mheight = nodeHeight;
}

/*
 * @author Abdullah Alhassan
 * @version 1
 * @file node.h
 *
 * This class is constructed for the AVLBinSearchTree uses
 * and there are three type of constructors each will serve 
 * a function in the AVLBinSearchTree.
 * 
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

typedef int ItemType;

class Node{

 private:

  //@post This constructor will construct a pointer that has two NULL children
  //      and height of 1
  //@usage Default constructor that will be used to construc the root node
  //       and any other parameter static nodes
  Node();
  //@pre The newItem variable is assigned as an ItemTyp, and the two children
  //     are also assigned as a pointer
  //@post This constructor will create pointer with a certain item
  //      specified by the client, and two children also specified
  //      by the client. The height of the tree will be set to 1.
  //@param 
  //  newItem: an int type that will be the value of the node
  //  left: a pointer which is the left child of the node
  //  right: a pointer which is the left child of the node 
  //@usage This constructor will be used by the insert function
  //       since it need to create a new node with certain data)
  Node( const ItemType& nodeItem, Node* left, Node* right);

  //@pre The newItem and the mheight variable is assigned as an ItemTyp,
  //     and the two children
  //     are also assigned as a pointer, 
  //@post This constructor will create pointer with a certain item
  //      specified by the client, and two children also specified
  //      by the client. The height of the tree will be set to 1.
  //@param 
  //  newItem: an int type that will be the value of the node
  //  left: a pointer which is the left child of the node
  //  right: a pointer which is the left child of the node 
  //  height: an int type that will be the height of the node
  //@usage This constructor will be used by the copy constructor
  //       and the assignment operator since the copy should
  //       contain all the information of the tree nodes
  Node( const ItemType& nodeItem, const ItemType& nodeHeight, Node* left,
            Node* right);
  

  //Node varaibles that will help construct the AVLBinSearchTree
  Node* mleftptr;
  Node* mrightptr;
  ItemType mitem;
  ItemType mheight;
  
  //granting access to AVLBinSearchTree class to the private members of this calss.
  friend class AVLBinSearchTree;
  
};
#endif

/* 
 * @author Abdullah Alhassan
 * @version 1
 * @file avlbinsearch.h
 *
 *       This AVLBinSearchTree is a type of Binary Search Tree.
 *       The AVL Tree has more feature than a normal BST, the main
 *       idea in this is to get it balanced. In other word, the height
 *       difference between any two child node is not bigger than 1,
 *       given that initialy the root node alone has a height of 1.
 *       To make the comparision between the height of subtrees, I 
 *       made a convention that the height difference will always be 
 *       "Left - Right" so that when it produce a negative number it
 *       means that the Right subtree is heavier and vice versa.
 *       Therefor, the range of error would be when h > 1 or h < -1.
 */

#ifndef AVLBINSEARCHTREE_H
#define AVLBINSEARCHTREE_H

#include "node.h"

class AVLBinSearchTree
{
 public:
 
  AVLBinSearchTree();
  
  AVLBinSearchTree(const AVLBinSearchTree& treeptr);

  ~AVLBinSearchTree();

  AVLBinSearchTree& operator=(const AVLBinSearchTree& treeptr);
 
  //@pre The newItem variable is assigned as an ItemType
  //@post The AVL Tree will have one more node, also the tree will 
  //      restructured based on the height differnce
  //@param 
  //  newItem: an int type that will be the value of the tree 
  //@usage This function will be called by a client, then it will 
  //       call a protected member that have access to the root node
  void insert(const ItemType& newItem);
  

   //@pre the tree is not empty
  //@post Printing the items of the tree followed by their heights
  //@usage This function will be called by a client, to demonstrate 
  //       the item and heights of the tree. The printing method
  //       follows a preorder trversal, which means the root will be
  //       the first item.
  void printTest();

 protected:
  
  //@pre The treeptr is assigned as the root node
  //@post The AVL Tree will have one more node, also the tree will 
  //      restructured based on the height differnce. In other word,
  //      the tree will be balanced.
  //@param 
  //  newItem: An int type that will be the value of the tree node.
  //  treeptr: Assigned as the root node and passed by refrence so
  //           that any changes actually apply to the actual root node
  //@usage It is a recursive function that will be called by the insert
  //       function, then it will add the newItem using recursion. As
  //       the recursion gets backward the function will balance the tree.
  void insertItem(Node* &treeptr, const ItemType& newItem);

 
  //@pre  The assinged variable has is an int
  //@post These helped function will return the values
  //      of an important variables that will determine
  //      the structure of the tree
  //@param 
  //  h1, h2: are an int variables that represents the height of node1 and node2
  //  ptr: is the node whose height will be determined using the max function
  //  treeptr: is the node that its function will acces the children of the node
  //           to determide the balance factor.
  //@usage helper funcitons that are used to orgnize the process. 
  ItemType max(const ItemType h1, const ItemType h2);
  ItemType getHeight(const Node* ptr) const;
  ItemType getBalance(Node* treeptr);


  //@pre The treeptr is assigned as the root node
  //@post The items and heights of the AVL tree will be printed 
  //      put in the preorder form.
  //@param 
  //  treeptr: Assigned as the root node and passed by copy so it does not change.
  //@usage It is a recursive function that will be called by the printTree
  //       function.
  void print(Node* treeptr) const;

  //@pre The parameters are assigned as the root node.
  //@post destroy the tree using recursion and the postorder forem.
  //@param 
  //  treep: Assigned as the root node and passed by refrence to del the actual node. 
  //@usage It is a recursive function that will be called by the destructor.
  void destroyTree(Node* &treep);

  //@pre The parameters are assigned as the root node.
  //@post Construct a deep copy of the tree using recursion and the preorder form.
  //@param 
  //  newtreep: Assigned as the root node and passed by refrence to copy the actual node. 
  //@usage It is a recursive function that will be called by the copy constructo.
  void copyTree(Node* &newtreep, Node* oldtreep);

    

  //@pre Not emtpy tree
  //@post Restructure the tree so that it is balnced according AVL form.
  //@param 
  //   k1, k2, k3: are nodes that will be assigned to the proper treeptr to 
  //               to reconstruct the shape of the tree.
  //@usage They are helper functions that will be called by the inserItem funciton
  //       it based on the situation of the tree structure one of the those four function
  //       will be called to balance the tree.
  Node* rotateLeft(Node* k2);
  Node* rotateRight(Node* k1);
  Node* rotateLeftRight(Node* k3);
  Node* rotateRightLeft(Node* k3);
  
  //The root of thr tree
  Node* mroot;

};
#endif

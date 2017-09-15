/*
 * @author Abdullah Alhassan
 * @version 1
 * @file ListNode.h 
 */

#ifndef _LISTNODE
#define _LISTNODE

typedef int ItemType;

class ListNode
{
 public:
  //return item
  ItemType getItem();
  //return next
  ListNode* getNext();
  //constructor
  ListNode();
  //overloaded constructor
  ListNode(const ItemType & x);
  //overloaded constructor
  ListNode(const ItemType & x, ListNode* nNode);

  //Link to the next node
  void setNext(ListNode* nNode);
  //set an item to the node
  void setItem(const ItemType & x);
  //destructor
  ~ListNode();

 private :
  ItemType item; // A data item
  ListNode* next; // Pointer to next node
  friend class ListP;
}; // end Node

#endif

/*
 * @author Abdullah Alhassan
 * @version 1
 * @file ListP.h 
 */


#include <iostream> 
#include "ListNode.h"


#ifndef _LISTP
#define _LISTP
using namespace std;

class ListP
{
 public:
  //constructor
  ListP();
  ListP(const ListP & l); // copy constructor
  //destructor
  ~ListP();
  //check if the list is empty by checking the size
  bool isEmpty() const;
  //return the size of the list
  int getSize() const;  
  //add a node to the list to any position between Size and 0
  void insert(int pos, const ItemType & x); // insert the new item x into the position "pos"
  //remove a node from the list from any position between (Size-1) and 0
  void remove(int pos);// remove the item at the position "pos"
  //display the item in the list (array base)
  void display(); // for debugging purpose, print out the list
  //set the head of the list to new head of a sorted list
  void sort_mergesort();
 
 private:
  int size; // how many items in the list
  //the top of the list
  ListNode* head;
  /* Recursion function that
   * split until eaxh part of the list contain one node
   * merge backward using the merge function
   */
  ListNode* mergesort(ListNode* begin, int lsize);
  //takes two head and merge them based on their item size; in an ascending order
  ListNode* merge(ListNode* list1, ListNode* list2);
};

#endif

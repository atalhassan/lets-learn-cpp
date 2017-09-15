/*
 * @author Abdullah Alhassan
 * @version 1
 * @file ListNode.cpp 
 */

#include "ListNode.h"
#include <iostream>

//constructor
ListNode::ListNode()
{
  item = 0;
  next = NULL;
}
//overloaded constructor
ListNode::ListNode(const ItemType & x)
{
  item = x;
  next = NULL;
}
//overloaded constructor
ListNode::ListNode(const ItemType & x, ListNode* nNode)
{
  item = x;
  next = nNode;
}

//destructor
ListNode::~ListNode()
{
  next = NULL; 
  delete next;
}

void ListNode::setNext(ListNode* nNode)
{
  next = nNode;
}

void ListNode::setItem(const ItemType & x)
{
  item = x;
}

ItemType ListNode::getItem()
{
  return item;
}

ListNode* ListNode::getNext()
{
  return next;
}

/*
 * @author Abdullah Alhassan
 * @version 1
 * @file ListP.cpp 
 */

#include"ListP.h"
#include <iostream>
#include <string>

//Constructor
ListP::ListP()
{
  size = 0;
  head = NULL;
}

//Copy Constructor
ListP::ListP(const ListP& l)
{
  head = NULL;
  size = 0;
  ListNode* ptr = l.head;
  int n = 0;
  while(ptr->next != NULL){
    insert(n,ptr->getItem());
    ptr = ptr->next;
    n++;
  }
  insert(n, ptr->getItem());
  ptr = ptr->next;
  delete ptr;
 }

//Destructor
ListP::~ListP()
{
  //one item in the list
  if(head->next == NULL){
    head = NULL;
  }
  //multiple items in the list
  else{
    while(head != NULL)
      head = head->next;
  }
  delete head;
}

bool ListP::isEmpty() const
{
  return size == 0;
}

int ListP::getSize() const
{
  return size;
}

void ListP::insert(int pos, const ItemType & x)
{
  //check the validity of the pos required
  if(pos > size || pos < 0){
    std::cout << "Invalid Positoin please try again!!"
	      << " (choose position between 0 - "
	      << size << ")";
    return;
  }

  //initialize a node with item x
  ListNode* ptr = new ListNode(x);

  //empty list
  if(isEmpty()){
    head = ptr;
    head->next = NULL;
    size++;
    return;

  //insert into the front of the list
  } else if(pos == 0){
    ptr->next = head;
    head = ptr;
    size++;
    return;

  //insert into the middle of the list
  } else {
   ListNode* ptr2 = head;
   for(int i = 0; i < (pos-1); i++)
      ptr2 = ptr2->next;
   ptr->next = ptr2->next;
   ptr2->next = ptr;
  }
  size++;
}

void ListP::remove(int pos)
{
  //empty list
  if(isEmpty()){
    std::cout << "Empty list!";
    return;
  }
  //check the validity of the pos
  if(pos > (size-1) || pos < 0){
    std::cout << "Invalid Positoin please try again!!"
	      << " (choose position between 0 - "
	      << (size-1) << ")";
    return;
  }

  //one item in the list 
  if(size == 1){
    delete head;
    size--;
    return;
  }

  //initlize an iterator pointer to head
  ListNode* ptr = head;

  //delete the first item
  if(pos == 0){
    head = head->next;
    delete ptr;
    size--;
    return;
  }
  //delete middle item
  for(int i = 0; i < (pos-1); i++)
    ptr = ptr->next;
  ListNode* ptr2 = ptr->next;;
  //  ptr2 = ptr2->next;
  ptr->next = ptr2->next;
  delete ptr2;
  size--;
}

void ListP::display()
{
  //empty list
  if(isEmpty()){
    std::cout <<"Empty List!!";
    return;
  }
  //new array with size as the size of ListP
  int ListDisplay[size];
  //iterator pointer to head
  ListNode* ptr = head;
  for(int i = 0; i < size; i++){
    ListDisplay[i] = ptr->getItem();
    ptr = ptr->next;
  }

  //display the array
  std::cout << "{";
  for(int i = 0; i < (size-1); i++)
    std::cout << ListDisplay[i] << ", ";
  
  std::cout << ListDisplay[size-1] << "}";
}

void ListP::sort_mergesort()
{
  //set the head to the new head in the sorted list
  head = mergesort(head, size);
}

ListNode* ListP::mergesort(ListNode* begin, int lsize)
{
  //empty list
  if(begin == NULL)
    return begin;
  //bese case
  if(begin->next == NULL)
    return begin;
  //Split  
  int midPos = lsize/2;
  int size1 = midPos;
  int size2 = lsize - midPos;
  ListNode* ptr = begin;
  for(int i = 0; i < (midPos-1); i++)
    ptr = ptr->next;
  ListNode* head2 = ptr->next;
  ptr->next = NULL;
 
  //mergeSort
  begin =  mergesort(begin, size1);
  head2 = mergesort(head2, size2);
 
  //merge
  return merge(begin, head2);
}

ListNode* ListP::merge(ListNode* list1, ListNode* list2)
{
  //base case
  if(list1 == NULL)
    return list2;
  else if(list2 == NULL)
    return list1;
  
  //sort in an ascending order and return the proper head
  if(list1->item < list2->item){
    list1->next = merge(list1->next, list2);
    return list1;
  } else{
    list2->next = merge(list1, list2->next);
    return list2;
  }
}

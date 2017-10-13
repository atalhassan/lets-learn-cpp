/*@author  Abdullah Alhassan
 *@version 1
 *@file    stack.cpp
 */
#include <iostream>
#include "stack.h"
#include <string>
#include <stdlib.h>
#include <time.h>

//set the member variables
//-1 means empty stack
Stack::Stack()
{
  length = -1;
  head = NULL;
}
//Destructor
Stack:: ~Stack()
{
  delete_list();
}
//Copy constructor
Stack::Stack(const Stack& other)
{
  length = other.length;  
  head = other.head;
}
//Assignment operator
Stack& Stack::operator= (const Stack& other)
{ 
  length = other.length;
  head = other.head;
  return *this;
}
//push function
void Stack::push(const Card& a_card)
{
  Node * ptr = new Node;
  ptr->value = a_card;
  ptr->next = head;
  head = ptr;
  length++;
}
//pop function
bool Stack::pop()
{  
  if(is_empty()) 
    return false;
  Node* ptr = new Node;
  ptr = head;
  head = head->next;
  length--; 
  delete ptr;
  return true;
}
//peek function
bool Stack::peek(Card& a_card) const
{
  if(is_empty())
    return false;
  a_card = head->value;
  return true;
}

int Stack::size() const
{
  return length + 1;
}

bool Stack::is_empty() const
{
  return size() == 0;
}

void Stack::shuffle()
{
  //convert the linked list into array
  int n = size();
  Card* items = new Card[n];
  for (int i = 0; i < n; i++) {
    peek(items[i]);
    pop(); 
  }
  //deleter linked list  
  delete_list();
  
  //shuffling by swaping elements from the stack
  srand(time(NULL));
  for (int i = 0; i < n ; i++) {
    int swap_index = rand() % size();
    Card tmp = items[i];
    items[i] = items[swap_index];
    items[swap_index] = tmp; 
  }
  //rebuild linked list
  for (int i = 0; i < n; i++) {
    Node * ptr = new Node;
    ptr->value = items[i];
    ptr->next = head;
    head = ptr;
    length++; 
  }
  //deleter pointer array
  delete [] items;
}

void Stack::add_to_bottom(Stack& a_stack)
{
  Stack tmp;
  // copy this stack onto tmp
  int len = size();
  for (int i = 0; i < len; i++) {
    Card elem;
    peek(elem);
    tmp.push(elem);
    pop();
  }
  
  len = a_stack.size();
  // copy a_stack_copy onto tmp
  for (int i = 0; i < len; i++) {
    Card elem;
    a_stack.peek(elem);
    tmp.push(elem);
    a_stack.pop();
  }

  // copy tmp stack to this stack
  len = tmp.size();
  for (int i = 0; i < len; i++) {
    Card elem;
    tmp.peek(elem);
    push(elem);
    tmp.pop();
  }
}

std::string Stack::to_string() const
{
  std::string name = "";
  Card tmp;
  Node* ptr = head;
  while(ptr != NULL){
    if (ptr->next == NULL){
      tmp = ptr->value;
      name = tmp.to_string() +" "+ name;
    } else {
      tmp = ptr->value;
      name = tmp.to_string() + " " + name;
    }
    ptr = ptr->next;
  }
  //if no cards
  if(name == "")
    std::cout<<"No Cards!!";
  return name;
}

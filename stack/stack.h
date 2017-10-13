/*@author  Abdullah Alhassan
 *@version 1
 *@file    stack.h
 */
#ifndef STACK_H
#define STACK_H
#include "card.h"
#include <string>

const int MIN_SIZE = 2;

class Stack {
 public:
  Stack();
  //In destructor the stack_array will be deleted
  ~Stack();
  //Copy Constructor
  Stack(const Stack& other);
  //Assignment Operator to =
  Stack& operator= (const Stack& other);
  //Post: add a_card to the stack
  void push(const Card& a_card);
  //Pre: stack_array content is not empty
  //Post: remove a_card from the stack
  //Result: if true length will be decremented by 1,
  bool pop();
  //Post: set the top card in the stack to  a_card
  bool peek(Card& a_card) const;
  //Result: return the size of the elements in the stack
  int size() const;
  //Pre: size is 0
  //Result: true if Pre is fullfilled, flase otherwise.
  bool is_empty() const;
  //change the order of the stack
  void shuffle();
  //add new cards to the bottom of the stack
  void add_to_bottom(Stack& a_stack);
  //Result: a string represintation of the cards
  std::string to_string() const;
 private:
  // helper function that will deleter the linked list
  void delete_list() {
    while(head != NULL) {
      Node* ptr = head;
      head = head->next;
      delete ptr;
    }
  }
  // constructing the Node
  struct Node {
    Card value;
    Node * next;
  } * head;
  int length;
};
#endif

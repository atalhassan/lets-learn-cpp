/* This program was implemented to make sure that 
 * the functions in stack.h and stack.cpp are 
 * complete and correct.
 *
 * @author   Abdullah Alhassan
 * @version  1
 * @file     test.cpp
 *
 */
#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

int main() 
{
  //DECK_SIZE is 52 from card.h 
  Card cards[DECK_SIZE];
  //intialize cards
  int total = 0;
  for(int i = 0; i <= 3 && total < DECK_SIZE; i++) 
    for(int j = 0; j <= 12 && total < DECK_SIZE; j++){
      cards[i * 13 + j].set_suit(i + 1);
      cards[i * 13 + j].set_rank(j + 1);
      ++total;
    }
  //check Constructor and initial size
  Stack s1;
  cout << "\ns1 Stack object was Constructed \n"
       << "Cards on Stack: " << s1.size() << endl << endl;
 
  //check push function and to_string
  for(int i = 0; i < 5; i++)
    s1.push(cards[i]);
  cout << "s1 pushed 5 cards\n"
       << "Cards on Stack: " << s1.size() << endl
       << s1.to_string() << endl << endl;
  
  //check copy constructor
  Stack s2(s1);
  cout << "s2 Stack object was copied using Copy Constructor\n"
       << "Cards on Stack: " << s2.size() << endl
       << s2.to_string() << endl << endl;

  for(int i = 5; i < 7; i++)
    s2.push(cards[i]);
  cout << "s2 pushed 3 more cards:\n"
       << "Cards on stack: " << s2.size() << endl
       << s2.to_string() << endl << endl; 

  //check assignment operator
  Stack s3;
  s3 = s2;
  cout << "s3 Stack object was assigned using Assignment Operator (=)\n"
       << "Cards on stack: " << s3.size() << endl
       << s3.to_string() << endl << endl;       

  //check peek function and that s1 has not change
  Card tmp;
  s1.peek(tmp);
  cout << "A tmp card peeked on the top card of s1\n"
       << tmp.to_string() << endl << endl;
  
  //check pop funciton
  for(int i = 0; i < 5; i++)
    s2.pop();
  cout << "s2 popped 5 cards \n"
       << "Cards on stack: " << s2.size() << endl
       << s2.to_string() << endl;       

  for(int i = 0; i < 5; i++)
    s1.pop();
  cout << "s1 popped 5 cards \n"
       << "Cards on stack: " << s1.size() << endl
       << s1.to_string() << endl << endl;       
  
  for(int i = 0; i < 6; i++)
    s3.pop();
  cout << "s3 popped 6 cards \n"
       << "Cards on stack: " << s3.size() << endl
       << s3.to_string() << endl << endl;       
  

  //the return will destruct all of the stacks
  cout << "s1, s2, and s3 will be destructed by" 
       << " the Destructor when return launched \n\n";
  
  return 0;
}

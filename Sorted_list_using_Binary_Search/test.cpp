/* This program was implemented to make sure that 
 * the functions in card.h and sortedlist.h are complete and correct.
 *
 * @author   Abdullah Alhassan
 * @version  1
 * @file     test.cpp
 */
#include <iostream>
#include "sortedlist.h"
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
  SortedList s1;
  cout << "\ns1 List object was Constructed \n"
       << "Cards on List: " << s1.size() << endl << endl;

  //check add function and to_string
  for(int i = 0; i < 5; i++)
    s1.add(cards[i]);
  cout << "s1 inserted 5 cards\n"
       << "Cards on List: " << s1.size() << endl
       << s1.to_string() << endl << endl;
  
  //check remove function and to_string
  for(int i = 0; i < 2; i++)
    s1.remove(cards[i]);
  cout << "s1 removed 2 cards\n"
       << "Cards on List: " << s1.size() << endl
       << s1.to_string() << endl << endl;
  
  //check the equality in card.h
  if(cards[2] > cards[1])
    cout << "the second card is greater than the first card\n";
  if(cards[1] == cards[1])
    cout << "the first card is equal to the first card\n\n";

 return 0;
}

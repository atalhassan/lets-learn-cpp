/* This program prompt the user for a number of cards, 
 * and sort it form lower to larger, then it asks if
 * the user would like to iterate through the list 
 * of cards. or remove some cards from the list
 *
 * @author   Abdullah Alhassan
 * @version  1
 * @file     main.cpp
 */
#include <iostream>
#include "sortedlist.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

void initiallize_cards(int cards, SortedList& deck); 

int main() 
{

  cout << "-------------------------\n";
  cout << " Sorted List\n";
  cout << "-------------------------\n\n";

  //prompt the user for number of cards
  int num_of_cards = 0;
  cout <<" Enter number of cards (1-100): ";
  cin >> num_of_cards;

  //checking valid number
  while(num_of_cards > 100 || num_of_cards < 1){
    cout<< "Invalid number please enter a number between 1 - 100 \n";
    cin >> num_of_cards;
  }
    
  cout << endl;
  
  //create the list  
  SortedList deck;
  initiallize_cards(num_of_cards, deck);
  //print the cards
  cout <<"Sorted Cards: ";
  cout << deck.to_string() << endl;
  cout << endl << endl;
  char quit;

  //play
  while(quit != 'q')
    {
      int rank;
      int suit;
      Card tmp;
      char action;
      cout << "Select action (s=search, r=remove, q=quit): ";
      cin >> action;
      //search
      if(action == 's'){
	cout << "Rank of card to search for (1-13): ";
	cin >> rank;
	cout << "Suit of card to search for (1-4): ";
	cin >> suit;
	tmp.set_suit(suit);
	tmp.set_rank(rank);  
	if(deck.contains(tmp))
	  cout << "The card " << tmp.to_string() 
	       <<" is IN the list of cards. \n\n";
	else
	  cout << "The card " << tmp.to_string() 
		<<" is NOT IN the list of cards. \n\n";
	//remove
      } else if( action == 'r') {
	cout << "Rank of card to search for (1-13): ";
	cin >> rank;
	cout << "Suit of card to search for (1-4): ";
	cin >> suit;
	tmp.set_suit(suit);
	tmp.set_rank(rank);  
	if(deck.remove(tmp))	  
	  cout << "New cards:" << deck.to_string() << endl << endl; 
	else
	  cout << "The card " << tmp.to_string() 
	       <<" is NOT IN the list of cards to remove. \n\n";
	//quit
      } else if(action == 'q')
	quit = action;
    }
  return 0;
}

void initiallize_cards(const int cards, SortedList& deck)
{
  //seed time
  srand(time(NULL));
  
  Card* card_deck= new Card[cards];
  //intialize cards
  for(int i = 0; i < cards; i++) {
    card_deck[i].set_rank((rand() % 4)+1);
    card_deck[i].set_suit((rand() % 13)+1);
  }
  for(int i = 0; i < cards; i++)
    deck.add(card_deck[i]);  
  }

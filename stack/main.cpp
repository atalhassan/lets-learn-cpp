/* This program is a slapjack game where there is
 * a deck of cards that distrubutes to two players equally.
 * Each player play one card, if the card was Jack, then
 * the program will randomly choose  who will slap the jack
 *
 * @author  Abdullah Alhassan
 * @version 1
 * @file    main.cpp
 */
#include <iostream>
#include "stack.h"
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;
//Pre: number of cards added < DECK_SIZE (52)
//Post: add cards to the stack 
void initialize_deck(Stack& deck);
//take a card from the hand and 
//add it to the pot 
Card play(Stack& hand, Stack& pot);

int main()
{
  Stack deck;

  //seed the genrator
  srand(time(NULL));

  //intilize the deck
  initialize_deck(deck);
  
  //shuffle the deck  
  deck.shuffle();

  //create two players
  Stack p1_hand;
  Stack p2_hand;

  //deal the cards
  Card tmp;
  for(int i = 0; i < 26; i++) {
    deck.peek(tmp);
    p1_hand.push(tmp);
    deck.pop();
    deck.peek(tmp);
    p2_hand.push(tmp);
    deck.pop();
  }

  bool game_over = false;
  bool p1_turn = true;
  Stack pot;

  cout << "--------------------" << endl;
  cout << "Welcome to Slapjack!" << endl;
  cout << "--------------------" << endl << endl;

  //The game will keep looping until one hand 
  //run out of cards
  while(!game_over) {
    Card ground;

    if(p1_turn) {
      ground = play(p1_hand, pot);
      cout << "P1(" << p1_hand.size() << "): "
	   << ground.to_string() << "\tPot: ";
      cout << "[";
      cout << pot.to_string();
      cout << "]" << endl;      
    } else {
      ground = play(p2_hand, pot);
      cout << "P2(" << p2_hand.size() << "): "
	   << ground.to_string() << "\tPot: ";
      cout << "[";
      cout << pot.to_string();
      cout << "]" << endl;
    }

    //Pre: ground is jack
    //Post: add the pot to a player
    if(ground.is_jack()) {
      pot.shuffle();
      if( rand() % 2 == 0) {
	p1_hand.add_to_bottom(pot);
	cout << "*** P1 won the pot! ***" << endl;
      } else {
	p2_hand.add_to_bottom(pot);
	cout << "*** P2 won the pot! ***" << endl;
      }
    }
    
    //switch players
    p1_turn = !p1_turn;
    
    //Pre: a hand length is 0
    //Post: other hand win the game
    if(p1_hand.size() < 1) {
      cout << "*** P2 wins! ***" << endl;
      game_over = true;
    } else if (p2_hand.size() < 1) {
      cout << "*** P1 wins! ***" << endl;
      game_over = true;
    }
  }

  return 0;
  }

void initialize_deck(Stack& deck)
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
  //push cards to the deck stack
  for(int i = 0; i < DECK_SIZE; i++) 
    deck.push(cards[i]);
}

Card play(Stack& hand, Stack& pot)
{
  Card play_card;
  hand.peek(play_card);
  hand.pop();
  pot.push(play_card);
  
  return play_card;
}

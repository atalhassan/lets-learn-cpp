/*@author  Abdullah Alhassan
 *@version 1
 *@file    card.cpp
 */
#include <string>
#include <cstdio>
#include "card.h"

// default is ace of spades
Card::Card() : suit(1), rank(1)
{
}
//change suit value
void Card::set_suit(int the_suit)
{
  if (the_suit >= 1 && the_suit <= 4)
    suit = the_suit;
}
//change rank value
void Card::set_rank(int the_rank)
{
  if (the_rank >= 1 && the_rank <= 13)
    rank = the_rank;
}

bool Card::is_spade() 
{
  return suit == 1;
}

bool Card::is_heart()
{
  return suit == 2;
}

bool Card::is_diamond()
{
  return suit == 3;
}

bool Card::is_club()
{
  return suit == 4;
}

bool Card::is_ace()
{
  return rank == 1;
}

bool Card::is_jack()
{
  return rank == 11;
}

bool Card::is_queen()
{
  return rank == 12;
}

bool Card::is_king()
{
  return rank == 13;
}

int Card::get_rank()
{
  return rank;
}

std::string Card::to_string() 
{
  std::string name = "";
  // confirm the correct rank value
  if (is_ace())
    name += "A";
  else if (is_jack())
    name += "J";
  else if (is_queen())
    name += "Q";
  else if (is_king())
    name += "K";
  else {
    //convert int to string
    char buffer[3];
    sprintf(buffer, "%d", get_rank());
    name += buffer;
  }
  // combine the suit
  if (is_spade())
    name += "S";
  else if(is_heart())
    name += "H";
  else if(is_diamond())
    name += "D";
  else
    name += "C";
  
  return name;
}

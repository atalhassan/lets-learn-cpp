/* @author   Abdullah Alhassan
 * @version  1
 * @file     card.h
 */
#ifndef CARD_H
#define CARD_H
#include <string>

const int DECK_SIZE = 52;

class Card {
 public:
  Card();
  /* Pre: the_suit should be between 1-4.
   * Post: set suit to the_suit.
   */
  void set_suit(int the_suit);
  /* Pre: the_rank should be between 1-13.
   * Post: set rnak to the_rank.
   */
  void set_rank(int the_rank);
  /* Pre: suit = 1.
   * Result: true if suit is 1, false otherwise
   */
  bool is_spade();
  /* Pre: suit = 2.
   * Result: true if suit is 2, false otherwise
   */
  bool is_heart();
  /* Pre: suit = 3.
   * Result: true if suit is 3, false otherwise
   */
  bool is_diamond();
  /* Pre: suit = 4.
   * Result: true if suit is 4, false otherwise
   */
  bool is_club();
  /* Pre: rank = 1.
   * Result: true if rank is 1, false otherwise
   */
  bool is_ace();
  /* Pre: rank = 11.
   * Result: true if rank is 11, false otherwise
   */
  bool is_jack();
  /* Pre: rank = 12.
   * Result: true if rank is 12, false otherwise
   */
  bool is_queen();
  /* Pre: rank = 13.
   * Result: true if rank is 13, false otherwise
   */
  bool is_king();
  // Result: true if rank is 1, false otherwise
  int get_rank();
  //convert int to string
  std::string to_string();
 private:
  int suit;
  int rank;
};

#endif

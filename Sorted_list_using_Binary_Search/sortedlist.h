/* @author   Abdullah Alhassan
 * @version  1
 * @file     sortedlist.h
 */
#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include "card.h"

typedef Card item_type;

const int MAX_SIZE = 100;

class SortedList {
 public:
  SortedList();
  /* Pre: not full
   * Post: add an item to the list
   * Result: true if the list is not empty, false otherwise
   */
  bool add(const item_type& item);
  /* Pre: not empty
   * Post: remove an item from the list
   * Result: true if the list is not empty, false otherwise
   */
  bool remove(const item_type& item);
  /* Pre: not empty
   * Result: true if the list contain the item, false otherwise
   */
  bool contains(const item_type& item) const;
  int size() const;
  bool is_empty() const;
  bool is_full() const;
  std::string to_string() const;
 private:
  item_type list_array[MAX_SIZE];
  int length;
  int binsearch(const item_type& item, int start, int end) const;
};

#endif

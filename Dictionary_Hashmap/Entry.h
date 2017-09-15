/*
 * @author Abdullah Alhassan
 * @version 1
 * @file Entry.h 
 */

#include <string>

#ifndef ENTRY_H
#define ENTRY_H

 
typedef int KeyType;
typedef std::string ItemType;

class Entry { 

 protected:
  
  ItemType item;
  KeyType searchKey;
  void setKey (const KeyType & Key);

 public:

  Entry();
  Entry(const KeyType& Key, const ItemType& newItem); 
  ~Entry();
  ItemType getItem () const;
  KeyType getKey () const;
  void setItem (const ItemType & newItem);

};

#endif

/*
 * @author Abdullah Alhassan
 * @version 1
 * @file HashedEntry.h
 */


#include "Entry.h"


#ifndef HASHEDENTRY_H
#define HASHEDENTRY_H




class HashedEntry : public Entry
{
 private:
 
  HashedEntry* nextPtr; 

 public:

  HashedEntry();
  ~HashedEntry();
  HashedEntry (const KeyType Key, const ItemType newItem);
  HashedEntry (const KeyType Key, const ItemType newItem, HashedEntry* nextEntryPtr);
  void setNext ( HashedEntry *nextEntryPtr);
  HashedEntry* getNext ()const;

}; // end HashedEntry

#endif

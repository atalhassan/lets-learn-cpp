/*
 * @author Abdullah Alhassan
 * @version 1
 * @file HashedEntry.cpp 
 */

#include "HashedEntry.h"



HashedEntry::HashedEntry() : nextPtr(NULL)
{
}

HashedEntry::~HashedEntry()
{
  delete nextPtr;
  delete getNext();
}

HashedEntry::HashedEntry(const KeyType Key, const ItemType newItem)
{
  nextPtr = NULL;
  searchKey = Key;
  item = newItem;
}

HashedEntry::HashedEntry(const KeyType Key, const ItemType newItem,  HashedEntry* nextEntryPtr)
{
  searchKey = Key;
  item = newItem;
  nextPtr = nextEntryPtr;
}

void HashedEntry::setNext(HashedEntry* nextEntryPtr) 
{
  nextPtr = nextEntryPtr;
}

HashedEntry* HashedEntry::getNext() const
{
  return nextPtr;
}

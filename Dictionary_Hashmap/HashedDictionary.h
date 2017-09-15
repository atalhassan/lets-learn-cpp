/*
 * @author Abdullah Alhassan
 * @version  1
 * @file HashedDictionary.h
 */


#include "HashedEntry.h"

#ifndef HASHEDDICTIONARY_H
#define HASHEDDICTIONARY_H


class HashedDictionary {

 private:

  HashedEntry* hashTable[101];
  
  int itemCount; //number of entries in Dictionary
  int hashTableSize; // # of occupied indexes in current hash table
 
  static const int DEFAULT_SIZE = 101;
  
  int hashFunc (KeyType searchKey) const; // modulo: searchKey%DEFAULT_SIZE;
 


 public:

  HashedDictionary ();
  ~HashedDictionary (); 

  bool isEmpty () const;
  int getNumberOfItems () const;
  //add to the hash tabel, if occupied, add to the front as a HashedEntry 
  bool add (const KeyType & Key, const ItemType & newItem); 
  //remove the item with a certain Key
  bool remove (const KeyType & Key);
  //clear all the content of the hashTable
  void clear ();
  //return the item sotred as a string
  ItemType getItem (const KeyType & Key) const;
  //check if the hashTable conatian an element with a certain key
  bool contains (const KeyType & Key) const;


};

#endif

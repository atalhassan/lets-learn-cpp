/*
 * @author Abdullah Alhassan
 * @version 1
 * @file HashedDictionary.cpp
 */


#include <iostream>
#include "HashedDictionary.h"

//constructor
HashedDictionary::HashedDictionary()
{
  itemCount = 0;
  hashTableSize = 0;
  //  hashTable = new HashedEntry[DEFAULT_SIZE];
  for(int i = 0; i < DEFAULT_SIZE; i++)
    hashTable[i] = NULL;
}

//Destructor
HashedDictionary::~HashedDictionary()
{
  if(!isEmpty())
    clear();
}

//hash funciton
int HashedDictionary::hashFunc(KeyType searchKey) const
{
  int i = (searchKey % DEFAULT_SIZE); 
  return i;
}

bool HashedDictionary::isEmpty() const
{
  return itemCount == 0;
}

int HashedDictionary::getNumberOfItems() const
{
  return itemCount;
}


// add function
bool HashedDictionary:: add(const KeyType& Key, const ItemType & newItem)
{
  //hash the key
  int code = hashFunc(Key);

  //Emtpy spot
  if(hashTable[code] == NULL){
    hashTable[code] = new HashedEntry(Key,newItem);
    hashTableSize++;
  }
  //add to the front
  else{
    HashedEntry* ptr = new HashedEntry(Key, newItem,hashTable[code]);
    hashTable[code] = ptr;
  }
  itemCount++;
  return true;
}
//remove function
bool HashedDictionary::remove(const KeyType& Key)
{
  //check if isEmpty
  if(isEmpty()){
    std::cout << "Emtpt Dictionary! \n";
    return false;
  }
  //hash the code
  int code = hashFunc(Key);
    
  //Empty spot
  if(hashTable[code] == NULL){
    std::cout << "The key is empty!!\n";
    return false;
  }
  //iterator pointer
  HashedEntry* ptr = hashTable[code];
  //The key is the first Node
  if(ptr->getKey() == Key) {
    hashTable[code] = hashTable[code]->getNext();
    delete ptr;
    if(hashTable[code] == NULL)
      hashTableSize--;
    else
      itemCount--;
    return true;
  }
  //in the middle or last
  else{
    //second iterator pointer
    HashedEntry* ptr2 = ptr; 
    while(ptr->getNext()->getNext() == NULL){
      if(ptr->getNext()->getKey() == Key) { 
	ptr2 = ptr->getNext();
	ptr->setNext(ptr2->getNext());
	delete ptr2;
	ptr = NULL;
	delete ptr;
	itemCount--;
	return true;
      }
      ptr = ptr->getNext();
    }
  }
  std::cout << "Key not found!!\n";
  return false;
}

//clear function
void HashedDictionary::clear()
{
  //if it is not empty
  if(!isEmpty()){
    for(int i = (DEFAULT_SIZE - 1); i >=0; i--){
      while(hashTable[i] != NULL){
	HashedEntry* ptr = hashTable[i];
	hashTable[i] = hashTable[i]->getNext();
	ptr = NULL;
	delete ptr;
      }
    }
    itemCount = 0;
    hashTableSize = 0;
  }
  else
    std::cout << "Emtpy List!! \n";
  
}

//get item function
ItemType HashedDictionary::getItem(const KeyType& Key) const
{
  int code = hashFunc(Key);
  HashedEntry* ptr = hashTable[code];
  
  //Empty spot
  if(hashTable[code] == NULL){
    return "The Key is empty!!\n";
  }
  //one item in the hashTable
  if(hashTable[code]->getKey() == Key){
    return hashTable[code]->getItem();
  }

  //in the middle  
  while(ptr != NULL) {
    if(ptr->getKey() == Key){
      std::string item =  hashTable[code]->getItem();
      return item;
      break;
    }
    ptr = ptr->getNext();
  }
  
  return "The key is empty!!!!\n";  
}

//contains function
bool HashedDictionary::contains(const KeyType& Key) const
{
  int code = hashFunc(Key);
  HashedEntry* ptr = hashTable[code];
  
  //Empty spot
  if(hashTable[code] == NULL){
    std::cout << "The key is empty!!";
    return false;
  }
  //one item in the hashTable
  if(hashTable[code]->getKey() == Key){
    return true;
  }
  //in the middle
  while(ptr != NULL) {
    if(ptr->getKey() == Key)
      return true;
    ptr = ptr->getNext();
  }
  return false;
} 

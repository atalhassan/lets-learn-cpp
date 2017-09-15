/*
 * @author Abdullah Alhassan
 * @version  1
 * @file Entry.cpp
 */



#include "Entry.h"

Entry::Entry():item(""), searchKey(0)
{
}

Entry::Entry(const KeyType& Key, const ItemType& newItem)
{
  setKey(Key);
  setItem(newItem);
}

Entry::~Entry()
{
  searchKey = 0;
  item = "";
}

ItemType Entry::getItem() const
{
  return item;
}

KeyType Entry::getKey() const
{
  return searchKey;
}

void Entry::setItem(const ItemType & newItem)
{
  item = newItem;
}

void Entry::setKey(const KeyType & key)
{
  searchKey = key;
}

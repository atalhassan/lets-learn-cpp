/* @author   Abdullah Alhassan
 * @version  1
 * @file     sortedlist.cpp
 */
#include "sortedlist.h"
#include <string>
#include <iostream>


SortedList::SortedList(): length(-1)
{
}

int SortedList::binsearch(const item_type& item, int start, int end) const
{
  //base case
  if(start > end) 
    return -1;
  else {
    int middle = ((start + end)/2);  
    if(item == list_array[middle])
      return middle;
    else if(item < list_array[middle])
      //recurssive step
      return binsearch(item, start, (middle-1) );
    else if(item > list_array[middle])
      //recurssive step
      return binsearch(item, (middle+1), end); 
  }// end if
  //failed search
  return -1;
}

bool SortedList::add(const item_type& item)
{
  if(is_full())
    return false;
  //Empty list
  if(is_empty())
    list_array[0] = item;
  else { 
    //start from the end
    for(int i = length; i >= 0; i--){
      //check if the item is larger
      if(item > list_array[i]){
	list_array[i+1] = item;
	break;
	//if reaches 0
      }else if( i == 0) {
	list_array[i+1] = list_array[i];
	list_array[i] = item;
	break;
      }
      list_array[i+1] = list_array[i];
    }
  }
  length++;
  return true;
}

bool SortedList::remove(const item_type& item)
{
  if(is_empty())
    return false;
  int position = binsearch(item,0, length);
  //if item didn't exist
  if(position == -1)
    return false;
  //starting from the position
  for(int i = position; i < (size()-1); i++) 
    list_array[i] = list_array[i + 1];
  length--;
  return true;
}

bool SortedList::contains(const item_type& item) const
{
  if(is_empty())
    return false;
  int position = binsearch(item, 0, length);
  if(position > -1)
    return true;
  return false;
}

int SortedList::size() const
{
  return length + 1;
}

bool SortedList::is_empty() const
{
  return size() == 0;
}
bool SortedList::is_full() const
{
  return size() == MAX_SIZE;
}

std::string SortedList::to_string() const
{
  std::string name = "";
  Card tmp;
  for(int i = 0; i < (size()-1); i++) {
    tmp  = list_array[i];
    name += tmp.to_string() + " ";    
  }
  tmp = list_array[size() - 1];
  name += tmp.to_string();
  return "{" + name + "}";
}


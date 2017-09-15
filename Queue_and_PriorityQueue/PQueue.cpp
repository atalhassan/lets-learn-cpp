/* Circular array-based implementation.
 * The array has indexes to the front and back of the
 * queue. A counter tracks the number of items currently
 * in the queue. 
 *
 * @author Abdullah Alhassan
 * @version 1
 * @file PQueue.cpp
 */
 

#include "PQueue.h"  // header file
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue()
{
}  // end default constructor

// enqueue adds an item to the proper position in the queue
//@pre emtpy queue
//@post adds an item to the queue in the proper position
//       and increment the count and back by 1
//@result the queue content new item
void PriorityQueue::enqueue(QueueItemType& newItem)
{
  //When the queue is full
  if(count == MAX_QUEUE) {
    cout << "Queue is full!! \n";
    return;
  }
  //When the queue is empty
  if(isEmpty()) {
    items[front] = newItem;
  } 
  //Normal case
  else {
    for(int i = back; i >= 0; i--){
      if(newItem > items[i]){
	items[i+1] = newItem;
      }
      else
	items[i+1] = items[i];
      //if the integer was the smallest
      if(i == 0)
	items[i] = newItem;
    }
  } 
   back++;
   count++;   
 }  // end enqueue
// End of implementation file.

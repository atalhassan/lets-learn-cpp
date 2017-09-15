/** @file QueueA.cpp
 * Circular array-based implementation.
 * The array has indexes to the front and back of the
 * queue. A counter tracks the number of items currently
 * in the queue. 
 *
 * @author Abdullah Alhassan
 * @version 1
 * @file QueueA.cpp
 */

#include "QueueA.h"  // header file
#include <iostream>
using namespace std;

Queue::Queue() : front(0), back(-1), count(0)
{
}  // end default constructor

// isEmpty checks if the function has content
//@pre count is 0
//@result returns true if count is 0, false otherwise
bool Queue::isEmpty() 
{
  if(count == 0)
    return true;
  return false;
}  // end isEmpty

// enqueue add an item to end of the Queue
//@pre emtpy queue
//@post adds an item to the queue and increment the count and back by 1
//@result the queue content new item
void Queue::enqueue(QueueItemType& newItem)
{
  if(count == MAX_QUEUE) {
    cout << "Queue is full!! \n";
    return;
  }
  if(isEmpty()) {
    items[front] = newItem;
  } else {
    for(int i = back; i >= 0; i--)
      items[i+1] = items[i];
    items[front] = newItem;
  }
  back++; 
  count++;
}  // end enqueue

// dequeue removes the last item from the queue
//@pre the queue is not empty
//@post removes the lst item from the queue and decrease count and back by 1
//@result a queue with lower by an item
void Queue::dequeue()
{
  if(isEmpty()) {
    cout << "QUEUE is empty!!!!" << endl;
    return;
  }
  back--;
  count--;
}  // end dequeue

// getFront retrieve the last element in the queue
//@pre the queue is not empty
//@post retrieve the last item in the queue
//@result true is the queue is not empty, false otherwise 
bool Queue::getFront(QueueItemType& newItem)
{
  if(isEmpty()) {
    cout << "QUEUE is empty!!" << endl;
    return false;
  }
  newItem = items[back];
  return true;
}  // end getFront
// End of implementation file.

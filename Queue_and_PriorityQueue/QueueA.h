/*
 * @author Abdullah Alhassan
 * @version 1
 * @file QueueA.h 
 */

//#include "QueueException.h"
#ifndef QUEUEA_H
#define QUEUEA_H
//const int MAX_QUEUE = maximum-size-of-queue;
//typedef desired-type-of-queue-item QueueItemType;
const int MAX_QUEUE = 15;
typedef int QueueItemType;

/** @class Queue
 * ADT queue - Array-based implementation. */
class Queue
{
 public:
  // constructors and destructor:
  /** Default constructor. */
  Queue();
  // copy constructor and destructor are
  // supplied by the compiler

  // Queue operations:
  bool isEmpty();
  void enqueue(QueueItemType& newItem);
  void dequeue();
  bool getFront(QueueItemType& newItem);

 protected:
  QueueItemType items[MAX_QUEUE];
  int front;
  int back;
  int count;
}; // end Queue
#endif
// End of header file.

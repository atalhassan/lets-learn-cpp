/*
 * @author Abdullah Alhassan
 * @version 1
 * @file PQueue.h 
 */

#include "QueueA.h"

#ifndef PRIORITYQUEUEA_H
#define PRIORITYQUEUEA_H


/** @class Queue
 * ADT queue - Array-based implementation. */
class PriorityQueue: public Queue
{
 public:
  // constructors and destructor:
  /** Default constructor. */
  PriorityQueue();

  void enqueue(QueueItemType& newItem);
  
}; // end Queue
#endif
// End of header file.

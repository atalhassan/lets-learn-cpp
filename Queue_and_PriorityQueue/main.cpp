/* This program was built to test the header file 
 * PriorityQueue, the test is by adding random numbers
 * to the Queue to see if it would pace it in order
 * of priorty.
 *
 * @author Abdullah Alhassan
 * @version 1
 * @file main.cpp
 */

#include "PQueue.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
  srand(time(NULL));
  PriorityQueue x;
  int b;
  //add random numbers to the queue
  for(int i = 15; i > 0; i--) {
    b = rand() % 20;    
    x.enqueue(b);
  }

  //try to add while it's full
  b = 12;
  x.enqueue(b);

  int a;
  //peek and remove the first item entered 
  for(int i = 15; i > 0; i--){
    x.getFront(a);
    x.dequeue();
    cout << a << endl;
  }

  //try to remove while empty
  x.dequeue();

  return 0;
}

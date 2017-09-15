/*
 * @author Abdullah Alhassan
 * @version 1
 * @file main.cpp 
 *
 * This program was designed to test
 * the merge sort implemntaion.
 * the sorting will be in an
 * ascending order, and the list
 * will be linkedlist implemntation. 
 */

#include "ListP.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main()
{

  srand(time(NULL));
  //initializing L1
  ListP L1;
  
  //insert 10 items to L1
  for(int i = 0; i < 10; i++)
    L1.insert(i, rand() % 50);

  cout << "L1 before sorting: \n";

  //display 
  L1.display();
  
  cout << endl << endl;

  cout << "L1 after sorting: \n";

  //sort L1
  L1.sort_mergesort();
  
  L1.display();

  cout << endl << endl;


  return 0;
}

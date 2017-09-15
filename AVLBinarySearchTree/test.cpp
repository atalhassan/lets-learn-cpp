/*
 * @author Abdullah Alhassan
 * @version 1
 * @file test.cpp
 */

#include <iostream>
#include "avlbinsearchtree.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
  int x;

  srand(time(NULL));
  AVLBinSearchTree a;
  
  //assighn random items between 0 - 49
  for(int i = 0; i < 25; i++)
    a.insert(rand() % 100);
 
  // print a tree
  cout << "a:\n";
  a.printTest();

  cout << endl;

  //copy constructor
  AVLBinSearchTree b(a);
  
  //inserting 5 items to tree a to make sure it is a deep copy
  for(int i =0; i < 5; i++) 
    a.insert(rand() % 100);
 
  //print b tree
  cout << "b:\n";
  b.printTest();
 
  //assignement operator
  AVLBinSearchTree c = b;

  //inserting 5 items to tree b to make sure it is a deep copy
  for(int i =0; i < 5; i++) 
    b.insert(rand() % 100);

  cout << "\nc: \n";

  //print c tree
  c.printTest();
  cout << endl;

  //The destructor will be called by defult
  return 0;
}

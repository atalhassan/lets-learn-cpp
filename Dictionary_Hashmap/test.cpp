/*
 * @author Abdullah Alhassan
 * @version 1
 * @file test.cpp 
 *
 * This Program was built to test the funciton on the 
 * Dictionary class, which was implemented using a hashTable
 * of size 101
 */


#include <iostream>
#include "HashedDictionary.h"

using namespace std;

int main ()
{
  //Create Dictionary object
  HashedDictionary H1;

  //add 120 items to the Dictionary
  for(int i = 0; i < 120; i++)
    H1.add(i, "Abdullah");      


  //remove 10 items to the Dictionary
  for(int i = 0; i < 10; i++)
    H1.remove(i);     


  //Print the results
  for(int i = 0; i < 50; i++) {
    if(i % 10 == 0)
      cout << endl;
    cout << H1.getItem(i) << "  ";
  }
  cout << endl << endl;
 
  //chech if the Dictonarry contains a certain Key
  for(int i = 0; i < 250; i++){
    if(i % 10 == 0)
      cout << endl;
    if(H1.contains(i))
      cout << "T"<< "  ";
    else
      cout << "F" << "  ";
  }

  cout << endl;
 
  //clear the contents
  H1.clear();
   
  return 0;
}

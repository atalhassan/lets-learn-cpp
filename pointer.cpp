/*
  Pointers in C++ is denoted by * e.g. 
  int* a;
  
  where "a" holds the memory address of the variable a

  to get the actual value of "a" inside that memory we use the 
  defrenceing &

  &a will output the value inside a
  
  This program will create a list and pass it to a function as a pointer
  The function then will redeclare the list and change its values, which will
  also be changed in the main function
 */


#include <iostream>

using namespace std;

void createA(int* &b, int num);


int main (){

  int* a = new int[3];

  createA(a, 4);

  for(int k = 0; k < 4; k++){
    cout << a[k] << endl;
    
  }
  
  return 1;
}


void createA(int* &b, int num){
  b = new int[num];

  for(int k = 0; k < num; k++){
    *(b + k) = k * 3;
  }
  b[3] = 4;
}

/*
 * @author Abdullah Alhassan
 * @version 1
 * @file node.h
 *
 * This pupose of this program is to test the BinarySerachTree class.
 * Testing all the functions to make sure that the class is woking
 * proparly.
 */

#include <iostream>
#include "binarysearchtree.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
  srand(time(NULL));

  BinarySearchTree a;

  for(int i = 0; i < 45; i++)
    a.Insert(rand() % 50);

  cout << "a: PreOreder:\n";
  a.preorderTraverse();
  cout << endl;

  cout << "a: InOreder:\n";
  a.inorderTraverse();
  cout << endl;  

  cout << "a: PostOreder:\n";
  a.postorderTraverse();
  cout << endl;    

  cout << "a: search for numbers from 0 to 9, print if found\n";
  

  for(int i = 0; i < 10; i++)
    if(a.Search(i))
      cout << i << "  ";


  cout << endl << endl;  
  
  //copy constructor
  BinaryTree b(a);
  cout << "A new Binary Tree was constructed using the copy constructor\n";
  cout << endl;  
  cout << "b:\n";
 
    

  cout << "b: PreOreder:\n";
  b.preorderTraverse();
  cout << endl;

  cout << "b: InOreder:\n";
  b.inorderTraverse();
  cout << endl;  

  cout << "b: PostOreder:\n";
  b.postorderTraverse();
  cout << endl;    


 return 0;
}

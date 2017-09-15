OA/*
 * This program is built to compute the probability of
 * getting a random number from a dice that has a chosen
 * number of sides. Also, it will calculate the average
 * number of rolling values, and make a histogram of 
 * every side.
 *
 *
 * @author  Abdullah Alhassan
 * @version 1
 * @file    main.cpp
 *
 */
#include <iostream>
#include "dice.h"
using namespace std;

/*******************************************
 The print distribution funciton will take 
 the array from the main function and print 
 out a histogram distribution for each side.
********************************************/
void print_distribution(int rolls[], int num_of_sides, int num_of_rolls);

/*******************************************
 The avergace funciton will divide the sum 
 of the array by the number of rolls.  
********************************************/
float average(int rolls[], int num_of_rolls);

/*******************************************
 The print probabilities funciton will 
 calculate the number of times every
 side has been rolled and divide it by
 the number of rolls times 100, to get
 the precentage of every side.  
********************************************/
void print_probabilities(int rolls[], int num_of_sides, int num_of_rolls);

int main()
{
  cout << "-----------------------------\n";
  cout << "Wlecome to the dice roller!\n";
  cout << "-----------------------------\n\n";
  
  int sides = 2; // The minimum side number will be 2
  do{
  cout << "Please enter the number of sides for the dice: ";
  cin >> sides;
  if( sides <= 1)
    cout << "The number of sides must be 2 or larger\n\n";
  } while(sides <= 1); // The while loop is to prevent the user 
                      // from inputting invalid number 
  int roll_times = 1;
  do{
  cout << "Please enter the number of rolls of the dice:";
  cin >> roll_times;
  if( roll_times < sides)
    cout << "The number of rolls must be at least " << sides << "\n\n";
  } while( roll_times < sides);

  cout << "\n\n";

  Dice d1(sides);
  
  int rolls[roll_times]; // This array will contain the random numbers
  
  //This for loop will store the value of every roll to the array
  for(int roll = 0; roll < roll_times; roll++){
    d1.roll();
    rolls[roll] =  d1.get_value();
  }

  cout << "The distribution of the rolls was:\n";
  print_distribution(rolls, d1.get_sides(), roll_times);
  cout << endl;

  cout << "The average roll was: " <<  average(rolls, roll_times) << "\n\n";

  cout << "The probabilities of rolling each side was:\n"; 
  print_probabilities(rolls, d1.get_sides(), roll_times);

  return 0;
}
 
/************************ New Funciotn ******************************/

void print_distribution(int rolls[], int num_of_sides, int num_of_rolls)
{
  for(int side = 1; side <= num_of_sides; side++){
    cout << side << ": ";
    for(int item = 0; item <= num_of_rolls; item++)
      if( side == rolls[item])
	cout << "*";
    cout << endl;
  }
}

/************************ New Funciotn ******************************/

float average(int rolls[], int num_of_rolls)
{
  float sum = 0;
  for(int item = 0; item <= num_of_rolls; item++)
    sum += rolls[item];
  sum = (sum/num_of_rolls);
  return sum;
}

/************************ New Funciotn ******************************/

void print_probabilities(int rolls[], int num_of_sides, int num_of_rolls)
{
  for(int side = 1; side <= num_of_sides; side++){
    float sum = 0;
    cout << side << ": ";
    for(int item = 0; item <= num_of_rolls; item++)
      if(side == rolls[item])
	sum += 1;
    cout << ((sum/num_of_rolls)*100) << " %" << endl;
  }
}

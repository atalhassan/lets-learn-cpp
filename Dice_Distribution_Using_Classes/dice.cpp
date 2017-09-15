/* 
 *@author   Abdullah Alhassan
 *@veriosn  1
 *@file     dice.cpp
 *
 */
#include "dice.h"
#include <stdlib.h>
#include <time.h>

Dice::Dice(int num_of_sides)
{
  sides = num_of_sides;
  curr_value = 0;
}
void Dice::roll()
{
  /* This for loop will only loop once, because in the main
   * funciton it will be called based on the number of loops
   */
  for(int roll = 0; roll <= 1; roll++)
    curr_value = ((rand() % sides) + 1);
}
int Dice::get_sides()
{
  return sides;
}
int Dice::get_value()
{
  return curr_value;
}

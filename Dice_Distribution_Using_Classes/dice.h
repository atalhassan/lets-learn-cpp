/*
 *@author  Abdullah Alhassan
 *@version 1.0
 *@file    dice.h
 *
 */
#ifndef DICE_H
#define DICE_H
class Dice{
 public:
  Dice(int num_of_sides);
  void roll();
  int get_sides();
  int get_value();
 private:
  int sides;
  int curr_value;
};
#endif

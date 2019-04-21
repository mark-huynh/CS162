#include "seaotter.hpp"


/*********************************************************************
** Function: SeaOtter()
** Description: SeaOtter constructer
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: SeaOtter object is instantiated
*********************************************************************/
SeaOtter::SeaOtter()
{
  this->age = 0;
  this->cost = 5000;
  this->birthNum = 2;
  this->revenue = 250;
  this->foodCost *= 2;
}


/*********************************************************************
** Function: SeaOtter(int age)
** Description: SeaOtter parameterized constructer
** Parameters: int age
** Pre-Conditions: none
** Post-Conditions: SeaOtter object is instantiated
*********************************************************************/
SeaOtter::SeaOtter(int age)
{
  this->age = age;
  this->cost = 5000;
  this->birthNum = 2;
  this->revenue = 250;
  this->foodCost *= 2;
}

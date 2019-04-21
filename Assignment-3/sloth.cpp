#include "sloth.hpp"


/*********************************************************************
** Function: Sloth()
** Description: Sloth constructer
** Parameters:  none
** Pre-Conditions: None
** Post-Conditions: Sloth object is instantiated
*********************************************************************/
Sloth::Sloth()// : age(0), cost(2000), birthNum(3), revenue(100){}
{
  this->age = 0;
  this->cost = 2000;
  this->birthNum = 3;
  this->revenue = 100;
}


/*********************************************************************
** Function: Sloth
** Description: Sloth parameterized constructer
** Parameters: int age
** Pre-Conditions: None
** Post-Conditions: Sloth object is instantiated
*********************************************************************/
Sloth::Sloth(int age)
{
  this->age = age;
  this->cost = 2000;
  this->birthNum = 3;
  this->revenue = 100;
}

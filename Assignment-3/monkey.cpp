#include "monkey.hpp"
#include <ctime>
#include <cstdlib>
/*********************************************************************
** Function: Monkey()
** Description: Monkey constructor
** Parameters: None
** Pre-Conditions: none
** Post-Conditions: monkey object is instantiated
*********************************************************************/
Monkey::Monkey()
{
  this->age = 0;
  this->cost = 15000;
  this->birthNum = 1;
  this->revenue = 1500;
  this->foodCost *= 4;
}


/*********************************************************************
** Function: Monkey(int age)
** Description: Parametarized Constructor
** Parameters: int age
** Pre-Conditions: None
** Post-Conditions: Monkey object is instantiated
*********************************************************************/
Monkey::Monkey(int age)
{
  this->age = age;
  this->cost = 15000;
  this->birthNum = 1;
  this->revenue = 1500;
  this->foodCost *= 4;


}
/*********************************************************************
** Function:setbonusRev()
** Description: sets the bonusRev variable to a random balue between 250 and 500
** Parameters: none
** Pre-Conditions: Monkey object is instantiated
** Post-Conditions:
*********************************************************************/
void Monkey::setbonusRev()
{
  //srand(time(NULL));
  this->bonusRev = (rand() % 251) + 250;


}
/*********************************************************************
** Function: getbonusRev()
** Description: returns bonusRev
** Parameters: none
** Pre-Conditions: Monkey object is instantiated
** Post-Conditions:
*********************************************************************/
int Monkey::getbonusRev()
{
  return this->bonusRev;
}

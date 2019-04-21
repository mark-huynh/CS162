#include "animal.hpp"

/*********************************************************************
** Function: Animal()
** Description: Animal constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Animal Object is instantiated
*********************************************************************/
Animal::Animal() : foodCost(50){}


/*********************************************************************
** Function: changeFoodCost(float percent)
** Description: Sets the cost of food by a certain percentage
** Parameters: integer of percent
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Animal::changeFoodCost(float percent)
{
  this->foodCost = (int)((this->foodCost) * (percent / 100.0));
}

/*********************************************************************
** Function: getfoodCost()
** Description: returns foodCost
** Parameters: None
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Animal::getfoodCost()
{
  return this->foodCost;
}

/*********************************************************************
** Function: getAge()
** Description: returns age
** Parameters: none
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Animal::getAge()
{
  return this->age;
}

/*********************************************************************
** Function: getCost()
** Description: returns cost
** Parameters: none
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Animal::getCost()
{
  return this->cost;
}

/*********************************************************************
** Function: getbirthNum()
** Description: returns birthNum
** Parameters: none
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Animal::getbirthNum()
{
  return this->birthNum;
}

/*********************************************************************
** Function: getRevenue()
** Description: returns the revenue
** Parameters: none
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Animal::getRevenue()
{
  return this->revenue;
}

/*********************************************************************
** Function: setfoodCost(int n)
** Description: sets the cost of food to a number
** Parameters: integer to set food cost to
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Animal::setfoodCost(int n)
{
  this->foodCost = n;
}

/*********************************************************************
** Function: setAge(int n)
** Description: sets the age of an animal
** Parameters: integer n
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Animal::setAge(int n)
{
  this->age = n;
}

/*********************************************************************
** Function: setCost(int n)
** Description: Sets the cost of animal
** Parameters: integer
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Animal::setCost(int n)
{
  this->cost = n;
}

/*********************************************************************
** Function: setbirthNum
** Description: sets the birthnum
** Parameters: int n
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Animal::setbirthNum(int n)
{
  this->birthNum = n;
}

/*********************************************************************
** Function: setRevenue
** Description: sets the revenue
** Parameters: integer n
** Pre-Conditions: Animal Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Animal::setRevenue(int n)
{
  this->revenue = n;
}

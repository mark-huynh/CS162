#include "pit.hpp"
#include <iostream>

/*********************************************************************
** Function: encounter()
** Description: Overidden function for encounter in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Pit::encounter()
{
  return 2;
}

/*********************************************************************
** Function: percept()
** Description: Overidden function for percept in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Pit::percept()
{
  std::cout << "You feel a breeze.\n";
}

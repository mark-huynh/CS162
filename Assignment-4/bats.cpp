#include "bats.hpp"
#include <iostream>
/*********************************************************************
** Function: encounter()
** Description: Overidden function for encounter in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Bats::encounter()
{
  return 3;
}
/*********************************************************************
** Function: percept
** Description: Overidden function for percept in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Bats::percept()
{
  std::cout << "You hear wings flapping.\n";
}

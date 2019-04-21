#include "openspace.hpp"


/*********************************************************************
** Function: OpenSpace()
** Description: Default constructor for OpenSpace
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: OpenSpace object is instantiated
*********************************************************************/
OpenSpace::OpenSpace()
{
  this->start = false;
  this->student = false;
  this->ta = false;
  this->instructor = false;
  this->ladder = false;
  this->skill = false;
}


/*********************************************************************
** Function: is_occupiable()
** Description: Returns true since an OpenSpace is occupiable
** Parameters: None
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::is_occupiable()
{
  return true;
}


/*********************************************************************
** Function: get_display_character()
** Description: returns the appropriate display character for an OpenSpace
** Parameters: None
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
char OpenSpace::get_display_character()
{
  if(this->student == true)
  {
    return '*';
  }
  if(this->ta == true)
  {
    return 'T';
  }
  if(this->instructor == true)
  {
    return '%';
  }
  if(this->skill == true)
  {
    return '$';
  }
  if(this->start == true)
  {
    return '@';
  }
  if(this->ladder == true)
  {
    return '^';
  }
  return ' ';
}


/*********************************************************************
** Function: hasStudent()
** Description: getter method that returns if a IntrepidStudent is occupying the OpenSpace
** Parameters: None
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::hasStudent()
{
  return student;
}


/*********************************************************************
** Function: hasTa()
** Description: getter method for ta
** Parameters: none
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::hasTa()
{
  return ta;
}


/*********************************************************************
** Function: hasInstructor()
** Description: getter method for instructor
** Parameters: None
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::hasInstructor()
{
  return instructor;
}


/*********************************************************************
** Function: hasLadder()
** Description: getter method for ladder
** Parameters: None
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::hasLadder()
{
  return ladder;
}


/*********************************************************************
** Function: hasSkill()
** Description: getter method for skill
** Parameters: None
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::hasSkill()
{
  return skill;
}


/*********************************************************************
** Function: setHasStudent(bool status)
** Description: setter method for Student
** Parameters: boolean to change if an OpenSpace has a student
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
void OpenSpace::setHasStudent(bool status)
{
  student = status;
}


/*********************************************************************
** Function: setHasTa(bool status)
** Description: setter method for ta
** Parameters: sets if an OpenSpace has a ta
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
void OpenSpace::setHasTa(bool status)
{
  this->ta = status;
}


/*********************************************************************
** Function: setHasInstructor(bool status)
** Description: setter method for instructor
** Parameters: bool if the openspace has an instructor
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
void OpenSpace::setHasInstructor(bool status)
{
  instructor = status;
}


/*********************************************************************
** Function: setHasLadder(bool status)
** Description: setter method for ladder
** Parameters: bool if the OpenSpace has a ladder
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
void OpenSpace::setHasLadder(bool status)
{
  ladder = status;
}


/*********************************************************************
** Function: setHasSkill(bool status)
** Description: setter method for skill
** Parameters: bool if an openspace has a programmingSkill
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
void OpenSpace::setHasSkill(bool status)
{
  skill = status;
}


/*********************************************************************
** Function: setStart(bool status)
** Description: setter method for start
** Parameters: a bool value to set if an OpenSpace is the start
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
void OpenSpace::setStart(bool status)
{
  this->start = status;
}


/*********************************************************************
** Function: isStart()
** Description: getter method for start
** Parameters: none
** Pre-Conditions: OpenSpace object is instantiated
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::isStart()
{
  return this->start;
}

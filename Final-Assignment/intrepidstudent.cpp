#include "intrepidstudent.hpp"
#include <iostream>

using namespace std;


/*********************************************************************
** Function: IntrepidStudent()
** Description: Default constructor for IntrepidStudent
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: IntrepidStudent Object is instantiated
*********************************************************************/
IntrepidStudent::IntrepidStudent()
{
  this->type = 'S';
  this->programmingSkills = 0;
}


/*********************************************************************
** Function: getMove()
** Description: Implemented virtual function from parent class. Prompts user for student's move
** Parameters: None
** Pre-Conditions: IntrepidStudent Object is instantiated
** Post-Conditions: None
*********************************************************************/
char IntrepidStudent::getMove()
{
  // char input;
  string input;
  cout << "Use WASD keys to move around, U to climb the ladder (^), and P to use a programming skill \n";
  cin >> input;
  while(input.length() > 1)
  {
    cout << "Please input a valid character \n";
    cin >> input;
  }
  input = toupper(input[0]);
  while(input != "W" && input != "A" && input != "S" && input != "D" && input != "P" && input != "U")
  {
    cout << "Please input a valid character\n";
    cin >> input;
  }
  if(input == "P" && this->programmingSkills == 0)
  {
    return 'N';
  }
  char c = input[0];
  return c;
}


/*********************************************************************
** Function: getProgrammingSkills()
** Description: returns the amount of programming skills student holds
** Parameters: None
** Pre-Conditions: IntrepidStudent Object is instantiated
** Post-Conditions: None
*********************************************************************/
int IntrepidStudent::getProgrammingSkills()
{
  return this->programmingSkills;
}


/*********************************************************************
** Function: decrementProgramming()
** Description: decreases the amount of programming skills by 1
** Parameters: None
** Pre-Conditions: IntrepidStudent Object is instantiated
** Post-Conditions: None
*********************************************************************/
void IntrepidStudent::decrementProgramming()
{
  this->programmingSkills--;
}


/*********************************************************************
** Function: setProgrammingSkills(int num)
** Description: sets the number of programming skills student has
** Parameters: an integer
** Pre-Conditions: IntrepidStudent Object is instantiated
** Post-Conditions: None
*********************************************************************/
void IntrepidStudent::setProgrammingSkills(int num)
{
  this->programmingSkills = num;
}

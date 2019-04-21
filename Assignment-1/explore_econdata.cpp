/*********************************************************************
 * ** Program Filename: explore_econdata.cpp
 * ** Author: Mark Huynh
 * ** Date: January 18th, 2019
 * ** Description: This program will enable the user to run the executable file with a text file containing economic data in a valid format
 *                 and will create a series of user friendly navigation panels to assist with outputting different types
 *                 of data from the file specified by the user.
 * ** Input: Text file of valid format containing economic data of states and counties
 * ** Output: Depending on user's choice: highest/lowest median income, highest/lowest unemployment data, or a 
 *            sorted list of States/Counties in terms of median income or of greatest unemployment change
 * *********************************************************************/


#include "econdata.hpp"


/*********************************************************************
 * ** Function: main
 * ** Description: This is the main function that will call upon the  defined functions in econdata.cpp in order to navigate through the provided text file.
 *                 It also ensures at the start of the program that the file was sucessfully read and inputted into the program.
 * ** Parameters: The text file in a valid format to be navigated by the user
 * ** Pre-Conditions: All functions are defined and prototypes are declared in econdata.cpp and econdata.hpp
 * ** Post-Conditions: None
 * *********************************************************************/ 

int main(int argc, char* argv[])
{
   ifstream infile;
   infile.open(argv[1]);
   if(infile.fail())
   {
      cout << "File could not be read" << endl;
      return 1;
   }
   int numStates;
   infile >> numStates;
   struct state* stateArr = allocate_states(numStates);
   read_state_data(stateArr, numStates, infile);   
   int desired = choice();
   int soc = stateOrCount();
   printOutput(soc, desired, stateArr, numStates);
   free_state_data(stateArr, numStates);
}

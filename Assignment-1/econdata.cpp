#include "econdata.hpp"


/*********************************************************************
 * ** Function: choice
 * ** Description: This function welcomes the user to the program along with instructions. It then prompts the user
 *                 to input what sort of information they would like to see and returns the choice that they have made.
 * ** Parameters: None
 * ** Pre-Conditions: None
 * ** Post-Conditions: Returns the user's choice from a range of 1-6 (inclusive)
 * *********************************************************************/

int choice()
{
   cout << endl;
   cout << endl;
   cout << "----------------------------------------------------------------------------------------------" << endl;
   cout << "Welcome to the Economic Data Navigator! Type Control + C if you would like to exit at any time" << endl;
   cout << "----------------------------------------------------------------------------------------------" << endl;
   cout << "Which information would you like to learn about?:" << endl;
   cout << "The State/County with the highest median household income (1)" << endl;
   cout << "The State/County with the lowest median household income (2)" << endl;
   cout << "The State/County with the highest unemployment in 2015 (3)" << endl;
   cout << "The State/County with the lowest unemployment in 2015 (4)" << endl;
   cout << "The States/Counties in sorted order by change in unemployment from 2007 to 2015 (5)" << endl; 
   cout << "The States/Counties in sorted order by median household income (6)" << endl;
  return validInput(6); 
}


/*********************************************************************
 * ** Function: stateorCount
 * ** Description: Asks the user if they would like to display their information at a state level 
 *                 or at a county level.
 * ** Parameters: None
 * ** Pre-Conditions: None
 * ** Post-Conditions: Returns the user's choice from a range of 1-2 (inclusive)
 * *********************************************************************/
int stateOrCount()
{
   cout << "Would you like information at a (1)State level or a (2)County Level?" << endl;
   return validInput(2);
}


/*********************************************************************
 * ** Function: printOutput
 * ** Description: Takes in all of the user input data and determines what should be outputted depending on the 
 *                 choices of the user. The information that is outputted is sourced from the allocated state
 *                 array.
 * ** Parameters: The integer value of the user's choice for what type of information they would like outputted (choice)
 *                and whether or not it was state or county level (soc). The pointer of the array of states must also be 
 *                inputted along with the size of the array (numStates).
 * ** Pre-Conditions: The inputted struct state array must have had been allocated and had the parsed data inputted into 
 *                    all of it's variables. This also includes having it's counties arrays allocated and data inputted.
 * ** Post-Conditions: Specific economic data about States/Counties are outputted to the console.
 * *********************************************************************/

void printOutput(int soc, int choice, struct state* states, int numStates)
{
   if(soc == 1)		/* if the user chose to display State level information */
   {
      switch(choice)
      {
	 case 1:	/* Outputs highest median income */
	 {
	    struct state j;
	    j.med_income = 0;
	    for(int i = 0; i < numStates; i ++)
	    {
	       if(states[i].med_income > j.med_income)
	       {
		  j = states[i];
	       }
	    }
	    cout << "The State with the highest median household income is " << j.name << " with a value of " << j.med_income << endl;
	    break;
	 }

	 case 2:	/* Outputs lowest median income */
	 {
	    struct state k;
	    k.med_income = INT_MAX;
	    for(int i = 0; i < numStates; i ++)
	    {
	       if(states[i].med_income < k.med_income)
	       {
		  k = states[i];
	       }
	    }
	    cout << "The State with the lowest median household income is " << k.name << " with a value of " << k.med_income << endl;
	    break;
	 }

	 case 3:	/* Outputs highest unemployment 2015 */
	 {
	    struct state j;
	    j.unemployed_2015 = 0;
	    for(int i = 0; i < numStates; i ++)
	    {
	       if(states[i].unemployed_2015 > j.unemployed_2015)
	       {
		  j = states[i];
	       }
	    }
	    cout << "The State with the highest unemployment is " << j.name << " with a value of " << j.unemployed_2015 << endl;
	    break;
	 }
	 case 4:	/* Outputs lowest unemployment 2015 */
	 {
	    struct state k;
	    k.unemployed_2015 = INT_MAX;
	    for(int i = 0; i < numStates; i ++)
	    {
	       if(states[i].unemployed_2015 < k.unemployed_2015)
	       {
		  k = states[i];
	       }
	    }
	    cout << "The State with the lowest unemployment in 2015 is " << k.name << " with a value of " << k.unemployed_2015 << endl;
	    break;
	 }
	 case 5: 	/* Outputs list of States sorted from lowest to highest increase in unemployment from 2007 to 2015 */
	 {
	    unempSortState(states, numStates);
	    cout << "States from lowest to highest increase in unemployment from 2007 to 2015: " << endl;
	    for(int i = 0; i < numStates; i++)
	    {
	       cout << states[i].name << " ";
	    }
	    cout << endl;
	    break;
	 }
	 case 6:	/* Outputs list of States sorted from lowest to highest median income */
	 {
	    sortIncState(states, numStates);
	    cout << "Counties from lowest to highest median income: " << endl;
	    for(int i = 0; i < numStates; i++)
	    {
	       cout << states[i].name << " ";
	    }
	    cout << endl;
	    break;
	 }

      }
   }
   else 		/* User chooses county level data */
   {
      int state = stateChoice(states, numStates);
      switch(choice)
      {
	 case 1:
	 {
	    struct county j;
	    j.med_income = 0;
	    for(int i = 0; i < states[state].n_counties; i++)
	    {
	       if(states[state].counties[i].med_income > j.med_income)
	       {
		  j = states[state].counties[i];
	       }
	    }
	    cout << "The County with the highest median household income is " << j.name << " with a value of " << j.med_income << endl;
	    break;
	 }
	 case 2:
	 {
	    struct county j;
	    j.med_income = INT_MAX;
	    for(int i = 0; i < states[state].n_counties; i++)
	    {
	       if(states[state].counties[i].med_income < j.med_income)
	       {
		  j = states[state].counties[i];
	       }
	    }
	    cout << "The County with the lowest median household income is " << j.name << " with a value of " << j.med_income << endl;
	    break;
	 }
	 case 3:
	 {
	    struct county j;
	    j.unemployed_2015 = 0;
	    for(int i = 0; i < states[state].n_counties; i++)
	    {
	       if(states[state].counties[i].unemployed_2015 > j.unemployed_2015)
	       {
		  j = states[state].counties[i];
	       }
	    }
	    cout << "The County with the highest unemployment is " << j.name << " with a value of " << j.unemployed_2015 << endl;
	    break;
	 }
	 case 4:
	 {
	    struct county j;
	    j.unemployed_2015 = INT_MAX;
	    for(int i = 0; i < states[state].n_counties; i++)
	    {
	       if(states[state].counties[i].unemployed_2015 < j.unemployed_2015)
	       {
		  j = states[state].counties[i];
	       }
	    }
	    cout << "The County with the lowest unemployment is " << j.name << " with a value of " << j.unemployed_2015 << endl;
	    break;
	 }
	 case 5:
	 {
	    unempSort(states[state].counties, states[state].n_counties);
	    cout << "Counties in " << states[state].name << " from lowest to highest increase in unemployment from 2007 to 2015: " << endl;
	    for(int i = 0; i < states[state].n_counties; i++)
	    {
	       cout << states[state].counties[i].name << " ";
	    }
	    cout << endl;
	    break;
	 }
	 case 6:
	 {
	    sortIncCount(states[state].counties, states[state].n_counties);
	    cout << "Counties in " << states[state].name << " from lowest to highest median income: " << endl;
	    for(int i = 0; i < states[state].n_counties; i++)
	    {
	       cout << states[state].counties[i].name << " ";
	    }
	    cout << endl;
	    break;
	 }
      }
   }
}


/*********************************************************************
 * ** Function: unempSortState
 * ** Description: Sorts the array of states in order of increasing unemployment (from 2007 to 2015)
 * ** Parameters: The array of states that want to be sorted and the size of the array
 * ** Pre-Conditions: Each state must have unemployment data for 2007 and 2015 and have unemployed_change initialized
 * ** Post-Conditions: Inputted array will be sorted in order of increasing unemployed_change
 * *********************************************************************/

void unempSortState(struct state* arr, int arrSize)
{
   for(int i = 0; i < arrSize; i++)
   {
      for(int j = 0; j < arrSize; j++)
      {
	 if(arr[i].unemployed_change < arr[j].unemployed_change)
	 {
	    struct state temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	 }
      }
   }
}


/*********************************************************************
 * ** Function: unempSort
 * ** Description: Sorts the array of counties in order of increasing unemployment (from 2007 to 2015)
 * ** Parameters: The array of counties that want to be sorted and the size of the array
 * ** Pre-Conditions: Each county  must have unemployment data for 2007 and 2015 and have unemployed_change initialized
 * ** Post-Conditions: Inputted array will be sorted in order of increasing unemployed_change
 * *********************************************************************/

void unempSort(struct county* arr, int arrSize)
{
   for(int i = 0; i < arrSize; i++)
   {
      for(int j = 0; j < arrSize; j++)
      {
	 if(arr[i].unemployed_change < arr[j].unemployed_change)
	 {
	    struct county temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	 }
      }
   }
}


/*********************************************************************
 * ** Function: sortIncState
 * ** Description: Sorts the array of states in order of increasing median income
 * ** Parameters: The array of states that want to be sorted and the size of the array
 * ** Pre-Conditions: Each state must have median income data initialized
 * ** Post-Conditions: Inputted array will be sorted in order of increasing med_income
 * *********************************************************************/

void sortIncState(struct state* arr, int arrSize)
{
   for(int i = 0; i < arrSize; i++)
   {
      for(int j = 0; j < arrSize; j++)
      {
	 if(arr[i].med_income < arr[j].med_income)
	 {
	    struct state temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	 }
      }
   }
}


/*********************************************************************
 * ** Function: sortIncCount
 * ** Description: Sorts the array of counties in order of increasing median income
 * ** Parameters: The array of counties that want to be sorted and the size of the array
 * ** Pre-Conditions: Each county must have median income data initialized
 * ** Post-Conditions: Inputted array will be sorted in order of increasing med_income
 * *********************************************************************/

void sortIncCount(struct county* arr, int arrSize)
{
   for(int i = 0; i < arrSize; i++)
   {
      for(int j = 0; j < arrSize; j++)
      {
	 if(arr[i].med_income < arr[j].med_income)
	 {
	    struct county temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	 }
      }
   }
}


/*********************************************************************
 * ** Function: stateChoice
 * ** Description: Asks the user which state they would like to invesigate for economic data
 * ** Parameters: the array of states from the inputted file and the size of the array
 * ** Pre-Conditions: state array is allocated and data is inputted
 * ** Post-Conditions: returns the integer corresponding to the location of the state in the array
 * *********************************************************************/

int stateChoice(struct state* states, int numStates)
{
   cout << "Which state's counties would you like to see?" << endl;
   for(int i = 0; i < numStates; i++)
   {
      cout << states[i].name << " (" << i + 1 << ") " << endl;
   }
   int choice = validInput(numStates) - 1;
   return choice;
}


/*********************************************************************
 * ** Function: validInput
 * ** Description: Will ensure that the user will only input an integer within the bounds specified 
 * ** Parameters: an integer value that will be the maximum value that can be inputed (from 0)
 * ** Pre-Conditions: None
 * ** Post-Conditions: returns an integer within the bounds specified
 * *********************************************************************/

int validInput(int range)
{
   	string userInput;
	cin >> userInput;
	while(!isdigit(userInput[0]))
	{
		cout << "Please enter a valid input between 1 and " << range << ": ";
		cin >> userInput;
	}
	stringstream value(userInput);
	int numUserInput;
	value >> numUserInput;


	while(numUserInput > range || numUserInput <= 0)
	{
		cout << "Please enter a valid input between 1 and " << range << ": ";
		cin >> numUserInput;
	}

	return numUserInput;
		
}


/*********************************************************************
 * ** Function: allocate_states
 * ** Description: Will create a struct state array on the heap with a specified size
 * ** Parameters: number of states that the array will have
 * ** Pre-Conditions: none
 * ** Post-Conditions: returns a state array of specified size
 * *********************************************************************/

struct state* allocate_states(int numStates)
{
	struct state* arrStates = new struct state[numStates];
}


/*********************************************************************
 * ** Function: read_state_data
 * ** Description: Will read the infomation from the file and input them into their respective variables within a state array
 * ** Parameters: A state array, the size of the array, and the file to be read from
 * ** Pre-Conditions: A state array needs to have been allocated and a ifstream object has to have been made from the file
 * ** Post-Conditions: A state array with values stored in each of its variables
 * *********************************************************************/

void read_state_data(struct state* arr, int numStates, ifstream& file)
{
   for(int i = 0; i < numStates; i++)
   {
      file >> arr[i].name;
      file >> arr[i].unemployed_2007;
      file >> arr[i].unemployed_2015;
      file >> arr[i].med_income;
      file >> arr[i].n_counties;
      arr[i].unemployed_change = arr[i].unemployed_2015 - arr[i].unemployed_2007;
      arr[i].counties = allocate_counties(arr[i].n_counties);
      read_county_data(arr[i].counties, arr[i].n_counties, file);
   }
}


/*********************************************************************
 * ** Function: allocate_counties
 * ** Description: Creates a county array on the heap with a specified size
 * ** Parameters: size of the array
 * ** Pre-Conditions: none
 * ** Post-Conditions: returns an array of counties of specified size
 * *********************************************************************/

struct county* allocate_counties(int numCounties)
{
   struct county* arrCounties = new struct county[numCounties];
}


/*********************************************************************
 * ** Function: read_county_data
 * ** Description: Will read the infomation from the file and input them into their respective variables within a county array
 * ** Parameters: A county array, the size of the array, and the file to be read from
 * ** Pre-Conditions: A county array needs to have been allocated and a ifstream object has to have been made from the file
 * ** Post-Conditions: A county array with values stored in each of its variables
 * *********************************************************************/

void read_county_data(struct county* countArr, int numCounties, std::ifstream& file)
{
      for(int i = 0; i < numCounties; i++)
      {
	 file >> countArr[i].name;
	 file >> countArr[i].unemployed_2007;
	 file >> countArr[i].unemployed_2015;
	 file >> countArr[i].med_income;
	 countArr[i].unemployed_change = countArr[i].unemployed_2015 - countArr[i].unemployed_2007;

      }
}


/*********************************************************************
 * ** Function: free_state_data
 * ** Description: deletes all of the county arrays and state arrays that were created on the heap
 * ** Parameters: the state array pointer and the size of the array
 * ** Pre-Conditions: the state and county arrays must have been initallized on the heap
 * ** Post-Conditions: the state and county arrays will be deleted from the heap
 * *********************************************************************/

void free_state_data(struct state* stateArr, int numStates)
{
	for(int i = 0; i < numStates; i++)
	{
	      delete[] stateArr[i].counties;
	}
	delete[] stateArr;
}


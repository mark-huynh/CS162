#include <sstream>
#include <cctype>
#include <iostream>
#include <fstream>
#include <string>
#include <limits.h>

using namespace std;
void unempSortState(struct state* arr, int arrSize);
void sortIncState(struct state* arr, int arrSize);
void unempSort(struct county* arr, int arrSize);
void sortIncCount(struct county* arr, int arrSize);
int stateChoice(struct state* states, int numStates);
int stateOrCount();
int choice();
void printOutput(int soc, int choice, struct state* states, int numStates);
int validInput(int range);
struct state* allocate_states(int numStates);
void read_state_data(struct state* arr, int numStates, ifstream& file);
struct county* allocate_counties(int numCounties);
void read_county_data(struct county* countArr, int numCounties, std::ifstream& file);
void free_state_data(struct state* stateArr, int numStates);

struct county 
{
  string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  float unemployed_change;
};

struct state 
{
  string name;
  float unemployed_2007;
  float unemployed_2015;
  int med_income;
  struct county* counties;
  int n_counties;
  float unemployed_change;
};

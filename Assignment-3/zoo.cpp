#include "zoo.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "seaotter.hpp"

using namespace std;


/*********************************************************************
** Function: Zoo()
** Description: Zoo constructer
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: Zoo object is instantiated
*********************************************************************/
Zoo::Zoo() : bank(/*2000*/ 100000), numMonkey(0), numSloth(0), numSeaOtter(0), zooMonkey(NULL), zooSloth(NULL), zooSeaOtter(NULL)
{
  this->babyMonkey = 0;
  this->adultMonkey = 0;
  this->babySloth = 0;
  this->adultSloth = 0;
  this->babySeaOtter = 0;
  this->adultSeaOtter = 0;
  this->teenMonkey = 0;
  this->teenSloth = 0;
  this->teenSeaOtter = 0;
}


/*********************************************************************
** Function: ~Zoo()
** Description: Zoo destructor
** Parameters: None
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: Zoo object is destructed
*********************************************************************/
Zoo::~Zoo()
{
  delete[] zooSloth;
  delete[] zooMonkey;
  delete[] zooSeaOtter;
}


/*********************************************************************
** Function: printAnimals()
** Description: prints out the number of each animal
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::printAnimals()
{
  countAnimals();
  cout << "You currently have: " << endl;
  cout <<" Baby Monkeys: " << babyMonkey << endl;
  cout <<" Adult Monkeys: " << adultMonkey << endl;
  cout <<" Baby Sloths: " << babySloth << endl;
  cout <<" Adult Sloths: " << adultSloth << endl;
  cout <<" Baby Sea Otters: " << babySeaOtter << endl;
  cout <<" Adult Sea Otters: " << adultSeaOtter << endl;
  cout <<" And you have " << teenSloth << " teen sloths, " << teenMonkey << " teen monkeys, and " << teenSeaOtter << " teen sea otters." << endl;
}


/*********************************************************************
** Function:  countAnimals()
** Description: counts all the different types of animals and updates them
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::countAnimals()
{
  this->babyMonkey = 0;
  this->adultMonkey = 0;
  this->babySloth = 0;
  this->adultSloth = 0;
  this->babySeaOtter = 0;
  this->adultSeaOtter = 0;
  this->teenMonkey = 0;
  this->teenSloth = 0;
  this->teenSeaOtter = 0;

  for(int i = 0; i < numMonkey; i++)
  {
    if(this->zooMonkey[i].getAge() < 30)
    {
      babyMonkey++;
    }
    else if(this->zooMonkey[i].getAge() >= 1095)
    {
      adultMonkey++;
    }
    else
    {
      teenMonkey++;
    }
  }

  for(int i = 0; i < numSloth; i++)
  {
    if(this->zooSloth[i].getAge() < 30)
    {
      babySloth++;
    }
    else if(this->zooSloth[i].getAge() >= 1095)
    {
      adultSloth++;
    }
    else
    {
      teenSloth++;
    }
  }

  for(int i = 0; i < numSeaOtter; i++)
  {
    if(this->zooSeaOtter[i].getAge() < 30)
    {
      babySeaOtter++;
    }
    else if(this->zooSeaOtter[i].getAge() >= 1095)
    {
      adultSeaOtter++;
    }
    else
    {
      teenSeaOtter++;
    }
  }
}


/*********************************************************************
** Function: welcomeScreen()
** Description: Prints out the welcome message
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::welcomeScreen()
{
  cout << "____________________________________________________" << endl;
  cout << "-------------- Welcome to Zoo Tycoon! --------------" << endl;
  cout << "____________________________________________________" << endl;
}


/*********************************************************************
** Function: animalPrices()
** Description: prints out the individual prices of each animal
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
string Zoo::animalPrices()
{
  return "The cost of each adult species is: \n (1)Monkey, $15,000 \n (2)Sea Otter, $5,000 \n (3)Sloths, $2,000\n (4)If you would not like to make a purchase\n";
}


/*********************************************************************
** Function: addMonkey(int age)
** Description: adds a monkey to the zooMonkey array
** Parameters: age of the monkey to be added
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::addMonkey(int age)
{
  this->numMonkey++;
  Monkey* temp = new Monkey[this->numMonkey];
  for(int i = 0; i < (this->numMonkey - 1); i++)
  {
    temp[i] = this->zooMonkey[i];
  }
  temp[this->numMonkey - 1] = Monkey(age);
  delete[] this->zooMonkey;
  this->zooMonkey = temp;
}


/*********************************************************************
** Function: addSloth(int age)
** Description: adds a monkey to the zooSloth array
** Parameters: age of the sloth to be added
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::addSloth(int age)
{
  this->numSloth++;
  Sloth* temp = new Sloth[this->numSloth];
  for(int i = 0; i < (this->numSloth - 1); i++)
  {
    temp[i] = this->zooSloth[i];
  }
  temp[this->numSloth - 1] = Sloth(age);
  delete[] this->zooSloth;
  this->zooSloth = temp;
}


/*********************************************************************
** Function: addSeaOtter(int age)
** Description: adds a seaotter to the zooSeaOtter array
** Parameters: age of the seaotter to be added
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::addSeaOtter(int age)
{
  this->numSeaOtter++;
  SeaOtter* temp = new SeaOtter[this->numSeaOtter];
  for(int i = 0; i < (this->numSeaOtter - 1); i++)
  {
    temp[i] = this->zooSeaOtter[i];
  }
  temp[this->numSeaOtter - 1] = SeaOtter(age);
  delete[] this->zooSeaOtter;
  this->zooSeaOtter = temp;
}



/*********************************************************************
** Function: eventGenerator()
** Description: picks a random event for the game
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::eventGenerator()
{
  int n = rand() % 4;
  switch(n)
  {
    case 0:
      animalSick();
      break;
    case 1:
      animalBirth();
      break;
    case 2:
      zooBoom();
      break;
    case 3:
    {
      cout << "Nothing special occured today" << endl;
      collectRev();
      break;
    }
  }
}


/*********************************************************************
** Function: animalSick()
** Description: Makes a random animal sick
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::animalSick()
{
  int totalAnimals = numMonkey + numSloth + numSeaOtter;
  if(totalAnimals == 0)
  {
    cout << "It was a cold day today, but luckily you didn't have any animals out!" << endl;
  }
  else
  {
    Animal *arr[totalAnimals];
    for(int i = 0; i < numMonkey; i++)
    {
      arr[i] = &zooMonkey[i];
    }
    for(int i = numMonkey; i < numMonkey + numSloth; i++)
    {
      for(int j = 0; j < numSloth; j++)
      {
        arr[i] = &zooSloth[j];
      }
    }
    for(int i = (numMonkey + numSloth); i < (numMonkey + numSloth + numSeaOtter); i++)
    {
      for(int j = 0; j < numSeaOtter; j++)
      {
        arr[i] = &zooSeaOtter[j];
      }
    }

    int x = rand() % totalAnimals;

    // cout <<"----MONKEY----" << endl;
    // for(int i = 0; i < numMonkey; i++)
    // {
    //   cout << zooMonkey[i].getCost() << endl;
    // }
    // cout <<"----Sloth----" << endl;
    // for(int i = 0; i < numSloth; i++)
    // {
    //   cout << zooSloth[i].getCost() << endl;
    // }
    // cout <<"----Seaoter----" << endl;
    // for(int i = 0; i < numSeaOtter; i++)
    // {
    //   cout << zooSeaOtter[i].getCost() << endl;
    // }

    // for(int i = 0; i < totalAnimals; i++)
    // {
    //   cout << i << " :" << arr[i]->getCost() << endl;
    // }

    Animal *temp = arr[x];

    if(temp->getAge() < 30)
    {
      cout << "A child animal has gotten sick in your zoo! It is going to cost you $" << temp->getCost() << endl;
      if(temp->getCost() > bank)
      {
        cout << "Unfortunately you do not have enough money! So the baby animal has died." << endl;
        switch(temp->getCost())
        {
          case (15000):
            removeMonkey(30);
            break;

          case (5000):
            removeSeaOtter(30);
            break;

          case (2000):
            removeSloth(30);
            break;
        }
      }
      else
      {
        bank -= temp->getCost();
      }
    }
    else
    {
      cout << "An adult animal has gotten sick in your zoo! It is going to cost you $" << (temp->getCost() / 2) << endl;
      if((temp->getCost() / 2) > bank)
      {
        cout << "Unfortunately you do not have enough money! So the animal has died." << endl;
        switch(temp->getCost())
        {
          case (15000):
            removeMonkey(1095);
            break;

          case (5000):
            cout << "call";
            removeSeaOtter(1095);
            break;

          case (2000):
            removeSloth(1095);
            break;
        }
      }
      else
      {
        bank -= (temp->getCost() / 2);
      }
    }

  }
  collectRev();
}



/*********************************************************************
** Function: animalBirth()
** Description: random adult animal will give birth
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::animalBirth()
{
  int totalAdults = adultMonkey + adultSloth + adultSeaOtter;
  if(totalAdults == 0)
  {
    cout << "It was possible that babies could've been born today, but unfortunately you have no adult animals." << endl;
  }
  else
  {
    int arr[totalAdults];
    for(int i = 0; i < adultMonkey; i++)
    {
      arr[i] = 0;
    }
    for(int i = adultMonkey; i < adultSloth + adultMonkey; i++)
    {
      arr[i] = 1;
    }
    for(int i = (adultSloth + adultMonkey); i < (adultSloth + adultMonkey + adultSeaOtter); i++)
    {
      arr[i] = 2;
    }

    // cout << "total: " << totalAdults << endl;

    // for(int i = 0; i < totalAdults; i++)
    // {
    //   cout << "___" << endl;
    //   cout << "[" << arr[i] << "]" << endl;
    //   cout << "___" << endl;
    // }

    int x = rand() % (totalAdults);
    //
    // cout << "Random x birth: " << x << endl;
    //
    int val = arr[x];
    //
    // cout << "value at x: " << val << endl;

    switch(val)
    {
      case 0:
      {
        cout << "Your adult Monkey gave birth to a baby monkey! Congrats!" << endl;
        addMonkey(0);
        break;
      }
      case 1:
      {
        cout << "Your adult Sloth gave birth to 3 babies! Congrats!" << endl;
        addSloth(0);
        addSloth(0);
        addSloth(0);
        break;
      }
      case 2:
      {
        cout << "Your adult Sea Otter gave birth to 2 babies! Congrats!" << endl;
        addSeaOtter(0);
        addSeaOtter(0);
        break;
      }
    }
  }

  collectRev();
}


/*********************************************************************
** Function: zooBoom()
** Description: creates a boom in attendance to the zoo and each monkey earns extra revenue
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::zooBoom()
{
  cout << "A boom in attendance just occured! Each monkey you own has earned extra revenue." << endl;
  int bonusRev = 0;
  for(int i = 0; i < numMonkey; i++)
  {
    this->zooMonkey[i].setbonusRev();
    bonusRev += this->zooMonkey[i].getbonusRev();
  }
  cout << "For your " << numMonkey << " Monkeys, you have received an extra: $" << bonusRev << endl;
  this->bank += bonusRev;
  collectRev();
}


/*********************************************************************
** Function: collectRev()
** Description: Collects revenue from all the animals you own
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::collectRev()
{
  int dayRev = ((numMonkey - babyMonkey) * 1500) + ((numSloth - babySloth) * 100) + ((numSeaOtter - babySeaOtter) * 250);
  dayRev += (babyMonkey * 3000) + (babySloth * 200) + (babySeaOtter * 500);
  cout << "Today, from all of your animals you have gained $" << dayRev << endl;
  this->bank += dayRev;
}


/*********************************************************************
** Function: playerTurn()
** Description: enacapsulates everything that happens during a player turn
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::playerTurn()
{
  cout << "Currently, you bank holds $" << bank << endl;
  increaseAge();
  purchase();
  int x = (rand() % 50) + 75;
  foodCost(x);
  printAnimals();
  eventGenerator();
}


/*********************************************************************
** Function: increaseAge()
** Description: adds a day of age to every animal
** Parameters:none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::increaseAge()
{
  for(int i = 0; i < numMonkey; i++)
  {
    zooMonkey[i].setAge((zooMonkey[i].getAge() + 1));
  }

  for(int i = 0; i < numSloth; i++)
  {
    zooSloth[i].setAge((zooSloth[i].getAge() + 1));
  }

  for(int i = 0; i < numSeaOtter; i++)
  {
    zooSeaOtter[i].setAge((zooSeaOtter[i].getAge() + 1));
  }

}


/*********************************************************************
** Function: foodCost(int percent)
** Description: sets the food cost for every animal
** Parameters: int percent
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::foodCost(int percent)
{
  int totalFoodCost = 0;

  for(int i = 0; i < numMonkey; i++)
  {
    zooMonkey[i].changeFoodCost(percent);
    totalFoodCost += zooMonkey[i].getfoodCost();
  }

  for(int i = 0; i < numSloth; i++)
  {
    zooSloth[i].changeFoodCost(percent);
    totalFoodCost += zooSloth[i].getfoodCost();
  }

  for(int i = 0; i < numSeaOtter; i++)
  {
    zooSeaOtter[i].changeFoodCost(percent);
    totalFoodCost += zooSeaOtter[i].getfoodCost();
  }

  cout << "Total food cost for today changed by a factor of " << percent/100.0 << " today. $" << totalFoodCost <<" was taken out of your bank." << endl;
  this->bank -= totalFoodCost;
}


/*********************************************************************
** Function: purchase()
** Description: prompts the user of what animal they would like to purchase
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::purchase()
{
  cout << "Would you like to purchase any adult animals for today? You can only have 2 adult species." << endl;
  cout << animalPrices();
  string temp;
  cin >> temp;
  while(temp != "1" && temp != "2" && temp != "3" && temp != "4")
  {
    cout << "Please input a valid integer between 1 and 4 : ";
    cout << animalPrices();
    cin >> temp;
  }
  int input = stoi(temp);
  int x = 0;
  do
  {
    while(input != 4 && input != 3 && input != 2 && input != 1)
    {
      cout << animalPrices();
      cout << "Please input a valid integer between 1 and 4 : ";
      cin >> temp;
      input = stoi(temp);
    }

    switch(input)
    {
      case 1:
      {
        //Monkey 15000
        if(adultMonkey == 2 || bank < 15000)
        {
          cout << "Sorry, you either already have 2 adults of this species or you do not have enough money in your bank" << endl;
          input = 5;
        }
        else
        {
          bank -= 15000;
          addMonkey(1096);
          x = 1;
        }
        break;
      }

      case 2:
      //Seaotter 5000
      {
        if(adultSeaOtter == 2 || bank < 5000)
        {
          cout << "Sorry, you either already have 2 adults of this species or you do not have enough money in your bank" << endl;
          input = 5;
        }
        else
        {
          bank -= 5000;
          addSeaOtter(1096);
          x = 1;
        }
        break;
      }
      case 3:
      //Sloth 2000
      {
        if(adultSloth == 2 || bank < 2000)
        {
          cout << "Sorry, you either already have 2 adults of this species or you do not have enough money in your bank" << endl;
          input = 5;
        }
        else
        {
          bank -= 2000;
          addSloth(1096);
          x = 1;
        }
        break;
      }

      case 4:
        x = 1;
    }
  }while(x == 0);
}


/*********************************************************************
** Function: removeMonkey
** Description: removes a monkey from the zooMonkey array
** Parameters: age of monkey to be removed
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::removeMonkey(int age)
{
  int index;
  if(age == 30)
  {
    for(int i = 0; i < numMonkey; i++)
    {
      if(zooMonkey[i].getAge() < 30)
      {
        index = i;
        break;
      }
    }
  }
  else
  {
    for(int i = 0; i < numMonkey; i++)
    {
      if(zooMonkey[i].getAge() > 30)
      {
        index = i;
        break;
      }
    }
  }
  zooMonkey[index] = zooMonkey[numMonkey - 1];
  numMonkey--;
}


/*********************************************************************
** Function: removeSeaOtter
** Description: removes a monkey from the zooSeaOtter array
** Parameters: age of sea otter to be removed
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::removeSeaOtter(int age)
{
  int index;
  if(age == 30)
  {
    for(int i = 0; i < numSeaOtter; i++)
    {
      if(zooSeaOtter[i].getAge() < 30)
      {
        index = i;
        break;
      }
    }
  }
  else
  {
    for(int i = 0; i < numSeaOtter; i++)
    {
      if(zooSeaOtter[i].getAge() > 30)
      {
        index = i;
        break;
      }
    }
  }
  zooSeaOtter[index] = zooSeaOtter[numSeaOtter - 1];
  numSeaOtter--;
}


/*********************************************************************
** Function: removeSloth
** Description: removes a monkey from the zooSloth array
** Parameters: age of Sloth to be removed
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
void Zoo::removeSloth(int age)
{
  int index;
  if(age == 30)
  {
    for(int i = 0; i < numSloth; i++)
    {
      if(zooSloth[i].getAge() < 30)
      {
        index = i;
        break;
      }
    }
  }
  else
  {
    for(int i = 0; i < numSloth; i++)
    {
      if(zooSloth[i].getAge() > 30)
      {
        index = i;
        break;
      }
    }
  }
  zooSloth[index] = zooSloth[numSloth - 1];
  numSloth--;
}


/*********************************************************************
** Function: getBank()
** Description: returns the amount of money in the bank
** Parameters: none
** Pre-Conditions: Zoo object is instantiated
** Post-Conditions: None
*********************************************************************/
int Zoo::getBank()
{
  return this->bank;
}

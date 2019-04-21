#ifndef ZOO_H
#define ZOO_H

#include "animal.hpp"
#include "sloth.hpp"
#include "monkey.hpp"
#include "seaotter.hpp"
#include <string>

using namespace std;

class Zoo
{
  protected:
    int bank;
    Monkey *zooMonkey;
    Sloth *zooSloth;
    SeaOtter *zooSeaOtter;
    int numMonkey;
    int numSloth;
    int numSeaOtter;
    int babyMonkey;
    int adultMonkey;
    int babySloth;
    int adultSloth;
    int babySeaOtter;
    int adultSeaOtter;
    int teenMonkey;
    int teenSloth;
    int teenSeaOtter;

  public:
    Zoo();
    ~Zoo();
    void printAnimals();
    void countAnimals();
    void welcomeScreen();
    string animalPrices();
    void eventGenerator();
    void addMonkey(int age);
    void addSloth(int age);
    void addSeaOtter(int age);
    void animalSick();
    void animalBirth();
    void zooBoom();
    void collectRev();
    void playerTurn();
    void increaseAge();
    void foodCost(int percent);
    void purchase();
    void removeMonkey(int age);
    void removeSeaOtter(int age);
    void removeSloth(int age);
    int getBank();

};

#endif

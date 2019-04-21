#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card
{
  private:
    int rank;  // Should be in the range 1-13.
    int suit;  // Should be in the range 0-3.
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
    Card(int rank, int suit);
    Card();
    ~Card();
    int getSuit();
    int getRank();
    string printSuit();
    string printRank();
    void setSuit(int suit);
    void setRank(int rank);
    string printCard();
};

#endif

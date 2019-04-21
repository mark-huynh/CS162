#ifndef PLAYER_H
#define PLAYER_H

#include "hand.hpp"
#include "card.hpp"

class Player
{
  private:
    Hand hand;
    int* books;  // Array with ranks for which the player has books.
    int n_books;
  public:
    Player();
    Player(Hand h);
    Player(const Player& p);
    void operator=(const Player& p);
    ~Player();
    void printHand();
    void sortHand();
    int getNBooks();
    int* getBooks();
    int getNCards();
    Hand getHand();
    string askCardRank();
    bool checkBooks();
    Card* removeCard(string rank);
    void addCard(Card c);
  // must have constructors, destructor, accessor methods, and mutator methods
};

#endif

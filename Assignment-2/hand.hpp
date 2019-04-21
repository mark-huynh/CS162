#ifndef HAND_H
#define HAND_H

#include "card.hpp"

class Hand
{
  private:
    Card* cards;
    int n_cards;  // Number of cards in the hand.
    Card* remCards;
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
    Hand();
    Hand(int nCards, Card* c);
    Hand(const Hand& h);
    void operator=(const Hand& other);
    ~Hand();
    void sortHand();
    void setCards(Card* c);
    void setNCards(int n);
    void addCard(Card c);
    Card* removeCard(string rank);
    void printHand();
    int getNCards();
    Card* getCards();

};

#endif

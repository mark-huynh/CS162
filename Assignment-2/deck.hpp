#ifndef DECK_H
#define DECK_H


#include "card.hpp"

class Deck
{
  private:
    Card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
    Deck();
    ~Deck();
    Card* getCards();
    int getnCards();
    void setCards(int index, Card c);
    void setnCards(int numCards);
    void printDeck();
    void shuffle();
    Card draw();

};

#endif

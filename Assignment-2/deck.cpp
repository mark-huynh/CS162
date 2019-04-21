#include "deck.hpp"

#include <ctime>
#include <cstdlib>

using namespace std;


/*********************************************************************
** Function: Deck()
** Description: Default constructor for Deck class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Deck object is created
*********************************************************************/
Deck::Deck()
{
  this->n_cards = 51;
  int i = 0;
  int j = 1;
  int k = 0;
  while(i < 52)
  {
    Card t(j, k);
    this->cards[i] = t;
    if(j == 13)
    {
      k++;
      j = 0;
    }
    i++;
    j++;
  }
}


/*********************************************************************
** Function: ~Deck()
** Description: Destructor for Deck object
** Parameters: None
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: Deck object is deallocated
*********************************************************************/
Deck::~Deck()
{
  // Intentially left blank
}


/*********************************************************************
** Function: getCards()
** Description: Returns all cards in the deck
** Parameters: none
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: array of cards in the deck is returned
*********************************************************************/
Card* Deck::getCards()
{
  return this->cards;
}


/*********************************************************************
** Function: getnCards()
** Description: returns the number of cards remaining in deck
** Parameters: none
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: returns the number of cards remaining in deck
*********************************************************************/
int Deck::getnCards()
{
  return this->n_cards;
}


/*********************************************************************
** Function: setCards(int index, Card c)
** Description: sets a card at an area of the deck
** Parameters: index of the deck to be modified and card to be inputted
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: Card at specified index in deck is changed
*********************************************************************/
void Deck::setCards(int index, Card c)
{
  this->cards[index] = c;
}


/*********************************************************************
** Function: setnCards(int numCards)
** Description: sets the number of cards remaining in the deck
** Parameters: number of cards in deck
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: Number of cards in deck is changed
*********************************************************************/
void Deck::setnCards(int numCards)
{
  this->n_cards = numCards;
}


/*********************************************************************
** Function: printDeck()
** Description: prints to console every card in the deck
** Parameters: none
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: prints to console every card in the deck
*********************************************************************/
void Deck::printDeck()
{
  for(int i = 0; i <= this->n_cards; i++)
  {
    cout << i << this->cards[i].printCard() << endl;
  }
  cout << endl;
}


/*********************************************************************
** Function: shuffle()
** Description: Randomizes all cards in the deck
** Parameters: None
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: Random cards in the deck are swapped 1000 times
*********************************************************************/
void Deck::shuffle()
{
  srand(time(NULL));
  for(int i = 0; i < 1000; i++)
  {
    int t = rand()%52;
    int s = rand()%52;
    Card temp = this->cards[s];
    this->cards[s] = this->cards[t];
    this->cards[t] = temp;
  }
}


/*********************************************************************
** Function: draw()
** Description: A card is removed from the top of the deck and returned
** Parameters: none
** Pre-Conditions: Deck object has been instantiated
** Post-Conditions: number of cards in the deck is decrimented and top card is returned
*********************************************************************/
Card Deck::draw()
{
  if(this->n_cards == -1)
  {
    return Card();
  }
  Card top = this->cards[this->n_cards];
  this->n_cards--;
  return top;
}

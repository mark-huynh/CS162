#include "hand.hpp"
#include "card.hpp"

#include <iostream>

using namespace std;


/*********************************************************************
** Function: Hand()
** Description: Default Constructor for Hand Class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Hand Object is created
*********************************************************************/
Hand::Hand() : n_cards(0), cards(NULL)
{
  this->remCards = new Card[20];
}


/*********************************************************************
** Function: Hand(int nCards, Card* c)
** Description: Parametarized Contructor of Hand Class
** Parameters: Number of cards in hand and array of Card objects
** Pre-Conditions: None
** Post-Conditions: Hand Object is created
*********************************************************************/
Hand::Hand(int nCards, Card* c) : n_cards(nCards), cards(c)
{
  this->remCards = new Card[20];
}


/*********************************************************************
** Function: Hand(const Hand& h)
** Description: Copy constructor for hand class
** Parameters: Hand object to be copied
** Pre-Conditions: None
** Post-Conditions: Hand Object is created
*********************************************************************/
Hand::Hand(const Hand& h)
{
  this->n_cards = h.n_cards;
  this->cards = new Card[h.n_cards];
  this->remCards = new Card[20];
  for(int i = 0; i < h.n_cards; i++)
  {
    this->cards[i] = h.cards[i];
  }
  for(int i = 0; i < 20; i++)
  {
    this->remCards[i] = h.remCards[i];
  }

}


/*********************************************************************
** Function: operator=(const Hand& h)
** Description: Assignment overloader for Hand
** Parameters: Hand object to be copied
** Pre-Conditions: None
** Post-Conditions: Hand Object is created
*********************************************************************/
void Hand::operator=(const Hand& h)
{
  this->n_cards = h.n_cards;
  delete[] this->cards;
  this->cards = new Card[h.n_cards];
  for(int i = 0; i < h.n_cards; i++)
  {
    this->cards[i] = h.cards[i];
  }
  delete[] this->remCards;
  this->remCards = new Card[20];
  for(int i = 0; i < 20; i++)
  {
    this->remCards[i] = h.remCards[i];
  }
}


/*********************************************************************
** Function: ~Hand()
** Description: Deallocates hand object
** Parameters: None
** Pre-Conditions: Hand object is created
** Post-Conditions: Hand object is deallocated
*********************************************************************/
Hand::~Hand()
{
  delete[] this->cards;
  delete[] this->remCards;
}



/*********************************************************************
** Function: sortHand()
** Description: Sorts cards in hand in increasing order
** Parameters: None
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: Cards array is ordered in increasing rank order
*********************************************************************/
void Hand::sortHand()
{
  for(int i = 0; i < this->n_cards; i++)
  {
    for(int j = 0; j < this->n_cards; j++)
    {
      if(this->cards[i].getRank() < this->cards[j].getRank())
      {
        Card temp = this->cards[i];
        this->cards[i] = this->cards[j];
        this->cards[j] = temp;
      }
    }
  }
}


/*********************************************************************
** Function: printHand()
** Description: Prints out the cards in a Hand class
** Parameters: None
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: All cards is printed to the console
*********************************************************************/
void Hand::printHand()
{

  sortHand();

  for(int i = 0; i < this->n_cards; i++)
  {
    cout << this->cards[i].printCard() << "";
  }

  cout << endl;
}


/*********************************************************************
** Function: setCards
** Description: Replaces cards in hand array
** Parameters: New hand array
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: Private hand object points to a new Card array
*********************************************************************/
void Hand::setCards(Card* c)
{
  delete[] this->cards;
  this->cards = c;
}


/*********************************************************************
** Function: setNCards(int n)
** Description: numer of cards is changed
** Parameters: number of cards in the hand
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: n_cards is changed to a new int
*********************************************************************/
void Hand::setNCards(int n)
{
  this->n_cards = n;
}


/*********************************************************************
** Function: addCard(Card c)
** Description: adds a card to the card array
** Parameters: Card to be added
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: A card is added to the end of the array
*********************************************************************/
void Hand::addCard(Card c)
{
  this->n_cards++;
  Card* temp = new Card[this->n_cards];
  for(int i = 0; i < (this->n_cards - 1); i++)
  {
    temp[i] = this->cards[i];
  }
  temp[this->n_cards - 1] = c;
  delete[] this->cards;
  this->cards = temp;
}


/*********************************************************************
** Function: getNCards()
** Description: returns the number of cards in the Hand
** Parameters: None
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: number of cards in the Hand is returned
*********************************************************************/
int Hand::getNCards()
{
  return this->n_cards;
}


/*********************************************************************
** Function: getCards()
** Description: returns the card array
** Parameters: none
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: cards array is returned
*********************************************************************/
Card* Hand::getCards()
{
  return this->cards;
}


/*********************************************************************
** Function: removeCard(string rank)
** Description: Removes all cards of a certain rank from the card array
** Parameters: String of the rank to be removed
** Pre-Conditions: Hand Object is instantiated
** Post-Conditions: Array of cards removed is returned
*********************************************************************/
Card* Hand::removeCard(string rank)
{
  int counter = 0;
  Card empty;

  for(int i = 0; i < 20; i++)
  {
    this->remCards[i] = empty;
  }

  for(int i = 0; i < this->n_cards; i++)
  {
    if(this->cards[i].printRank() == rank)
    {
      Card temp = this->cards[i];
      remCards[counter] = temp;
      counter++;
      this->cards[i] = empty;
    }
  }

  // if(counter == 0)
  // {
  //   remCards = NULL;
  // }

  Card* newHand = new Card[this->n_cards - counter];

  int j = 0;

  for(int i = 0; i < this->n_cards; i++)
  {
    if(this->cards[i].getRank() != 0)
    {
      newHand[j] = this->cards[i];
      j++;
    }
  }

  setCards(newHand);

  setNCards(this-> n_cards - counter);


  return remCards;
}

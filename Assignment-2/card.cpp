#include "card.hpp"

using namespace std;


/*********************************************************************
** Function: Card()
** Description: Default constructor of Card Class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Card object is created
*********************************************************************/
Card::Card() : suit(0), rank(0)
{
  // this->suit = 0;
  // this->rank = 0;
}


/*********************************************************************
** Function: Card(int rank, int suit)
** Description: Parametarized constructor for Card class
** Parameters: rank and suit of desired card
** Pre-Conditions: None
** Post-Conditions: Card object is created
*********************************************************************/
Card::Card(int rank, int suit) : rank(rank), suit(suit)
{
  // this->suit = suit;
  // this->rank = rank;
}


/*********************************************************************
** Function: printRank()
** Description: returns the string of the rank of a card
** Parameters: none
** Pre-Conditions: Card object is instantiated
** Post-Conditions: string is returned denoting the rank of a card
*********************************************************************/
string Card::printRank()
{
  switch(this->rank)
  {
    case 1:
    return "Ace";

    case 11:
    return "Jack";

    case 12:
    return "Queen";

    case 13:
    return "King";
  }

  return to_string(this->rank);
}



/*********************************************************************
** Function: printSuit()
** Description: returns the string representing the suit of a card
** Parameters: none
** Pre-Conditions: Card object is instantiated
** Post-Conditions: string representation of suit is returned
*********************************************************************/
string Card::printSuit()
{
  switch(this->suit)
  {
    case 0:
    return "♠";

    case 1:
    return "♦";

    case 2:
    return "♥";

    case 3:
    return "♣";
  }
}


/*********************************************************************
** Function: printCard()
** Description: Returns string of the rank and suit of the card
** Parameters: none
** Pre-Conditions: Card object is instantiated
** Post-Conditions: Returns string of the rank and suit of the card
*********************************************************************/
string Card::printCard()
{
  return "( " + printRank() + " " + printSuit() + " )";
   // string top = "┌──────────┐\n";
   // string x = printRank();
   // string card1 = ("|" + x +"         |\n");
   // if(x == "10")
   // {
   //   card1 = ("|" + x +"        |\n");
   // }
   // string body = "|          |\n";
   // string middle = "|    " + printSuit() + "     |\n";
   // string card2 = ("|         " + x +"|\n");
   // if(x == "10")
   // {
   //   card2 = ("|        " + x +"|\n");
   // }
   // string bottom = "└──────────┘\n";
   // string fullCard = top + card1 + body + middle + body + card2 + bottom;
   // return fullCard;
}


/*********************************************************************
** Function: getSuit()
** Description: returns the suit of the card
** Parameters: none
** Pre-Conditions: Card object is instantiated
** Post-Conditions: returns the integer value of the suit
*********************************************************************/
int Card::getSuit()
{
  return this->suit;
}


/*********************************************************************
** Function: getRank()
** Description: returns the rank of the card
** Parameters: none
** Pre-Conditions: Card object is instantiated
** Post-Conditions: returns the integer value of the rank
*********************************************************************/
int Card::getRank()
{
  return this->rank;
}


/*********************************************************************
** Function: setSuit()
** Description: sets the suit of a card to a desired value
** Parameters: integer of the suit wanted (0 - 3)
** Pre-Conditions: Card object is instantiated
** Post-Conditions: Suit of card is modified
*********************************************************************/
void Card::setSuit(int suit)
{
  while(suit < 0 || suit > 3)
  {
    cout << "Suit is out of range" << endl;
  }
  this->suit = suit;
}


/*********************************************************************
** Function: setRank()
** Description: sets the rank of a card to a desired value
** Parameters: integer of the rank wanted (1 - 13)
** Pre-Conditions: Card object is instantiated
** Post-Conditions: Rank of card is modified
*********************************************************************/
void Card::setRank(int rank)
{
  while(rank < 1 || rank > 13)
  {
    cout << "Suit is out of range" << endl;
  }
  this->rank = rank;
}


/*********************************************************************
** Function: ~Card()
** Description: Destructor of card object
** Parameters: none
** Pre-Conditions: Card object is instantiated
** Post-Conditions: card object is deallocated
*********************************************************************/
Card::~Card()
{
  //intentionally empty
}

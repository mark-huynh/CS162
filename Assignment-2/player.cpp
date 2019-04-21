#include "player.hpp"

using namespace std;

/*********************************************************************
** Function: Player()
** Description: Default constructor for Player class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Player object is created
*********************************************************************/
Player::Player()
{
  this->n_books = 0;
  this->hand = Hand();
  this->books = new int[13];
}

/*********************************************************************
** Function: Player(Hand h)
** Description: Parametarized constructor for Player Class
** Parameters: Hand object
** Pre-Conditions: None
** Post-Conditions: Player object is created
*********************************************************************/
Player::Player(Hand h) : n_books(0)
{
  this->books = new int[13];
  this->hand = h;
}


/*********************************************************************
** Function: Player(const Player& p)
** Description: Copy constructor for Player Class
** Parameters: Player object to be copied
** Pre-Conditions: None
** Post-Conditions: Player object is created
*********************************************************************/
Player::Player(const Player& p)
{
  this->hand = p.hand;
  this->n_books = p.n_books;
  this->books = new int[13];
  for(int i = 0; i < 13; i++)
  {
    this->books[i] = p.books[i];
  }
}


/*********************************************************************
** Function: operator=(const Player& p)
** Description: Assignmet overloader for Player Class
** Parameters: Player object to be copied
** Pre-Conditions: None
** Post-Conditions: Player object is created
*********************************************************************/
void Player::operator=(const Player& p)
{
  this->hand = p.hand;
  this->n_books = p.n_books;
  delete[] this->books;
  this->books = new int[13];
  for(int i = 0; i < 13; i++)
  {
    this->books[i] = p.books[i];
  }
}

/*********************************************************************
** Function: ~Player()
** Description: destructor for Player class
** Parameters: None
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: Player object is deallocated
*********************************************************************/
Player::~Player()
{
  delete[] this->books;
}


/*********************************************************************
** Function: printHand()
** Description: Outputs cards in Hand to console
** Parameters: None
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: Cards in hand is outputted to console
*********************************************************************/
void Player::printHand()
{
  this->hand.printHand();
}

/*********************************************************************
** Function: sortHand()
** Description: Hand is sorted in increasing order of rank
** Parameters: None
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: Hand is sorted in increasing order of rank
*********************************************************************/
void Player::sortHand()
{
  this->hand.sortHand();
}

/*********************************************************************
** Function: getNBooks()
** Description: returns number of books player has
** Parameters: None
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: returns number of books player has
*********************************************************************/
int Player::getNBooks()
{
  return this->n_books;
}

/*********************************************************************
** Function: getBooks()
** Description: returns array of books
** Parameters: none
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: returns array of books
*********************************************************************/
int* Player::getBooks()
{
  return this->books;
}

/*********************************************************************
** Function: getHand()
** Description: returns Hand
** Parameters: none
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: returned Hand
*********************************************************************/
Hand Player::getHand()
{
  return this->hand;
}

/*********************************************************************
** Function: askCardRank()
** Description: prompts the user for what card to ask from opponent
** Parameters: none
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: String of desired card rank is returned
*********************************************************************/
string Player::askCardRank()
{
  string userInput;
  int ifHas = 0;
  do
  {
    cout << "What card would you like to ask from your opponent? :" << endl;
    cin >> userInput;
    for(int i = 0; i < this->hand.getNCards(); i++)
    {
      if(userInput == (this->hand.getCards()[i]).printRank())
      {
        ifHas++;
      }
    }
    if(ifHas < 1)
    {
      cout << "You do not currently have that card in your hand." << endl;
    }
  } while(ifHas < 1);
  return userInput;
}

/*********************************************************************
** Function: getNCards()
** Description: returns number of cards in hand
** Parameters: none
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: number of cards in hand is returned
*********************************************************************/
int Player::getNCards()
{
  return this->hand.getNCards();
}

/*********************************************************************
** Function: checkBooks()
** Description: Checks if player has a book in their hand
** Parameters: none
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: returns true if there is a book in hand and removes book
*********************************************************************/
bool Player::checkBooks()
{
  int check = 0;
  for(int i = 0; i < this->hand.getNCards() - 3; i++)
  {
      if(this->hand.getCards()[i].getRank() == this->hand.getCards()[i + 3].getRank())
      {
        this->books[this->n_books] = this->hand.getCards()[i].getRank();
        string card = this->hand.getCards()[i].printRank();
        Card* temp = removeCard(card);
        //delete[] temp;
        this->n_books++;
        i = 0;
        check++;
      }
  }
  if(check > 0)
  {
    return true;
  }
  return false;
}


/*********************************************************************
** Function: removeCard(string rank)
** Description: removes all cards of a particular rank from a hand
** Parameters: a string of the rank to be removed
** Pre-Conditions: Player Class is instantiated
** Post-Conditions: All cards of the particular rank is removed from the hand
*********************************************************************/
Card* Player::removeCard(string rank)
{
  return this->hand.removeCard(rank);
}

void Player::addCard(Card c)
{
  this->hand.addCard(c);
}

#include "game.hpp"
#include "card.hpp"
#include "hand.hpp"
#include "deck.hpp"
#include "player.hpp"

/*********************************************************************
** Function: Game()
** Description: Default constructor for game class
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: game object is created
*********************************************************************/
Game::Game()
{
  Deck d;
  this->cards = d;
  Player a;
  Player b;
  this->players[0] = a;
  this->players[1] = b;
}

/*********************************************************************
** Function: printPlaterHands()
** Description: Prints hands of both players (for debugging purposes only)
** Parameters: None
** Pre-Conditions: Game object is instantiated
** Post-Conditions: Both player hands are printed to the console
*********************************************************************/
void Game:: printPlayerHands()
{
  this->players[0].printHand();
  this->players[1].printHand();
}

/*********************************************************************
** Function: startGame()
** Description: Instatiates the deck and two players for the game
** Parameters: None
** Pre-Conditions: Game object is instantiated
** Post-Conditions: Deck is shuffled and both players are created
*********************************************************************/
void Game::startGame()
{
  this->cards.shuffle();
  Hand one;
  Hand two;
  for(int i = 0; i < 7; i++)
  {
    one.addCard(this->cards.draw());
    two.addCard(this->cards.draw());
  }

  this->players[0] = Player(one);
  this->players[1] = Player(two);
}

/*********************************************************************
** Function: gameOver()
** Description: returns whether or not the game has ended
** Parameters: None
** Pre-Conditions: Game object is instantiated
** Post-Conditions: Returns true if the game has ended
*********************************************************************/
bool Game::gameOver()
{
  if(this->cards.getnCards() == -1)
  {
    return true;
  }
  return false;
}

/*********************************************************************
** Function: playerTurn()
** Description: Encapsulates everything that the user does during a turn in gofish
** Parameters: none
** Pre-Conditions: Game object is instantiated
** Post-Conditions: User turn will end
*********************************************************************/
void Game::playerTurn()
{
  int k;
  do
  {
    if(this->players[0].getNCards() == 0 && this->cards.getnCards() > -1)
    {
      this->players[0].addCard(this->cards.draw());
    }
    else if(this->cards.getnCards() == -1)
    {
      break;
    }
    if(this->players[0].checkBooks())
    {
      cout << "Congrats! You obtained a book! You now have " << this->players[0].getNBooks() << " books!" << endl;
    }

    cout << "Number of Books you have: " << this->players[0].getNBooks() << endl;
    cout << "Number of Books your opponent has: " << this->players[1].getNBooks() << endl;
    cout << "Number of cards your opponent is holding: " << this->players[1].getNCards() << endl;;
    cout << "Number of cards left in the deck: " << this->cards.getnCards() + 1 << endl;
    cout << "Your hand: " << endl;
    this->players[0].printHand();

    string askedCard = this->players[0].askCardRank();
    Card* takenCards = this->players[1].removeCard(askedCard);
    if(takenCards[0].getRank() == 0)
    {
      cout << "Opponent did not have any " << askedCard << "'s in their hand. Go Fish!" << endl;
      cout << "This is the card that you drew: ";
      Card c = this->cards.draw();
      cout << c.printCard() << endl;
      this->players[0].addCard(c);
      k = 0;
    }
    else
    {
      cout << "Nice choice! This is what you took from your opponent: ";
      int i = 0;
      while(takenCards[i].getRank() != 0)
      {
        this->players[0].addCard(takenCards[i]);
        cout << takenCards[i].printCard() << " ";
        i++;
        k = 1;
      }
      cout << endl;
    }

    //delete[] takenCards;

    cout << "Now this is what your hand looks like: " << endl;

    this->players[0].printHand();

    if(this->players[0].checkBooks())
    {
      cout << "Congrats! You obtained a book! You now have " << this->players[0].getNBooks() << " books!" << endl;
    }

  }while(k == 1);
}


/*********************************************************************
** Function: computerTurn()
** Description: Encapsulates everything a computer should do during a turn in gofish
** Parameters: None
** Pre-Conditions: Game object is instantiated
** Post-Conditions: Computer turn will have ended
*********************************************************************/
void Game::computerTurn()
{
  int k;

  do
  {
    if(this->players[1].getNCards() == 0 && this->cards.getnCards() > -1)
    {
      this->players[1].addCard(this->cards.draw());
    }
    else if(this->cards.getnCards() == -1)
    {
      break;
    }

    cout << "Now the computer is taking their turn..." << endl;
    srand(time(NULL));
    int s;
    if(this->players[1].getHand().getNCards() - 1 == 0)
    {
      s = 0;
    }
    else
    {
      s  = rand() % (this->players[1].getHand().getNCards() - 1);
    }

    Card y = this->players[1].getHand().getCards()[s];
    cout << "The computer has chosen the Card " << y.printRank() << endl;

    Card* takenCards = this->players[0].removeCard(y.printRank());
    if(takenCards[0].getRank() == 0)
    {
      cout << "Fortunately you did not have any " << y.printRank() << "'s in your hand. Go Fish!" << endl;
      Card c = this->cards.draw();
      cout << "Opponent has drawn a card." << endl;
      this->players[1].addCard(c);
      k = 0;
    }
    else
    {
      cout << "Your opponent has taken away these cards from you: ";
      int i = 0;
      while(takenCards[i].getRank() != 0)
      {
        this->players[1].addCard(takenCards[i]);
        cout << takenCards[i].printCard() << " ";
        i++;
      }
      k = 1;
      cout << endl;
    }

    //delete[] takenCards;

    this->players[1].sortHand();

    if(this->players[1].checkBooks())
    {
      cout << "Computer has obtained a book. Now they have " << this->players[1].getNBooks() << " books!" << endl;
    }

}while(k == 1);
}

void Game::winner()
{
  if(this->players[0].getNBooks() > this->players[1].getNBooks())
  {
    cout << "You won the game! Congrats!" << endl;
  }
  else
  {
    cout << "The computer has won the game, darn" << endl;
  }
}

// Mike Kennedy
// ESE 224 - Hangman project

// Game Board: Class responsible for providing user with game interface

#include<iostream>

using namespace std;

class game_board
{
 private:
  int board;
 public:

  // Default constructor
  game_board() {}

  // Functions
  void displayBoard()
    {
      cout << "Displaying board" << endl;
    }
};

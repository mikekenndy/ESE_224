// Mike Kennedy
// ESE 224 - Hangman project

// Game Board: Class responsible for providing user with game interface

#include<iostream>
#include "basicFunctions.cpp"

using namespace std;

class game_board
{
 private:
  int numWrong;
  string phrase;

  // Display hang man
  string hangedMan(string guesses)
  {
    // Empty board looks as follows:
   /*   ___  */
   /*  |   | */
   /*  |     */
   /*  |     */
   /*  |     */
   /*  |     */
   /* ___    */
    string display = "  ___ \n";
    display += " |   |\n";
    // First wrong guess
    if (numWrong > 0)
      display += " |   O\n";
    else
      display += " | \n";
    // Second, third and fourth wrong guess
    if (numWrong > 3)
      display += " |  /|\\\n";
    else if (numWrong >2)
      display += " |  /| \n";
    else if (numWrong > 1)
      display += " |   |\n";
    else
      display += " |\n";
    // Fourth and fifth wrong guesses
    if (numWrong > 5)
      display += " |  / \\\n";
    else if (numWrong > 4)
      display += " |  /\n";
    else
      display += " |\n";

    display += " | \n";
    display += "___\n";

    return display;
  }

  // Format phrase for display
  string formattedPhrase(string guesses)
  {
    string ret = "";
    for (int i = 0; i < phrase.length(); i++)
      {
	// Add spaces if required
	if (phrase[i] == '\r' || phrase[i] == ' ')
	  ret += " ";

	// Correct guesses are displayed
	else if (guesses.find(phrase[i]) != string::npos)
	  ret += phrase[i];
	
	// All other characters are displayed as '_'
	else
	  ret += "_";
      }
    return ret;
  }

  // Display wrong guesses
  string wrongGuesses(string guesses)
  {
    string wrong = "";
    for (int i = 0; i < guesses.length(); i++)
      if (phrase.find(guesses[i]) == string::npos)
	wrong += guesses[i];

    // Set value for number of incorrect guesses
    numWrong = wrong.length();
    return wrong;
  }

  
 public:

  // Default constructor
  game_board()
    {
      this->phrase = "";
    }

  game_board(string phrase)
    {
      this->phrase = phrase;
    }

  // Functions
  void setPhrase(string phrase)
  {
    this->phrase = phrase;
  }

  // Display board to user
  void displayBoard(string guesses)
    {
      string wrong = wrongGuesses(guesses);

      cout << hangedMan(guesses) << endl;
      cout << formattedPhrase(guesses) << endl;
      printMessage("Past guesses: " + wrong, true, true);
      cout << endl;
    }
  
};

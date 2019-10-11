// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class responsible for running hangman game

#include<iostream>
#include<string>
#include"hangman_exceptions.h"
#include"game_board.h"

using namespace std;

class hangman
{
 private:
  int MAX_FAILS = 6;
  game_board board;

  // Variables to track game progress
  string phrase, pastGuesses = "";
  int incorrectGuesses = 0;
  int numSpaces;

  // Processes user guess
  bool containsLetter(string input, char guess)
  {
    return (input.find(guess) != string::npos);
  }

  // Returns number of un-guessed letters remaining in phrase
  int lettersRemaining()
  {
    int remaining = 0;
    for (int i = 0; i < phrase.length(); i++)
      // Do not count spaces
      if(phrase[i] != ' ')	
	if(pastGuesses.find(phrase[i]) == string::npos)
	  remaining++;

    return remaining;
  }
  
 public:

  // Default constructor
  hangman()
    {
      phrase = "default phrase";
      board.setPhrase(phrase);
      
      board.displayBoard("");
    }
  
  // Constructor with phrase input
  hangman(string phrase)
    {
      this->phrase = phrase;
      board.setPhrase(phrase);

      board.displayBoard("");
    }

  string getPhrase() { return phrase; }

  // Processes guesses
  char guessLetter(char guess)
  {
    // Ensure no duplicate guesses
    if (containsLetter(pastGuesses, guess))
      {
	throw CharAlreadyGuessed();
      }

    // Add guess to past guesses
    pastGuesses += guess;
    
    // Check whether phrase contains guess
    if (!containsLetter(phrase, guess))
      incorrectGuesses++;

    board.displayBoard(pastGuesses);
  }

  // Game indicators
  bool gameWon(){return lettersRemaining() == 0;}
  bool gameLost() { return incorrectGuesses == MAX_FAILS; }
  int guessesRemaining() { return MAX_FAILS - incorrectGuesses; }
};

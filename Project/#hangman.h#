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
  int MAX_FAILS = 5;
  
  string phrase, pastGuesses = "";
  int correctGuesses = 0;
  int incorrectGuesses = 0;  

  bool containsLetter(string input, char guess)
  {
    return (input.find(guess) != string::npos);
  }
  
 public:

  // Default constructor
  hangman() { phrase = "practice"; }
  
  // Constructor with phrase input
  hangman(string input) { phrase = input; }

  string getPhrase() { return phrase; }

  // Processes guess
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
    if (containsLetter(phrase, guess))
      {
	cout << "Guess is in phrase" << endl;
	correctGuesses++;	  
      }
    else
      {
	cout << "Guess not present in phrase." << endl;
	incorrectGuesses++;
      }

    cout << "Past guesses: " << pastGuesses << endl;
  }

  // Game indicators
  bool gameWon() { return correctGuesses == phrase.size(); }
  bool gameLost() { return incorrectGuesses == MAX_FAILS; }
  int guessesRemaining() { return MAX_FAILS - incorrectGuesses; }
};

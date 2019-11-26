// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class responsible for running hangman game

#include<string>
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
	bool containsLetter(string input, char guess);

	// Returns number of un-guessed letters remaining in phrase
	int lettersRemaining();

public:
	// Default constructor
	hangman();
	// Constructor with phrase input
	hangman(string phrase);

	string getPhrase();
	// Processes guesses
	void guessLetter(char guess);
	// Game indicators
	bool gameWon();
	bool gameLost();
	int guessesRemaining();
};
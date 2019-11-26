// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class responsible for running hangman game

#include"hangman.h"
#include"hangman_exceptions.h"

// Default constructor
hangman::hangman() {
	phrase = "default phrase";
	board.setPhrase(phrase);

	board.displayBoard("");
}

hangman::hangman(string phrase)
{
	this->phrase = phrase;
	board.setPhrase(phrase);

	board.displayBoard("");
}

bool hangman::containsLetter(string input, char guess)
{
	return (input.find(guess) != string::npos);
}

int hangman::lettersRemaining()
{
	int remaining = 0;
	for (int i = 0; i < phrase.length(); i++)
		// Do not count spaces
		if (phrase[i] != ' ')
			if (pastGuesses.find(phrase[i]) == string::npos)
				remaining++;

	return remaining;
}

string hangman::getPhrase() 
{ 
	return phrase; 
}

void hangman::guessLetter(char guess)
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

bool hangman::gameWon() 
{ 
	return lettersRemaining() == 0; 
}

bool hangman::gameLost() 
{ 
	return incorrectGuesses == MAX_FAILS; 
}

int hangman::guessesRemaining()
{ 
	return MAX_FAILS - incorrectGuesses; 
}
// Mike Kennedy
// ESE 224 - Hangman project

// Game Board: Class responsible for providing user with game interface

#include<string>
using namespace std;

class game_board
{
private:
	int numWrong;
	string phrase;

	// Display hang man
	string hangedMan(string guesses);

	// Format phrase for display
	string formattedPhrase(string guesses);

	// Display wrong guesses
	string wrongGuesses(string guesses);

public:

	// Constructors
	game_board();
	game_board(string phrase);

	// Functions
	void setPhrase(string phrase);

	// Display board to user
	void displayBoard(string guesses);
};

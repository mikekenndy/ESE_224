// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Project description
// Part 1:
// Enable a user to play a game of hangman using C++
// Features:
// - Draw hangman figure
// - Display '_' for unknown characters
// - Display correctly guess character
// 
// Part 2:
//

#include<iostream>
#include"hangman.h"

using namespace std;

int main()
{
  cout << "Creating game..." << endl;

  hangman h("phrase");

  char guess;
  while(true)
    {
      cout << "Enter guess: ";
      cin >> guess;
      try
      	{
      	  h.guessLetter(guess);
	  if (h.gameWon())
	    {
	      cout << "Game won!" << endl;
	      break;
	    }
	  else if(h.gameLost())
	    {
	      cout << "Game lost! :(" << endl;
	      break;
	    }
	  else
	    cout << h.guessesRemaining() << " incorrect guesses remaining!" << endl;
	  
      	}
      catch(CharAlreadyGuessed e)
      	{
      	  cout << "Cannot guess the same letter twice!" << endl;
      	}
    }

  
  return 0;
}

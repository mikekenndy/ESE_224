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

// Remove return character that exists in text file
string removeReturn(string phrase)
{
  string newPhrase = "";
  for (int i = 0; i < phrase.length(); i++)
    if (phrase[i] != '\r')
      newPhrase += phrase[i];
  return newPhrase;
}

bool validInput(string input)
{
  if (input.length() > 1)
    return false;
  
  string invalids = "1234567890,.?!<>/\\'\"@#$%^&*(){}[]_-+=";
  return invalids.find(input) == string::npos;
}

int main()
{
  cout << "Creating game..." << endl;

  string phrase = loadRandomWord("WordList.txt");
  phrase = removeReturn(phrase);
  hangman h(phrase);

  char guess;
  string input;
  
  while(true)
    {
      cout << "Enter guess: ";
      getline(cin, input);
      if(validInput(input))
	{
	  guess = input[0];
	  try
	    {
	      h.guessLetter(guess);
	      if (h.gameWon())
		{
		  cout << "Game won!" << endl;
		  cout << "The correct phrase was '" << h.getPhrase() << "'" << endl;
		  break;
		}
	      else if(h.gameLost())
		{
		  cout << "Game lost! :(" << endl;
		  cout << "The correct phrase was '" << h.getPhrase() << "'" << endl;
		  break;
		}
	      else
		cout << h.guessesRemaining() << " incorrect guesses remaining!" << endl;
	      
	    }
	  catch(CharAlreadyGuessed e)
	    {
	      cout << "Cannot guess the same letter twice!" << endl;
	    }
	  cout << endl;
	}
      else
	cout << "\nError, invalid input, try again" << endl;
    }

  
  return 0;
}



// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Project description
// Part 1:
// Enable a user to play a game of hangman using C++
// Features:
// - Draw hangman figure
// - Display '_' for unknown characters
// - Display correctly guess characters
//
// 
// Part 2:
// all users to sign in  and play game using file 'UserAccountHistory.txt' as database

#include<iostream>
#include"User.h"
#include"hangman.h"
#include"userFunctions.h"

using namespace std;

// ----------------
// GLOBAL VARIABLES
// ----------------
const string invalids = "1234567890,.?!<>/\\'\"@#$%^&*(){}[]_-+=";
const string WORD_BANK = "WordList.txt";
string USER;


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

  return invalids.find(input) == string::npos;
}


void newGame(string username)
{
  string phrase = loadRandomWord(WORD_BANK);
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

  // If user is logged in, update their information in the file
  if(!username.empty())
    updateStats(username, h.gameWon(), h.getPhrase());
}


void displayUserMsg()
{
  cout << endl;
  printMessage("Hello " + USER, true, false);
  printMessage("1. Play a game", true, false);
  printMessage("2. Check your history", false, true);
  cout << endl;
}


void displayGreeting()
{
  cout << endl;
  printMessage("Hangman Game", true, false);
  printMessage("ESE224 Fall 2019", true, false);
  printMessage("Group Members:", true, false);
  printMessage("Mike Kennedy - 108715992", false, false);
  printMessage("1. start a new game (part 1)", true, false);
  printMessage("2. sign in as user (part 2)", false, false);
  printMessage("3. sign in as admin (part 2)", false, true);
  cout << endl;
}


// Handles I/O for users logging into account
string loginUser()
{
  string uname, password;
  
  cout << "Enter username: ";
  getline(cin, uname);
  
  // Validate entered username
  if (isValidUsername(uname))
    {
      cout << "Enter password: ";
      getline(cin, password);
      
      // Validate entered password
      if(isCorrectPassword(uname, password))
	{
	  cout << "\nWelcome " << uname << "!" << endl;
	  USER = uname;
	  return uname;
	}
      else
	cout << "\nIncorrect password." << endl;
    }
  else
    cout << uname << " not found." << endl;
  return NULL;
}


int main()
{
  string input;
  string currentUser;
  char in;
  bool loggedIn = false;

  //
  // Uncomment following section for debugging:
  //
  cout << "-- TEST MODE --" << endl;
  vector<User> user_vector = readAccountHistory();

  for (int i = 0; i < user_vector.size(); i++)
    cout << "User: " << user_vector[i].getUsername() << endl;

  cout << "Login as " << user_vector[0].getUsername() << endl;
  cout << "Password: ";
  string pass;
  getline(cin, pass);
  user_vector[0].login(pass);
  cout << user_vector[0].getUsername() << " streak: " << user_vector[0].getStreak() << endl;
      
  // for(int i = 0; i < 2; i++)
  //   {
  //     cout << "Enter uname: ";
  //     getline(cin, uname);

  //     cout << "PW: ";
  //     getline(cin, pw);

  //     User tmp(uname, pw);
  //     user_vector.push_back(tmp);
  //   }

  // User x = user_vector.front();
  // cout << "Username: " << x.getUsername() << endl;

  // x = user_vector[0];
  // cout << "Username[0]: " << x.getUsername() << endl;
  // x = user_vector[1];
  // cout << "Username[1]: " << x.getUsername() << endl;

  in = 'q';
  // resetFile();
  // string uname, pw;
  // cout << "Create a username: ";
  // getline(cin, uname);
  // cout << "password: ";
  // getline(cin, pw);
  // createNewUser(uname, pw);

  
  // Continue prompting user for input until they quit
  while (in != 'q')
    {
      // Display LOGGED IN menu
      if(loggedIn)
	{
	  displayUserMsg();

	  cout << "Please select a number to continue, enter 'q' to quit: ";
	  getline(cin, input);
	  in = input[0];
	  if(input.length() > 1)
	    in = '0';

	  switch(in)
	    {
	    case '1':
	      newGame(currentUser);
	      break;

	    case '2':
	      displayUser(currentUser);
	      break;

	    case 'q':
	      cout << endl;
	      cout << "Application terminating..." << endl;
	      break;
	      
	    default:
	      cout << endl;
	      cout << "Input not recognized, please try again." << endl;
	      cout << endl;
	    }
	}
      // Display DEFAULT menu
      else
	{
	  displayGreeting();

	  cout << "Please select a number to continue, enter 'q' to quit: ";
	  getline(cin, input);
	  in = input[0];
	  if (input.length() > 1)
	    in = '0';
	
	  switch(in)
	    {
	    case '1':
	      newGame(currentUser);
	      break;
	      
	    case '2':
	      currentUser = loginUser();
	      loggedIn = true;
	      break;
	  
	    case '3':
	      cout << endl;
	      cout << "Sorry, this feature is not yet available." << endl;
	      cout << endl;
	      break;
	  
	    case 'q':
	      cout << endl;
	      cout << "Application terminating..." << endl;
	      break;
	      
	    default:
	      cout << endl;
	      cout << "Input not recognized, please try again." << endl;
	      cout << endl;
	      break;
	    }
	}
    }
    
  return 0;
}



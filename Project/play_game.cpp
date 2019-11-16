// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Original

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

// ----------------
// EXCEPTIONS
// ----------------
// struct InvalidUsername : public exception
// {
//   const char * what () const throw()
//   {
//     return "Username not found.";
//   }
// };

// struct InvalidPassword : public exception
// {
//   const char * what () const throw()
//   {
//     return "Incorrect password.";
//   }
// };




// Remove white spaces and return string without them
string removeWhiteSpaces(string input)
{
  string no_white;
  for (int i = 0; input[i]; i++)
    if (input[i] != ' ')
      no_white += input[i];
  return no_white;
}


// Scrape file and return vector containing all users
vector<User> readAccountHistory()
{
  vector<User> getUsers;
  ifstream userFile;
  userFile.open(USER_HISTORY);
  
  if(userFile.is_open())
    {
      // Variables:
      string line;
      string uname, password, lastplay;
      int wins, losses, winstreak;
      double winpct;

      while(getline(userFile, line))
	{
	  // Get username from line
	  uname = removeWhiteSpaces(line.substr(0,10));
	  if(uname == "Name" || uname == "")  // Skip column titles
	    continue;
	  
	  // Get password from line
	  password = removeWhiteSpaces(line.substr(10,10));

	  // Get wins from line
	  wins = stoi(line.substr(20, 8));

	  // Get losses from line
	  losses = stoi(line.substr(35, 8));

	  // Get winpercent from line
	  winpct = std::stod(line.substr(43, 10));

	  // Get winstreak from line
	  winstreak = stoi(line.substr(46, 12));

	  // Get last play from line
	  lastplay = removeWhiteSpaces(line.substr(58, 12));
	    
	  User user(uname, password, wins, losses, winpct,
		    winstreak, lastplay);
	  getUsers.push_back(user);
	}
      userFile.close();
    }
  else
    cout << "Error: Unable to open file '" << USER_HISTORY << "'" << endl;

  return getUsers;
}


// Remove return character that exists in text file
string removeReturn(string phrase)
{
  string newPhrase = "";
  for (int i = 0; i < phrase.length(); i++)
    if (phrase[i] != '\r')
      newPhrase += phrase[i];
  return newPhrase;
}


// Checks whether user input to menu is valid
bool validInput(string input)
{
  if (input.length() > 1)
    return false;

  return invalids.find(input) == string::npos;
}


// Start a new game of hangman
void newGame(User &user)
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
  if(user.isLoggedIn())
    user.updateHistory(h.getPhrase(), h.gameWon());
}


void displayUserMsg(User user)
{
  cout << endl;
  printMessage("Hello " + user.getUsername(), true, false);
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


void displayHistory(User user)
{
  // Ensure user is logged in
  if(!user.isLoggedIn())
    {
      cout << "Error: User not logged in." << endl;
      return;
    }

  cout << endl;
  cout << "Wins:\t\t" << user.getWins() << endl;
  cout << "Losses:\t\t" << user.getLosses() << endl;
  cout << "Win Percentage:\t" << user.getWinPercent() << endl;
  cout << "Win streak:\t" << user.getStreak() << endl;
  cout << "Last play:\t" << user.getLastPlay() << endl;
}


// Handles I/O for users logging into account
User loginUser(vector<User> user_vector)
{
  string uname, password;
  User user("TEMP", "TEMP");

  // Check valid username
  cout << "Enter username: ";
  getline(cin, uname);
  
  for(int i = 0; i < user_vector.size(); i++)
    {
      if(user_vector[i].getUsername() == uname)
	{
	  user = user_vector[i];
	  break;
	}
    }
  if(user.getUsername() == "TEMP")
    throw InvalidUsername();

  
  // Check valid password
  cout << "Enter password: ";
  getline(cin, password);
      
  user.login(password);
  if(user.isLoggedIn())
    {
      cout << "\nWelcome " << uname << "!" << endl;
      return user;
    }
  else
    throw InvalidPassword();
}


int main()
{
  // resetFile();
  // createNewUser("Mike", "asdf123");
  // createNewUser("Tom", "asdf123");
  // createNewUser("Bill", "asdf123");
  // createNewUser("Jeff", "asdf123");
  string input;
  char in;
  User currentUser("TEMP", "TEMP");
  vector<User> user_vector = readAccountHistory();
  
  // Continue prompting user for input until they quit
  while (in != 'q')
    {
      // Display LOGGED IN menu
      if(currentUser.getUsername() != "TEMP")
	{
	  displayUserMsg(currentUser);

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
	      displayHistory(currentUser);
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
	      try
		{
		  currentUser = loginUser(user_vector);
		}
	      catch (InvalidUsername u)
		{
		  cout << "Invalid username." << endl;
		}
	      catch (InvalidPassword p)
		{
		  cout << "Invalid password." << endl;
		}
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



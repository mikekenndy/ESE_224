// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Functions for handling tasks regarding users
// USER FUNCTIONS:
//
// isValidUsername
// - returns whether username exists in file
//
// displayFile
// - Prints the contents of the file stored in USER_HISTORY
//   line by line


#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>

// ----------
// Exception thrown if user name is taken
// ----------
struct UserAlreadyExists : public exception
{
  const char * what () const throw()
  {
    return "This username is already in use.";
  }
};


const string USER_HISTORY = "UserAccountHistory.txt";


string removeWhiteSpaces(string input)
{
  string no_white;
  for (int i = 0; input[i]; i++)
    if (input[i] != ' ')
      no_white += input[i];
  return no_white;
}

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


void displayFile(string filename)
{
  string line;
  ifstream file;
  file.open(filename);
  if(file.is_open())
    {
      while (getline(file, line))
	{
	  cout << line << endl;
	}
      file.close();
    }
  else
    cout << "Error: Unable to open file '" << filename << "'" << endl;
}


bool isValidUsername(string username)
{  
  ifstream userFile;
  userFile.open(USER_HISTORY);
  if(userFile.is_open())
    {
      string line;
      while (getline(userFile, line))
	{
	  if (line.substr(0, 10).find(username) != string::npos)
	    {
	      userFile.close();
	      return true;
	    }
	}
      userFile.close();
      return false;
    }
  else
    {
      cout << "Unable to open file '" << USER_HISTORY << "', please try again." << endl;
      return false;
    }
}


void displayUser(string username)
{
  // Verify user exists
  if (!isValidUsername(username))
    {
      cout << "User '" << username << "' not found." << endl;
      return;
    }
  
  // Display user stats    
  string line;
  ifstream userFile;
  userFile.open(USER_HISTORY);
  if(userFile.is_open())
    {
      cout << username << " history:" << endl;
      cout << setw(10) << right << "Name" << setw(10) << right << "password";
      cout << setw(8) << right << "Wins" << setw(8) << right << "Losses";
      cout << setw(10) << right << "WinPct" << setw(12) << right << "WinStreak";
      cout << setw(12) << left << " LastPlay" << endl;
      
      while (getline(userFile, line))
	{
	  if (line.substr(0, 10).find(username) != string::npos)
	    {
	      cout << line << endl;
	      break;
	    }
	}
      userFile.close();
    }
  else
    cout << "Error: Unable to open file '" << USER_HISTORY << "'" << endl;
}


void updateStats(string username, bool gameWon, string puzzle)
{
  // Get and store file text
  ifstream userFile;
  userFile.open(USER_HISTORY);
  if(userFile.is_open())
    {
      string file_text, line;
      while(getline(userFile, line))
	{
	  if(line.substr(0,10).find(username) != string::npos)
	    {
	      
	    }
	  else
	    file_text += line + "\n";
	}
      userFile.close();

      cout << "File text:" << endl;
      cout << file_text << endl;
    }
  else
    cout << "Error: Unable to open file '" << USER_HISTORY << "'" << endl;
}


bool isCorrectPassword(string username, string password)
{
  ifstream userFile;
  userFile.open(USER_HISTORY);
  if(userFile.is_open())
    {
      string line;
      while (getline(userFile, line))
	{
	  // Find line with correct username
	  if (line.substr(0, 10).find(username) != string::npos)
	    {
	      if (line.substr(10, 20).find(password) != string::npos)
		{
		  userFile.close();
		  return true;
		}
	      userFile.close();
	      return false;
	    }
	}
    }
  else
    {
      cout << "Unable to open file '" << USER_HISTORY << "', please try again." << endl;
      return false;
    }
}

void createNewUser(string username, string password)
{
  if(isValidUsername(username))
    throw UserAlreadyExists();
  ofstream userFile;
  // ios_base::app = append instead of overwrite
  userFile.open(USER_HISTORY, ios_base::app);
  if (userFile.is_open())
    {
      userFile << endl;
      userFile << setw(10) << right << username << setw(10) << right << password;
      userFile << setw(8) << right << "0" << setw(8) << right << "0";
      userFile << setw(10) << right << "0" << setw(12) << right << "0";
      userFile << setw(12) << left << "-";
      cout << "Wrote: '" << username << "' to " << USER_HISTORY << endl;
      userFile.close();
    }
}


void resetFile()
{
  string input;
  cout << "Are you sure you want to reset this file? (y/n) ";
  getline(cin, input);
  if (input != "y")
    return;
  ofstream userFile;
  userFile.open(USER_HISTORY);
  if(userFile.is_open())
    {
      userFile << setw(10) << right << "Name" << setw(10) << right << "password";
      userFile << setw(8) << right << "Wins" << setw(8) << right << "Losses";
      userFile << setw(10) << right << "WinPct" << setw(12) << right << "WinStreak";
      userFile << setw(12) << left << " LastPlay";

      userFile.close();
      cout << "Reset complete." << endl;
    }
  else
    cout << "Error, unable to open " << USER_HISTORY << endl;
}

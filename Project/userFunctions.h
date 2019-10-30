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
#include<iomanip>
#include<fstream>


const string USER_HISTORY = "UserAccountHistory.txt";


void displayFile(string filename)
{
  string line;

  ifstream file;
  file.open(filename);
  if(file.is_open())
    {
      while (getline(file, line))
	cout << line << endl;
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

void displayUser(string username)
{
  /* ofstream myFile; */
  /* myFile.open(USER_HISTORY); */
  /* myFile << setw(10) << right << "Name" << setw(10) << right << "password"; */
  /* myFile << setw(8) << right << "Wins" << setw(8) << right << "Losses"; */
  /* myFile << setw(10) << right << "WinPct" << setw(12) << right << "WinStreak "; */
  /* myFile << setw(12) << left << "LastPlay" << endl; */

  /* myFile << setw(10) << right << "Mike" << setw(10) << right << "asdf123"; */
  /* myFile << setw(8) << right << "2" << setw(8) << right << "1"; */
  /* myFile << setw(10) << right << "25%" << setw(12) << right << "1 "; */
  /* myFile << setw(12) << left << "fireman" << endl; */
}

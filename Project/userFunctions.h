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


//const string USER_HISTORY = "UserAccountHistory.txt";



/* void displayFile(string filename) */
/* { */
/*   string line; */
/*   ifstream file; */
/*   file.open(filename); */
/*   if(file.is_open()) */
/*     { */
/*       while (getline(file, line)) */
/* 	{ */
/* 	  cout << line << endl; */
/* 	} */
/*       file.close(); */
/*     } */
/*   else */
/*     cout << "Error: Unable to open file '" << filename << "'" << endl; */
/* } */


/* bool isValidUsername(string username) */
/* {   */
/*   ifstream userFile; */
/*   userFile.open(USER_HISTORY); */
/*   if(userFile.is_open()) */
/*     { */
/*       string line; */
/*       while (getline(userFile, line)) */
/* 	{ */
/* 	  if (line.substr(0, 10).find(username) != string::npos) */
/* 	    { */
/* 	      userFile.close(); */
/* 	      return true; */
/* 	    } */
/* 	} */
/*       userFile.close(); */
/*       return false; */
/*     } */
/*   else */
/*     { */
/*       cout << "Unable to open file '" << USER_HISTORY << "', please try again." << endl; */
/*       return false; */
/*     } */
/* } */


/* void displayUser(string username) */
/* { */
/*   // Verify user exists */
/*   if (!isValidUsername(username)) */
/*     { */
/*       cout << "User '" << username << "' not found." << endl; */
/*       return; */
/*     } */
  
/*   // Display user stats     */
/*   string line; */
/*   ifstream userFile; */
/*   userFile.open(USER_HISTORY); */
/*   if(userFile.is_open()) */
/*     { */
/*       cout << username << " history:" << endl; */
/*       cout << setw(10) << right << "Name" << setw(10) << right << "password"; */
/*       cout << setw(8) << right << "Wins" << setw(8) << right << "Losses"; */
/*       cout << setw(10) << right << "WinPct" << setw(12) << right << "WinStreak"; */
/*       cout << setw(12) << left << " LastPlay" << endl; */
      
/*       while (getline(userFile, line)) */
/* 	{ */
/* 	  if (line.substr(0, 10).find(username) != string::npos) */
/* 	    { */
/* 	      cout << line << endl; */
/* 	      break; */
/* 	    } */
/* 	} */
/*       userFile.close(); */
/*     } */
/*   else */
/*     cout << "Error: Unable to open file '" << USER_HISTORY << "'" << endl; */
/* } */


/* /\* void updateStats(string username, bool gameWon, string puzzle) *\/ */
/* /\* { *\/ */
/* /\*   // Get and store file text *\/ */
/* /\*   ifstream userFile; *\/ */
/* /\*   userFile.open(USER_HISTORY); *\/ */
/* /\*   if(userFile.is_open()) *\/ */
/* /\*     { *\/ */
/* /\*       string file_text, line; *\/ */
/* /\*       while(getline(userFile, line)) *\/ */
/* /\* 	{ *\/ */
/* /\* 	  if(line.substr(0,10).find(username) != string::npos) *\/ */
/* /\* 	    { *\/ */
	      
/* /\* 	    } *\/ */
/* /\* 	  else *\/ */
/* /\* 	    file_text += line + "\n"; *\/ */
/* /\* 	} *\/ */
/* /\*       userFile.close(); *\/ */

/* /\*       cout << "File text:" << endl; *\/ */
/* /\*       cout << file_text << endl; *\/ */
/* /\*     } *\/ */
/* /\*   else *\/ */
/* /\*     cout << "Error: Unable to open file '" << USER_HISTORY << "'" << endl; *\/ */
/* /\* } *\/ */


/* bool isCorrectPassword(string username, string password) */
/* { */
/*   ifstream userFile; */
/*   userFile.open(USER_HISTORY); */
/*   if(userFile.is_open()) */
/*     { */
/*       string line; */
/*       while (getline(userFile, line)) */
/* 	{ */
/* 	  // Find line with correct username */
/* 	  if (line.substr(0, 10).find(username) != string::npos) */
/* 	    { */
/* 	      if (line.substr(10, 20).find(password) != string::npos) */
/* 		{ */
/* 		  userFile.close(); */
/* 		  return true; */
/* 		} */
/* 	      userFile.close(); */
/* 	      return false; */
/* 	    } */
/* 	} */
/*     } */
/*   else */
/*     { */
/*       cout << "Unable to open file '" << USER_HISTORY << "', please try again." << endl; */
/*       return false; */
/*     } */
/* } */

void createNewUser(string username, string password)
{
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
      userFile << setw(8) << right << "Wins" << setw(8) << right << "losses";
      userFile << setw(10) << right << "WinPct" << setw(12) << right << "WinStreak";
      userFile << setw(12) << left << " LastPlay";

      userFile.close();
      cout << "Reset complete." << endl;
    }
  else
    cout << "Error, unable to open " << USER_HISTORY << endl;
}

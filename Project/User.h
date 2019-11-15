// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class to handle regular users (non - admin)
// Feature:
// - Cannot access information without logging in

#include"Account.h"
using namespace std;

// User not logged in exception
struct UserNotLoggedIn : public exception
{
  const char * what () const throw()
  {
    return "Cannot access this information without logging in.";
  }
};


class User: public Account
{
 private:
  int wins, losses, win_streak;
  double win_percent;
  string last_play;

 public:

  // Default Constructor
  User(string username, string password)
    {
      this->username = username;
      this->password = password;
      wins = losses = win_streak = 0;
      win_percent = 0;
    }

  // Constructor with parameters
  User(string username, string password, int wins, int losses,
       double win_percent, int win_streak, string last_play)
    {
      this->username = username;
      this-> password = password;
      this->wins = wins;
      this->losses = losses;
      this->win_streak = win_streak;
      this->win_percent = win_percent;
      this->last_play = last_play;
    }

  
  void readHistory()
  {
    cout << "Reading history!" << endl;
  }

  string getUsername(){return this->username;}
  int getWins()
  {
    if (this->loggedin)
      return this->wins;
    throw UserNotLoggedIn();
  }
  int getLosses()
  {
    if (this->loggedin)
      return this->losses;
    throw UserNotLoggedIn();
  }
  int getStreak()
  {
    if (this->loggedin)
      return this->win_streak;
    throw UserNotLoggedIn();
  }
  double getWinPercent()
  {
    if (this->loggedin)
      return this->win_percent;
    throw UserNotLoggedIn();
  }
  string getLastPlay()
  {
    if (this->loggedin)
      return this->last_play;
    throw UserNotLoggedIn();
  }

};

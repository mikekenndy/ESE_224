// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class to handle regular users and administrators
// Feature:
// - Cannot access information without logging in

#include"Account.h"
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;

//const string USER_HISTORY = "C:\\Programming\\C++\\ESE_224\\Project\\Hangman\\UserAccountHistory.txt";
const string USER_HISTORY = "UserAccountHistory.txt";


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
	void writeToFile();
	bool premium;

public:

	// Constructor with only username, password
	User(string username, string password);

	// Constructor with parameters
	User(string username, string password, int wins, int losses,
		double win_percent, int win_streak, string last_play, bool premium);

	void updateHistory(string last_play, bool game_won);
	bool createNewUser(string username, string password);
	void upgradeToPremium();
	bool clearHistory();
	void checkRank(User self, vector<User> allUsers);

	// Getters / setters
	string getUsername();
	int getWins();
	int getLosses();
	int getStreak();
	double getWinPercent();
	string getLastPlay();
	bool isPremium();
};

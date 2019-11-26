// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class to handle regular users and administrators
// Feature:
// - Cannot access information without logging in

#include<iostream>
#include<string>
#include "User.h"
using namespace std;




// Constructor with only username, password
User::User(string username, string password)
{
	this->username = username;
	this->password = password;
	wins = losses = win_streak = 0;
	win_percent = 0;
}


User::User(string username, string password, int wins, int losses,
	double win_percent, int win_streak, string last_play)
{
	this->username = username;
	this->password = password;
	this->wins = wins;
	this->losses = losses;
	this->win_streak = win_streak;
	this->win_percent = win_percent;
	this->last_play = last_play;
}


void User::writeToFile()
{
	// Read file
	ifstream file_read(USER_HISTORY);
	if (!file_read.is_open())
	{
		cout << "Error reading file '" << USER_HISTORY << "'" << endl;
		return;
	}
	string NEW_FILE_TEXT, line;

	while (getline(file_read, line))
		if (line.substr(0, 10).find(this->username) == string::npos)
			NEW_FILE_TEXT += line + "\n";

	file_read.close();

	// Write to file
	ofstream file_write(USER_HISTORY);
	if (!file_write.is_open())
	{
		cout << "Error writing to file '" << USER_HISTORY << "'" << endl;
		return;
	}
	file_write << NEW_FILE_TEXT;
	file_write << setw(10) << right << this->username << setw(10) << right << this->password;
	file_write << setw(8) << right << this->wins << setw(8) << right << this->losses;
	file_write << setw(10) << right << this->win_percent << setw(12) << right << this->win_streak;
	file_write << setw(12) << left << this->last_play;
	file_write.close();
}


void User::readHistory()
{
	cout << "Reading history!" << endl;
}


void User::updateHistory(string last_play, bool game_won)
{
	// Update values
	this->last_play = last_play;
	if (game_won)
	{
		wins++;
		win_streak++;
	}
	else
	{
		losses++;
		win_streak = 0;
	}
	win_percent = ((double)wins / ((double)wins + (double)losses));

	// Write back to file
	writeToFile();
}


// Getters / setters
string User::getUsername() { return this->username; }
int User::getWins()
{
	if (this->loggedin)
		return this->wins;
	throw UserNotLoggedIn();
}
int User::getLosses()
{
	if (this->loggedin)
		return this->losses;
	throw UserNotLoggedIn();
}
int User::getStreak()
{
	if (this->loggedin)
		return this->win_streak;
	throw UserNotLoggedIn();
}
double User::getWinPercent()
{
	if (this->loggedin)
		return this->win_percent;
	throw UserNotLoggedIn();
}
string User::getLastPlay()
{
	if (this->loggedin)
		return this->last_play;
	throw UserNotLoggedIn();
}
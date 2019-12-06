// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Class to handle regular users and administrators
// Feature:
// - Cannot access information without logging in

#include<iostream>
#include<string>
#include<vector>
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
	double win_percent, int win_streak, string last_play, bool premium)
{
	this->username = username;
	this->password = password;
	this->wins = wins;
	this->losses = losses;
	this->win_streak = win_streak;
	this->win_percent = win_percent;
	this->last_play = last_play;
	this->premium = premium;
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

	string p = "";
	if (premium)
		p = "X";

	file_write << NEW_FILE_TEXT;
	file_write << setw(10) << right << this->username << setw(10) << right << this->password;
	file_write << setw(8) << right << this->wins << setw(8) << right << this->losses;
	file_write << setw(10) << right << this->win_percent << setw(1) << left << "%";
	file_write << setw(11) << right << this->win_streak;
	file_write << setw(1) << left << " ";
	file_write << setw(18) << left << this->last_play;
	file_write << setw(8) << right << p;
	file_write.close();
}


void User::updateHistory(string last_play, bool game_won)
{
	// Update values
	this->last_play = last_play;
	if (game_won)
	{
		if (win_streak > 0)
			win_streak++;
		else
			win_streak = 1;
		wins++;
	}
	else
	{
		if (win_streak < 0)
			win_streak--;
		else
			win_streak = -1;
		losses++;
	}
	win_percent = ((double)wins / ((double)wins + (double)losses));

	// Write back to file
	writeToFile();
}

// Method to create new user and add to file
bool User::createNewUser(string username, string password)
{
	if (!admin)
		return false;

	// Ensure user doesn't already exist
	ifstream infile;
	infile.open(USER_HISTORY);
	if (infile.is_open())
	{
		string line;
		while(getline(infile, line))
			if (line.substr(0,10).find(username) != string::npos)
				return false;
	}
	else
		return false;

	ofstream userFile;
	// ios_base::app = append instead of overwrite
	userFile.open(USER_HISTORY, ios_base::app);
	if (userFile.is_open())
	{
		userFile << endl;
		userFile << setw(10) << right << username << setw(10) << right << password;
		userFile << setw(8) << right << "0" << setw(8) << right << "0";
		userFile << setw(11) << right << "0%";
		userFile << setw(11) << right << "0";
		userFile << setw(1) << left << "";
		userFile << setw(18) << left << "-";
		userFile << setw(8) << right << " ";
		userFile.close();
	}
	return true;
}

void User::upgradeToPremium()
{
	premium = true;
	writeToFile();
};
bool User::clearHistory()
{
	if (!premium)
		return false;
	last_play = "'";
	writeToFile();
	return true;
}

void User::checkRank(User self, vector<User> allUsers)
{
	vector<User> inOrder = allUsers;
	User current = allUsers[0];

	double highest;
	int cursor = 0;
	int size = allUsers.size();
	int used[100] = { 0 };
	for (int i = 0; i < allUsers.size(); i++)
	{
		highest = 0;
		for (int j = 0; j < allUsers.size(); j++)
		{
			if (allUsers[j].getWinPercent() >= highest && used[j] != 1)
			{
				highest = allUsers[j].getWinPercent();
				cursor = j;
			}
		}
		used[cursor] = 1;
		inOrder[i] = allUsers[cursor];
	}

	cout << setw(9) << left << "\nRankings ";
	cout << setw(10) << left << "User";
	cout << setw(14) << right << "Win Percentage";
	cout << endl;
	for (int i = 0; i < inOrder.size(); i++)
	{
		cout << setw(9) << left << (i + 1);
		cout << setw(10) << left << inOrder[i].getUsername();
		cout << setw(13) << right << (inOrder[i].getWinPercent() * 100) << "%";
		cout << endl;
	}
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
	return this->win_percent;
}
string User::getLastPlay()
{
	if (this->loggedin)
		return this->last_play;
	throw UserNotLoggedIn();
}
bool User::isPremium() { return premium; };
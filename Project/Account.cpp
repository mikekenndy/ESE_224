// Mike Kennedy - 108715992
// ESE224 - Hangman Project

// Super class to house accounts

#include"Account.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//const string USER_HISTORY = "C:\\Programming\\C++\\ESE_224\\Project\\Hangman\\UserAccountHistory.txt";
const string USER_HISTORY = "UserAccountHistory.txt";


void Account::admin_login(string password)
{
	admin = (ADMIN_PASSWORD == password);
	if (!admin)
		throw InvalidPassword();
}


void Account::logout()
{
	username = "TEMP";
	password = "";
	loggedin = false;
	admin = false;
}


void Account::login(string password) 
{ 
	loggedin = (password == this->password); 
}

bool Account::is_admin()
{
	return admin;
}

bool Account::isLoggedIn()
{
	return loggedin;
}

void Account::resetFile()
{
	if (!admin)
	{
		cout << "Error: This is an administrator privelage.";
		return;
	}
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
		userFile << setw(11) << right << "WinPct" << setw(11) << right << "WinStreak";
		userFile << setw(1) << left << " ";
		userFile << setw(18) << left << " LastPlay";
		userFile << setw(8) << right << " Premium";

		userFile.close();
		cout << "Reset complete." << endl;
	}
	else
		cout << "Error, unable to open " << USER_HISTORY << endl;
}

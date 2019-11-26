// Mike Kennedy - 108715992
// ESE224 - Hangman Project

// Super class to house accounts

#include "Account.h"
#include<iostream>
using namespace std;


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
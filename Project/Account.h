// Mike Kennedy - 108715992
// ESE224 - Hangman Project

// Super class to house accounts

#include<string>
using namespace std;

// ----------------
// EXCEPTIONS
// ----------------
struct InvalidUsername : public exception
{
	const char* what() const throw()
	{
		return "Username not found.";
	}
};

struct InvalidPassword : public exception
{
	const char* what() const throw()
	{
		return "Incorrect password.";
	}
};


class Account
{
 private:
	 string ADMIN_PASSWORD = "Password";  
 protected:
	 string username;
	 string password;
	 bool loggedin = false;
	 bool admin = false;  
 public:
	 void admin_login(string password);
	 void logout();
	 void login(string password);
	 bool is_admin();
	 virtual bool isLoggedIn();  
};

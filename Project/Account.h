// Mike Kennedy - 108715992
// ESE224 - Hangman Project

// Super class to house accounts

using namespace std;

// ----------------
// EXCEPTIONS
// ----------------
struct InvalidUsername : public exception
{
  const char * what () const throw()
  {
    return "Username not found.";
  }
};

struct InvalidPassword : public exception
{
  const char * what () const throw()
  {
    return "Incorrect password.";
  }
};




class Account
{
 protected:
  string username;
  string password;
  bool loggedin = false;
  
 public:  
  virtual void login(string password)    
  {
    if(password == this->password)
      loggedin = true;
    else
      loggedin = false;
  }

  virtual bool isLoggedIn(){return loggedin;}    
  
};

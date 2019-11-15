// Mike Kennedy - 108715992
// ESE224 - Hangman Project

// Super class to house accounts

using namespace std;

class Account
{
 protected:
  string username;
  string password;
  bool loggedin;
  
 public:  
  virtual void login(string password)    
  {
    if(password == this->password)
      loggedin = true;
    else
      loggedin = false;
  }    
  
};

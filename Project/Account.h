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
 private:
  string ADMIN_PASSWORD = "Password";
  
 protected:
  string username;
  string password;
  bool loggedin = false;
  bool admin = false;
  
 public:  
  virtual void admin_login(string password)
  {
    admin = (ADMIN_PASSWORD == password);
    if (!admin)
      throw InvalidPassword();
  }

  virtual void logout()
  {
    username = "TEMP";
    password = "";
    loggedin = false;
    admin = false;
  }


  virtual void login(string password){loggedin = (password == this->password);}
  virtual bool is_admin(){return admin;}
  virtual bool isLoggedIn(){return loggedin;}    
  
};

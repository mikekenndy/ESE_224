// Mike Kennedy - 108715992
// ESE 224 - Hangman Project

// Exceptions to handle illegal cases in hangman game

#include <iostream>
#include <exception>
using namespace std;

struct CharAlreadyGuessed : public exception
{
  const char * what () const throw()
  {
    return "Cannot guess the same character twice.";
  }
};

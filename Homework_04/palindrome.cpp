//Mike Kennedy - 108715992
//ESE224 - Homework 04
//Problem 01 - Determine whether a string is a palindrome using
//              a queue or a stack

#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;


// Prompts user to enter a string and returns the value entered
string getUserInput()
{
  cout << "Enter a string: ";
  string input;
  getline(cin, input);
  return input;
}


// Takes a string as a parameter and returns it formatted:
//  - all lowercase
//  - without spaces
//  - without punctuation
string removeFormatting(string input)
{
  string fixed = "";
  
  // String of values to ignore in input string
  string ignore = "1234567890!@#$%^&*()-_=+,./<>?;:'\"\\[{}]`~ \n\t\r\0";

  for(char c : input)
    {
      if (ignore.find(c) == string::npos)
	{
	  fixed += tolower(c);
	}
    }


  return fixed;
}


// Takes a string and returns whether or not it is a palindrome
bool isPalindrome(string palindrome)
{
  // Build palindrome stack
  stack <char> palStack;
  for (char c : palindrome)
    palStack.push(c);

  // Build palindrome queue
  queue <char> palQueue;
  for (char c : palindrome)
    palQueue.push(c);

  char q, s;
  for (int i = 0; i < palindrome.length(); i++)
    {
      s = palStack.top();
      palStack.pop();

      q = palQueue.front();
      palQueue.pop();

      if ( q != s)
	return false;
    }
  return true;
}

int main()
{
  string input = getUserInput();

  if (isPalindrome(removeFormatting(input)))
    cout << "'" << input << "' is a palindrome!" << endl;
  else
    cout << "'" << input << "' is NOT a palindrome." << endl;

  return 0;
}

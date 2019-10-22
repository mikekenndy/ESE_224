//Mike Kennedy - 108715992
//ESE224 - Homework 03
//Problem 02 Averaging Golf scores

#include <iostream>
#include <vector>

using namespace std;

const int MAX_SCORES = 10;

// Used to ensure scores entered by user are valid
bool validInput(string input)
{
  string validChars = "-0123456789";
  for (char c : input)
    if (validChars.find(c) == string::npos)
      return false;
	
  return !input.empty() && input != " ";
}

// Method to prompt the user to input ten scores
//  and returns them in a vector
vector<int> getScores()
{
  vector<int> scores;
  string stringScore;
  int intScore;
  
  cout << "Enter up to 10 golf scores, type '-1' to terminate." << endl;
  for(int i = 0; i < MAX_SCORES; i++)
    {
      do
	{
	  cout << "Score " << i + 1 << ": ";
	  getline(cin, stringScore);
	  if (!validInput(stringScore))
	    cout << "Invalid input, please try again." << endl;
	}
      while(!validInput(stringScore));

      // Convert input to integer
      intScore = stoi(stringScore);
      
      // Terminate loop if exit condition is met
      if (intScore == -1)
	break;
      scores.push_back(intScore);
    }

  return scores;
}

// Averages all values within a vector and
//  returns that average
double averageScore(vector<int> scores)
{
  double sum = 0;
  for (int x : scores)
    sum += x;
  return sum/scores.size();
}

// Takes score vector and average score and
//  displays values formatted for the user
void display(vector<int> scores, double average)
{
  cout << "Displaying all " << scores.size() << " golf scores:" << endl;
  for (int x : scores)
    cout << x << " ";
  cout << endl;
  cout << "The average score was " << average << endl;
}

int main()
{
  vector<int> userInput = getScores();
  display(userInput, averageScore(userInput));
  
  return 0;
}

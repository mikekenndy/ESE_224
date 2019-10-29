//Mike Kennedy - 108715992
//ESE224 - Homework 03
//Problem 04 Find average value of a 2d vector

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string filename = "power1.dat";
const int NUM_DAYS = 7;
const int NUM_WEEKS = 10;

  
// Read the values from a file and return them
//  in a 2d vector
vector<vector<double>> getValues()
{
  vector<vector<double>> power(NUM_WEEKS, vector<double>(NUM_DAYS));
  double val;

  ifstream powerFile (filename);
  if (powerFile.is_open())
    {
      int day = 0, week = 0; // used for placing values into vector

      // Loop through file and populate vector with appropriate
      //  values sorted by week
      while(powerFile >> val)
	{
	  power[week][day] = val;
	  day++;

	  // Reset the day and week when the end of
	  //  each week is reached
	  if ( day == NUM_DAYS )
	    {
	      day = 0;
	      week++;
	    }
	}
      powerFile.close();
    }

  return power;
  
}

// Loops through all values of vector 'vals' and
//  returns a double with the value of the average
double avgVec(vector<vector<double>> vals)
{
  double sum = 0;
  for (int i = 0; i < vals.size(); i++)
      for (double x : vals[i])
	sum += x;

  return sum / (vals.size() * vals[0].size());
}


int main()
{
  cout << "Getting data from " << filename << "..." << endl << endl;

  // Declare 2d vector and load power values into it from file
  vector<vector<double>> power = getValues();

  double average = avgVec(power);

  cout << "The average value of the 2D vector read from ";
  cout << filename << " is: " << average << endl;
  return 0;
}

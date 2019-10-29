//Mike Kennedy - 108715992
//ESE224 - Homework 03
//Problem 03 Finding and displaying minimum power outputs

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const string filename = "power1.dat";
const int NUM_DAYS = 7;
const int NUM_WEEKS = 10;


// Reads values from file and returns them
//  in a 2d vector organized by each day within the week
vector<vector<double>> getPower()
{
  vector<vector<double>> power(NUM_WEEKS, vector<double>(NUM_DAYS));
  double val;

  ifstream powerFile (filename);
  if (powerFile.is_open())
    {      
      int day = 0, week = 0; // used for placing values in vector

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

// Loops through the 2d vector and displays the days with the lowest
//  power output from each week to the user
void displayMin(vector<vector<double>> power)
{
  double dayPower;
  int lowestDay;

  // Loop through each week
  for (int week = 0; week < NUM_WEEKS; week++)
    {
      dayPower = power[week][0];
      lowestDay = 0;

      // Loop through each day of the week
      for (int day = 0; day < NUM_DAYS; day++)
	{
	  if (power[week][day] < dayPower)
	    {
	      dayPower = power[week][day];
	      lowestDay = day;
	    }	  
	}

      // Display lowest power output in current week
      cout << "The lowest power in week ";
      cout << (week + 1) << " was " << dayPower;
      cout << " on day " << (lowestDay + 1) << endl;
    }
}

int main()
{
  cout << "Getting data from " << filename << "..." << endl << endl;

  // Declare 2d vector and load power values into it from file
  vector<vector<double>> power = getPower();

  // Call method to display appropriate values to the user
  displayMin(power);  

  return 0;
}

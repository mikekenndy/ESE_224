// Mike Kennedy - 108715992
// ESE 224 - Homework 02

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

// -----
// Opens file Q1.txt and returns values from inside
// -----
string readFile()
{
  ifstream myfile ("Q1.txt");
  string fileText = "";
  if (myfile.is_open())
    {
      string line;
      while (getline (myfile, line))
	fileText += line + "\n";
      myfile.close();
    }
  else
    cout << "Unable to open file\n";
  
  return fileText;
}

// -----
// Takes "coded" input format and returns equivalent double
// -----
double convertToDouble(string str)
{
  bool negative = false;
  string format = "";

  // Loop through string and remove unnecessary characters
  for (int i = 0; i < str.size(); i++)
    {
      if (str[i] == '1'
	  || str[i] == '2'
	  || str[i] == '3'
	  || str[i] == '4'
	  || str[i] == '5'
	  || str[i] == '6'
	  || str[i] == '7'
	  || str[i] == '8'
	  || str[i] == '9'
	  || str[i] == '0'
	  || str[i] == '.')
	format += str[i];
      else if(str[i] == '(')
	negative = true;
    }

  // convert string to double value and convert to negative if in parenthesis
  double val = atof(format.c_str());

  if(negative)
    val *= -1;
    	
  return val;
}

// -----
// Takes single line of input and converts "coded" values into doubles
// -----
double * formatNums(string input)
{
  // --- PART 1 ---
  // Break up string into elements
  
  // Find number of seperate numbers in string
  int numElements = 1;
  for (int i = 0; i < input.size(); i++)
    if (input[i] == ' ')
      numElements++;

  // String array to hold each element
  string strDollarVal[numElements];

  // Populate string array
  int entry = 0;
  for (int i = 0; i < input.size(); i++)
    {
      if (input[i] == ' ')
	entry++;
      else
	strDollarVal[entry] += input[i];
    }

  
  // --- PART 2 --
  // Convert string elements into double values

  // double array to hold dolar values
  double* doubleDollarVal = new double[numElements];
  
  for (int i = 0; i < numElements; i++)
    doubleDollarVal[i] = convertToDouble(strDollarVal[i]);

  return doubleDollarVal;
}

int main()
{
  string o = readFile();
  double* vals = formatNums(o);

  // Printing values:
  for (int i = 0; i < sizeof(vals)/2; i++)
    {
      cout << "Val " << i << ": " << vals[i] << "\n";
    }


  return 0;
}



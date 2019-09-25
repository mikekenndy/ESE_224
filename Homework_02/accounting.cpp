// Mike Kennedy - 108715992
// ESE 224 - Homework 02

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;

// -----
// Opens file Q1.txt and returns values from inside
// -----
string readFile(string fileName)
{
  ifstream myfile (fileName);
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
vector<double> formatNums(string input)
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
  vector<double> doubleDollarVal;
  // double* doubleDollarVal = new double[numElements];

  for (int i = 0; i < numElements; i++)
    doubleDollarVal.push_back(convertToDouble(strDollarVal[i]));

  return doubleDollarVal;
}

// -----
// Function to create a new file and write formatted values into it
// -----
void writeToFile(string fileName, vector<double> values)
{
  ofstream outFile;
  outFile.open (fileName);
  for (vector<int>::size_type i = 0; i < values.size(); i++)
    outFile << values[i] << " ";
  outFile << endl;
  outFile.close();
}

int main()
{
  string inFile = "Q1.txt";
  string input = readFile(inFile);  // Get values from text file
  vector<double> values = formatNums(input);  // Convert text file into double values

  string fileName = "formattedValues.txt";
  writeToFile(fileName, values);  // Write new values into new text file

  return 0;
}



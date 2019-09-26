// Mike Kennedy - 108715992
// ESE 224 - Homework 2 Q3

#include <iostream>
using namespace std;

void makeUpper(string &input)
{
  for (int i = 0; i < input.size(); i++)
    input[i] = toupper(input[i]);
}

int main()
{
  string input;
  cout << "Enter a string to be converted to upper case." << endl;
  cout << "Press 'q' to quit" << endl;
  
  while(input != "Q")
    {
      cout << "Input: ";
      getline(cin, input);
      makeUpper(input);
      cout << "Upper case string: " << input << endl << endl;
    }

  cout << "Program terminating." << endl;
  return 0;
}

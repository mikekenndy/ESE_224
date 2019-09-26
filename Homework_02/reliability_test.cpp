// Mike Kennedy - 108715992
// ESE 225 - Homework 2 Q4

#include <iostream>
#include <time.h>
using namespace std;

// Random float generator from textbook
double rand_float(double a, double b)
{
  return ((double)rand()/RAND_MAX)*(b-a) + a;
}

// Simulates each component with a 95% oass rate
bool simPass()
{
  return rand_float(0, 1) <= 0.95;
}

// Simulates the design shown in the figure shown in problem 4
bool testPass()
{
  bool c1, c2, c3, c4;
  c1 = simPass();
  c2 = simPass();
  c3 = simPass();
  c4 = simPass();

  return (c1 || c2) || (c3 && c4);
}

int main()
{
  // Conduct test with all probabilities set to 95%
  int passCount = 0, numTrials = 5000;
  for (int i = 0; i < numTrials; i++)
    {
      if(testPass())
  	passCount++;
    }

  double percent = ((double) passCount / numTrials) * 100;

  cout << "Passed " << percent << "% of tests." << endl;
  
  return 0;
}

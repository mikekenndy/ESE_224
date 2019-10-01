// Mike Kennedy - 108715992
// Homework 2 - Question 2

#include <iostream>
using namespace std;

double harmonicMean(double x, double y) {return (2 * x * y) / (x + y);}

int main()
{
  cout << "Enter a pair of doubles\nThe program will terminate when the harmonic mean of the numbers is equal to 0." << endl;
  double mean = -1;
  double x, y;
  while (mean != 0)
    {
      cout << "Enter first number: ";
      cin >> x;
      cout << "Enter second number: ";
      cin >> y;
      mean = harmonicMean(x, y);
      cout << "The harmonic mean of " << x << " and " << y << " is: " << mean << endl;
      cout << endl;
    }
  cout << "Harmonic mean is zero, program terminating." << endl;
  return 0;
}

// Mike Kennedy - 108715992
// ESE224 - Homework 03
// Problem 01 Sorting a vector

#include <iostream>
#include <vector>

using namespace std;

// Function to sort a vector of unknown size in
//  DESCENDING order, returns the sorted function
vector<int> vectorSort(vector<int> vec)
{
  vector<int> desc;
  desc = sort(vec.begin(), vec.end());
  return desc;
}

int main()
{
  cout << "Hello" << endl;
  
  vector<int> test{2, 10, 4, 15, 8, -1};

  cout << "Sorting test..." << endl;
  vector<int> sort = vectorSort(test);

  cout << "test: " << endl;
  for (int x : test)
    cout << x << " ";
  cout << endl;

  cout << "Sort: " << endl;
  for (int x : sort)
    cout << x << " ";
  cout << endl;
  
  return 0;
}

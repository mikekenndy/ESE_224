// Mike Kennedy - 108715992
// ESE224 - Homework 03
// Problem 01 Sorting a vector

#include <iostream>
#include <vector>

using namespace std;

// Test vector for sorting and searching
const vector<int> test{29, 32, 20, 78, 31};

// Method to swap two values in a vector
void swap(int loc1, int loc2, vector<int> &vec)
{
  int temp = vec[loc1];
  vec[loc1] = vec[loc2];
  vec[loc2] = temp;
}


// Function to sort a vector of unknown size in
//  DESCENDING order, returns the sorted function
vector<int> vectorSort(vector<int> vec)
{
  vector<int> desc = vec;

  for (int x = 0; x < desc.size(); x++)
    {
      int numSwaps = 0;
      for (int y = x; y < desc.size(); y++)
	{
	  // Swap numbers if they are out of order
	  if (desc[x] < desc[y])
	    {
	      numSwaps++;
	      swap(x, y, desc);
	    }	      
	}
      // Stop sorting if vector is sorted
      // if (numSwaps == 0)
      // 	break;
    }
  
  return desc;
}

// Searches input vector for a specific value
//  returns true if it is found, otherwise false
bool containsVal(vector<int> vec, int val)
{
  int middle = vec.size() / 2;

  if (vec.size() == 1)
    return false;
  
  // Return true if value is found
  if (vec[middle] == val)
    return true;

  // Check top half or vector if value is greater than center
  if (val > vec[middle])
    {
      vector<int> top (&vec[0], &vec[middle]);
      return containsVal (top, val);
    }

  // Check bottom half or vector if value is greater than center
  if (val < vec[middle])
    {
      vector<int> bot (&vec[middle], &vec[vec.size()]);
      return containsVal (bot, val);
    }
    
  return true;
}


int main()
{
  // cout << "Sorting test..." << endl;
  // vector<int> sort = vectorSort(test);

  // cout << endl;
  // cout << "initial vector: " << endl;
  // for (int x : test)
  //   cout << x << " ";
  // cout << endl;

  // cout << endl;
  // cout << "Sorted vector: " << endl;
  // for (int x : sort)
  //   cout << x << " ";
  // cout << endl;


  cout << "Enter a value to search for: ";
  int search;
  cin >> search;
  if (containsVal(vectorSort(test), search))
    cout << search << " is in the vector!" << endl;
  else
    cout << search << " was not found in the vector." << endl;
  
  return 0;
}

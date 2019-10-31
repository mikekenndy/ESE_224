//Mike Kennedy - 108715992
//ESE224 - Homework 04
// Problem 02 - Reverse a vector

#include<iostream>
#include<vector>
using namespace std;


// Function to reverse order of integer vector
vector<int> reverse(vector<int> v)
{
  vector<int> rev;
  for(int i = v.size(); i > 0; i--)
    rev.push_back(v[i-1]);
  return rev;
}

// Function to reverse order of char vector
vector<char> reverse(vector<char> v)
{
  vector<char> rev;
  for(int i = v.size(); i > 0; i--)
    rev.push_back(v[i-1]);
  return rev;
}

// Function to reverse order of double vector
vector<double> reverse(vector<double> v)
{
  vector<double> rev;
  for(int i = v.size(); i > 0; i--)
    rev.push_back(v[i-1]);
  return rev;
}

// Function to reverse order of float vector
vector<float> reverse(vector<float> v)
{
  vector<float> rev;
  for(int i = v.size(); i > 0; i--)
    rev.push_back(v[i-1]);
  return rev;
}

// Function to reverse order of bool vector
vector<bool> reverse(vector<bool> v)
{
  vector<bool> rev;
  for(int i = v.size(); i > 0; i--)
    rev.push_back(v[i-1]);
  return rev;
}

int main()
{
  // Test <int> vector
  vector<int> int_vec = {1, 4, 2, 3, 6, 5};
  vector<int> int_rev;

  // Test <char> vector
  vector<char> char_vec = {'c', 'f', 'a', 'b'};
  vector<char> char_rev;

  // Test <double> vector
  vector<double> double_vec = {1.1, 2.2};
  vector<double> double_rev;

  // Test <float> vector
  vector<float> float_vec = {1.81, 2.989, -0.123};
  vector<float> float_rev;

  // Test <bool> vector
  vector<bool> bool_vec = {true, false, true};
  vector<bool> bool_rev;
  
  int_rev = reverse(int_vec);
  char_rev = reverse(char_vec);
  double_rev = reverse(double_vec);
  float_rev = reverse(float_vec);
  bool_rev = reverse(bool_vec);

  cout << "Original int vector: ";
  for (int i : int_vec)
    cout << i;
  cout << "\nReversed int vector: ";
  for (int i : int_rev)
    cout << i;
  cout << endl << endl;

  cout << "Original char vector: ";
  for (char c : char_vec)
    cout << c;
  cout << "\nReversed char vector: ";
  for (char c: char_rev)
    cout << c;
  cout << endl << endl;

  cout << "Original double vector: ";
  for (double d:double_vec)
    cout << d << " ";
  cout << "\nReversed double vector: ";
  for (double d:double_rev)
    cout << d << " ";
  cout << endl << endl;

  cout << "Original float vector: ";
  for (float f:float_vec)
    cout << f << " ";
  cout << "\nReversed float vector: ";
  for (float f:float_rev)
    cout << f << " ";
  cout << endl << endl;

  cout << "Original bool vector: ";
  for (bool b:bool_vec)
    cout << b << " ";
  cout << "\nReversed bool vector: ";
  for(bool b:bool_rev)
    cout << b << " ";
  cout << endl;
  
  return 0;
}

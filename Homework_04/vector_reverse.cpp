//Mike Kennedy - 108715992
//ESE224 - Homework 04
// Problem 02 - Reverse a vector

#include<iostream>
#include<vector>
using namespace std;


// Function to reverse order of integer vector
void reverse(vector<int> &v)
{
  vector<int> rev = v;
  v.clear();
  for(int i = rev.size(); i > 0; i--)
    v.push_back(rev[i-1]);
}

// Function to reverse order of char vector
void reverse(vector<char> &v)
{
  vector<char> rev = v;
  v.clear();
  for(int i = rev.size(); i > 0; i--)
    v.push_back(rev[i-1]);
}

// Function to reverse order of double vector
void reverse(vector<double> &v)
{
  vector<double> rev = v;
  v.clear();
  for(int i = rev.size(); i > 0; i--)
    v.push_back(rev[i-1]);
}

// Function to reverse order of float vector
void reverse(vector<float> &v)
{
  vector<float> rev = v;
  v.clear();
  for(int i = rev.size(); i > 0; i--)
    v.push_back(rev[i-1]);
}

// Function to reverse order of bool vector
void reverse(vector<bool> &v)
{
  vector<bool> rev = v;
  v.clear();
  for(int i = rev.size(); i > 0; i--)
    v.push_back(rev[i-1]);
}

int main()
{
  // Test <int> vector
  vector<int> int_vec = {1, 4, 2, 3, 6, 5};

  // Test <char> vector
  vector<char> char_vec = {'c', 'f', 'a', 'b'};

  // Test <double> vector
  vector<double> double_vec = {1.1, 2.2};

  // Test <float> vector
  vector<float> float_vec = {1.81, 2.989, -0.123};

  // Test <bool> vector
  vector<bool> bool_vec = {true, true, false};
  
  cout << "Original int vector: ";
  for (int i : int_vec)
    cout << i;
  cout << "\nReversed int vector: ";
  reverse(int_vec);
  for (int i : int_vec)
    cout << i;
  cout << endl << endl;

  cout << "Original char vector: ";
  for (char c : char_vec)
    cout << c;
  cout << "\nReversed char vector: ";
  reverse(char_vec);
  for (char c: char_vec)
    cout << c;
  cout << endl << endl;

  cout << "Original double vector: ";
  for (double d:double_vec)
    cout << d << " ";
  cout << "\nReversed double vector: ";
  reverse(double_vec);
  for (double d:double_vec)
    cout << d << " ";
  cout << endl << endl;

  cout << "Original float vector: ";
  for (float f:float_vec)
    cout << f << " ";
  cout << "\nReversed float vector: ";
  reverse(float_vec);
  for (float f:float_vec)
    cout << f << " ";
  cout << endl << endl;

  cout << "Original bool vector: ";
  for (bool b:bool_vec)
    cout << b << " ";
  cout << "\nReversed bool vector: ";
  reverse(bool_vec);
  for(bool b:bool_vec)
    cout << b << " ";
  cout << endl;
  
  return 0;
}

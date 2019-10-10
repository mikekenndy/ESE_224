#include "basicFunctions.h"

void printMessage(string message, bool printTop = true, bool printBottom = true)
{
	if (printTop)
	{
		cout << "+---------------------------------+" << endl;
		cout << "|";
	}
	else
	{
		cout << "|";
	}
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();

	if (printBottom)
	{
		cout << "|" << endl;
		cout << "+---------------------------------+" << endl;
	}
	else
	{
		cout << "|" << endl;
	}
}

string loadRandomWord(string path)
{
	srand(time(0));
	string word;
	vector<string> v;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, word))
			v.push_back(word);
		word = v[rand() % v.size()];
		file.close();
	}
	return word;
}

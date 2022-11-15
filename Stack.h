
#include <string>
#include <iostream>
#include <time.h>


using std::string;
//Worked on class with Ryder

class Stack
{
public:
	Stack();
	
	void Push(string date);
	string Pop();
	string Peek();
	int isEmpty();

	int top;

private:

	string dates[50];


};





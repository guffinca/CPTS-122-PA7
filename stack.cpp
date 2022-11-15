#include "Stack.h"

//Worked on functions with Ryder

Stack::Stack()
{
	top = 0;
	for (int i = 0; i < 50; i++)
	{
		dates[i] = "";
	}
}
void Stack::Push(string date)
{
	if (dates[0] == "")
	{
		dates[0] = date;
	}
	else
	{
		top++;
		dates[top] = date;
	}
}

string Stack::Pop()
{
	string temp = dates[top];
	dates[top] = "";
	top--;
	return temp;
}

string Stack::Peek()
{
	return dates[top];
}

int Stack::isEmpty()
{
	return 0;
}

#include "StudentData.h"




using std::cout;
using std::endl;
using std::string;


Data::Data()
{
	record = 0;
	IDNumber = 0;
	Name = "";
	Email = "";
	Units = "";
	Program = "";
	Level = "";

}

Data::~Data()
{
	cout << "Inside Data deconstructor" << endl;
}

int Data::getRecord() const
{
	return record;
}

int Data::getID() const
{
	return IDNumber;
}

string Data::getName() const
{
	return Name;
}
string Data::getEmail() const
{
	return Email;
}
string Data::getUnits() const
{
	return Units;
}
string Data::getProgram() const
{
	return Program;
}
string Data::getLevel() const
{
	return Level;
}

void Data::setRecord(const int newRecord)
{
	record = newRecord;

}
void Data::setID(const int newID)
{
	IDNumber = newID;

}
void Data::setName(const string newName)
{
	Name = newName;

}
void Data::setEmail(const string newEmail)
{
	Email = newEmail;

}
void Data::setUnits(const string newUnits)
{
	Units = newUnits;
}
void Data::setProgram(const string newProgram)
{
	Program = newProgram;

}
void Data::setLevel(const string newLevel)
{
	Level = newLevel;
}

void Data::addAbsences()
{
	numabsences++;

	ostringstream str1;
	time_t t = time(0);   // get time now
	struct tm* now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;

	string date = str1.str();
	cout << date;
	Date.Push(date);
}

string Data::datesAbsent()
{
	string dates = "";
	dates = Date.Peek();
	return dates;
}


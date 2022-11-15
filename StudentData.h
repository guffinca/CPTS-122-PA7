#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"
#include "Stack.h"
class Data
{
public:
	Data();
	~Data();

	int getRecord() const;
	int getID() const;
	string getName() const;
	string getEmail() const;
	string getUnits() const;
	string getProgram() const;
	string getLevel() const;

	void setRecord(const int newRecord);
	void setID(const int newID);
	void setName(const string newName);
	void setEmail(const string newEmail);
	void setUnits(const string newUnits);
	void setProgram(const string newProgram);
	void setLevel(const string newLevel);
	
	
	void addAbsences();
	string datesAbsent();

private:
	int record;
	int IDNumber;
	string Name;
	string Email;
	string Units;
	string Program;
	string Level;

	int numabsences;

	Stack Date;

	
	



};
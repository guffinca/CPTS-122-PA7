#include "List.h"

class runProgram
{
	public:
		runProgram();
		~runProgram();
		void run();
		int menu();
		void importMasterList();
		void importClassList();
		void storeList();
		void markAbsences();
		
		void print(Data student);
		void report();

private:
	List<Data> Students;

};
runProgram::runProgram()
{

}

runProgram::~runProgram()
{

}

void runProgram::run()
{
	int choice = 0;

	do
	{
		choice = menu();
		switch (choice)
		{
		case 1:
			importClassList();
			break;
		case 2:
			importMasterList();
			break;
		case 3:
			storeList();
			break;
		case 4:
			markAbsences();
			break;
		case 5:
			report();
			break;
		case 6:
			storeList();
			break;
		}


	} while (choice != 6);
}

int runProgram:: menu()
{
	int choice = 0;

	cout << "Choose which you would like to use" << endl;
	cout << "1. Import Class list" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Generate report" << endl;
	cout << "6. Exit" << endl << endl;

	cin >> choice;

	return choice;

}

void runProgram:: importMasterList()
{
	
	fstream infile;
	
		infile.open("master.csv");

	char line[50] = "";
	Data newstudent;
	infile.getline(line, 50);
	while (!infile.eof()) {
		infile.getline(line, 50, ',');
		newstudent.setRecord(atoi(line));
		infile.getline(line, 50, ',');
		newstudent.setID(atoi(line));
		infile.getline(line, 50, ',');
		newstudent.setName(line);
		infile.getline(line, 50, ',');
		newstudent.setEmail(line);
		infile.getline(line, 50, ',');
		newstudent.setUnits(line);
		infile.getline(line, 50, ',');
		newstudent.setProgram(line);
		infile.getline(line, 50, '\n');
		newstudent.setLevel(line);
		Students.InsertAtFront(newstudent);
	}

	infile.close();
}

void runProgram::importClassList()
{

	fstream infile;
	
	
		infile.open("classlist.csv");
	

	char line[50] = "";
	Data newstudent;
	infile.getline(line, 50);
	while (!infile.eof()) {
		infile.getline(line, 50, ',');
		newstudent.setRecord(atoi(line));
		infile.getline(line, 50, ',');
		newstudent.setID(atoi(line));
		infile.getline(line, 50, ',');
		newstudent.setName(line);
		infile.getline(line, 50, ',');
		newstudent.setEmail(line);
		infile.getline(line, 50, ',');
		newstudent.setUnits(line);
		infile.getline(line, 50, ',');
		newstudent.setProgram(line);
		infile.getline(line, 50, '\n');
		newstudent.setLevel(line);
		Students.InsertAtFront(newstudent);
	}

	infile.close();
}

void runProgram::storeList()
{

	fstream outfile;
	outfile.open("master.csv");
	Node<Data>* pMem = Students.getHeadPtr();
	while (pMem != nullptr) {
		outfile << endl << pMem->getData()->getRecord() << "," << pMem->getData()->getID() << ",\"";
		outfile << pMem->getData()->getName() << ",";
		outfile << pMem->getData()->getEmail() << "," << pMem->getData()->getUnits() << ",";
		outfile << pMem->getData()->getProgram() << "," << pMem->getData()->getLevel();
		pMem = pMem->getNextPtr();
	}
	outfile.close();

}

void runProgram::markAbsences()
{
	
	int absence = 0;
	Node<Data>* pMem = Students.getHeadPtr();
	while (pMem != nullptr) {
		//Prints out student info
		print(*(pMem->getData()));
		cout << endl << "Absent 1 for Yes, 2 for No: ";
		cin >> absence;
		if (absence == 1) {
			pMem->getData()->addAbsences();
		}
		pMem = pMem->getNextPtr();
		system("cls");
	}
}

void runProgram::report()
{
	int choice = 0;
	do
	{
		cout << "Which report would you like to Generate" << endl;
		cout << "1. All Students" << endl;
		cout << "2. Students that are Absent" << endl;
		cin >> choice;
	} while (choice != 1 && choice != 2);
	if (choice == 1)
	{
		Node<Data>* pMem = Students.getHeadPtr();
		while (pMem != nullptr)
		{
			cout << pMem->getData()->getName() << " Date Absent: " << pMem->getData()->datesAbsent() <<endl;
			pMem = pMem->getNextPtr();
		}

	}
	else if (choice == 2)
	{
		Node<Data>* pMem = Students.getHeadPtr();
		while (pMem != nullptr)
		{
			cout << pMem->getData()->getName() << " Date Absent: " << pMem->getData()->datesAbsent();
			pMem = pMem->getNextPtr();
		}
	}
}
void runProgram :: print(Data student)
{
	cout << "Name: " << student.getName() << endl;
	cout << "ID: " << student.getID() << endl;
	cout << "Email: " << student.getEmail() << endl;
	cout << "Units: " << student.getUnits() << endl;
	cout << "Program: " << student.getProgram() << endl;
	cout << "Level: " << student.getLevel() << endl;

}



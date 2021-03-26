#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <time.h>  
#include <string>

#include <fstream>
using namespace std;

struct Date {
	int Day, Month, Year;
};

struct Student {
	string No;
	string Student_ID;
	string FirstName;
	string LastName;
	string Gender;
	string Date_Of_Birth;
	string Social_ID;
};

struct NodeStudent {
	Student data;
	NodeStudent* pNext;
};


void readFileStudent(NodeStudent*& pHead) {
	string path;
	cout << "Please enter the name of the file you want to input: ";
	cin >> path;
	ifstream fileIn;
	fileIn.open(path + ".csv", ios_base::in);

	if (fileIn.fail())
	{
		cout << "File is not existed" << endl;
		readFileStudent(pHead);
	}

	NodeStudent* pCur = nullptr;

	while (!fileIn.eof()) {
		if (pHead == nullptr) {
			pHead = new NodeStudent;
			pCur = pHead;
		}
		else {
			pCur->pNext = new NodeStudent;
			pCur = pCur->pNext;
		}
		getline(fileIn, pCur->data.No, ',');
		getline(fileIn, pCur->data.Student_ID, ',');
		getline(fileIn, pCur->data.FirstName, ',');
		getline(fileIn, pCur->data.LastName, ',');
		getline(fileIn, pCur->data.Gender, ',');
		getline(fileIn, pCur->data.Date_Of_Birth, ',');
		fileIn >> pCur->data.Social_ID;
		pCur->pNext = nullptr;
	}

	fileIn.close();
}

#pragma once
#include <iostream>

using namespace std; 

class Faculty; 

class University
{
private:
	int StudNumber = 2000;
	int LectNumber = 100;
	int FacultyNumber = 10;
	Faculty* facultyArray[5];
	int count = 0;
protected:
	string name;
public:
	University() {};
	University(string name, int studNumber, int LectNumber, int FacultyNumber) 
		: StudNumber(studNumber), LectNumber(LectNumber), FacultyNumber(FacultyNumber) {};
	University(string name) : name(name) {};

	int getStudents();
	int getLecturers();
	int getFaculties();

	void AddFaculty(Faculty &faculty) {
		facultyArray[count] = &faculty; 
		count++;
	}

	University operator += (int freshers) {
		this->StudNumber += freshers;
		cout << "Total number of students: " << this->StudNumber << endl;
		return (*this);
	}

	University operator -= (int deducted) {
		this->StudNumber -= deducted;
		cout << "Total number of students: " << this->StudNumber << endl;
		return (*this);
	}

	template <typename T> T EntryToUniver(T x, T y)
	{
		return (x > y) ? x : y;
	}
};


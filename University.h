#pragma once
#include <iostream>

using namespace std; 

class Faculty; 

class University
{
private:
	int StudNumber;
	int LectNumber;
	int FacultyNumber;
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
};


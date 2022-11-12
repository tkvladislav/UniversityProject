#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "University.h"
#include "Lecturer.h"
#include "Student.h"

#ifndef FACULTY
#define FACULTY

using namespace std;

class University;

class Faculty: public University
{
private:
	vector <Lecturer> lecturersArray; 
	vector <Student> studentsArray;
	string facultyName; 
	University* university;

public:
	Faculty(string name);
	Faculty() {};

	void ShowInfo(); 
	string getName();
	void Add(Lecturer &lecturer);
	void Add(Student &student);
	void PrintStudents();
	void PrintLecturers();
	void ShowDeductedStudents(); 
	Student returnStudents(int i);
};

#endif

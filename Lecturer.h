#pragma once
#include <fstream>
#include "Human.h"
#include "Employee.h"

class Exam; 
class Student; 
class Faculty;

#ifndef LECTURER
#define LECTURER

class Lecturer: public Human, public Employee
{
private:  
	Exam* exam;
	Student* student; 
	Faculty* faculty;
	string facultyName;
	int salary = 30000;
public:
	Lecturer();
	Lecturer(string name, int age, Faculty &faculty, string prevWork, int exp);
	Lecturer(string name, int age, Faculty &faculty);
	Lecturer(string name, int age); 
	Lecturer(string name);

	void PrintInfo();
	void StudentsList(Faculty& faculty);
	void SetMark(Student& student,Exam &exam, int mark);
	void DeductStudent(Student &student);
	void Work();

	Lecturer operator--() {
		this->salary = salary - 5000;
		return (*this);
		cout << this->name << " salary was reduced" << endl;
	}

	Lecturer operator + (Lecturer &lec) {
		Lecturer temp;
		temp.salary = (this->salary + lec.salary) / 2;
		return temp;
		cout << "Medium salary is " << temp.salary << endl;
	}
};

#endif

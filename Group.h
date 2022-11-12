#pragma once
#include <iostream>

using namespace std;

class Faculty;
class Student;

class Group
{
protected:
	Faculty* faculty;  
	int NumberOfStudents;
	Student *students[5];
	int num = 0;

public:
	string FacultyName;
	int NumberOfGroup;
	Group() {};
	Group(Faculty &faculty, int students, int number);

	void Add(Student& student);
};


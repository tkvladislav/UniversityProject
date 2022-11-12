#pragma once
#include <iostream>

using namespace std;

class Discipline; 

class Exam
{
private: 
	Discipline *discipline; 
	int mark; 
	string discipline_name;
	string student_name; 

public:
	Exam(Discipline &discipline);
	void setMark(int mark);
	int getMark(); 
	string getDisciplineName();
};


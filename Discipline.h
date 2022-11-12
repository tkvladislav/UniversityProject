#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Student;
class Exam;

class Discipline
{
private:
	string name;
	Exam* exam;
public:
	Discipline() {};
	Discipline(string Name) : name(Name) {};

	string getName();
};


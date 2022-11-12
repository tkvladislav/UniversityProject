#pragma once
#include "Human.h"
#include "Group.h"

class Discipline;
class Exam;
class Group;

#ifndef STUDENT
#define STUDENT

class Student : public Human
{
private:
	Discipline* discipline[4];
	Exam* exam;
	Group *group;

public:
	int GroupNumber;
	string faculty;
	int Number_mark = 0;
	int marks[4] = { 0, 0, 0, 0 };
	int course = 1;

	Student();
	Student(string name, int age);
	Student(string name, Group &group);
	Student(string name, int age, Group &group);

	void PrintInfo();
	void ChooseDisciplines(Discipline& dis1, Discipline& dis2, Discipline& dis3, Discipline& dis4);
	void SeeResults();
	void DoExam(Exam &exam);
	void Work();

	Student operator++() {
		this->course++;
		return (*this);
		cout << "Student " << this->name << " was transferred to" << this->course << " course" << endl;
	}
};

#endif


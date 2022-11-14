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
	int LearningPrice = 20000;
	int RatingMark = 0;

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
		cout << "Student " << this->name << " was transferred to " << this->course << " course" << endl;
		return (*this);
	}

	Student operator - (int oplata) {
		Student temp;
		temp.LearningPrice = this->LearningPrice - oplata; 
		cout << "Student have to pay " << temp.LearningPrice << endl;
		return temp;
	}

	Student operator * (int array[4]) {
		Student temp;
		for (int i = 0; i < 4; i++) {
			temp.marks[i] = array[i] * 0.25;
		}
		for (int i = 0; i < 4; i++) {
			this->RatingMark += temp.marks[i];
		}
		temp.RatingMark = this->RatingMark;
		cout << "The mark of student " << this->getName() << " is " << this->RatingMark << endl;
		return temp;
	}

	Student operator *= (int extrapoints) {
		this->RatingMark *= extrapoints * 0.75;
		cout << "Your rating with extra points is: " << this->RatingMark << endl;
		return (*this);
	}

	Student operator[] (int i) {
		cout << "Your " << i << " point is: " << this->marks[i] << endl;
		return (*this);
	}
};

#endif


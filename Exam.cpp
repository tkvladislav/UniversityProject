#include "Exam.h"
#include "Student.h"
#include "Discipline.h"

Exam::Exam(Discipline &discipline) {
	this->discipline_name = discipline.getName();
}

void Exam::setMark(int mark) {
	this->mark = mark;
}

int Exam::getMark() {
	return this->mark;
}

string Exam::getDisciplineName() {
	return this->discipline_name;
}
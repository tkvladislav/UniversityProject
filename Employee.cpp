#include "Employee.h"

void Employee::setWork(string work) {
	this->work = work;
}

string Employee::getWork() {
	return this->work;
}

void Employee::setPrevWork(string prevWork) {
	this->previousWork = prevWork;
}

string Employee::getPrevWork() {
	return this->previousWork;
}

void Employee::setExpirience(int exp) {
	this->expirience = exp;
}

int Employee::getExpirience() {
	return this->expirience;
}

#pragma once
#include <iostream>

using namespace std; 

class Employee
{
protected:
	string work;
	string previousWork;
	int expirience;
public:

	Employee() {
		previousWork = "none";
		expirience = 0;
	}

	void setWork(string work);
	string getWork();
	void setPrevWork(string prevWork);
	string getPrevWork();
	void setExpirience(int exp);
	int getExpirience();
};


#pragma once
#include <iostream>
#include <string>

using namespace std; 

class Human
{
protected:

	string name; 
	int age;

public:
	Human() {};

	void setName(string name);
	string getName();
	void setAge(int age);
	int getAge(); 
	virtual void Work() {
		cout << "Human is working " << endl;
	}
};


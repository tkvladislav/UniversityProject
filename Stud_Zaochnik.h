#pragma once
#include <iostream>
#include "Student.h"

using namespace std; 

class Stud_Zaochnik: public Student 
{
	public:
		string name; 
		int age; 
		Stud_Zaochnik(Student &student) : name(student.getName()), age(student.getAge()) {};

	void Work() {
		cout << this->name << " is zaochnik now" << endl;
	}
};


#pragma once
#include <iostream>
#include "Student.h"

using namespace std; 

class Stud_Zaochnik: public Student 
{
	public:
		string name; 
		int age; 
		string faculty;
		Stud_Zaochnik() {};
		Stud_Zaochnik(Student &student) : name(student.getName()), age(student.getAge()) {};

	void Work() {
		cout << this->name << " is zaochnik now" << endl;
	}

	Stud_Zaochnik operator= (Student &stud) {
		Stud_Zaochnik temp;
		temp.name = stud.getName();
		temp.age = stud.getAge();
		temp.faculty = stud.faculty;
		cout << "Student " << temp.name << " is zaochnik now " << endl;
		return temp;
	}
};


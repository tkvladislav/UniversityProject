#include "Lecturer.h"
#include "Exam.h"
#include "Student.h"
#include "Faculty.h"
#include <fstream>

Lecturer::Lecturer() {};

Lecturer::Lecturer(string name, int age) {
	this->name = name; 
	this->age = age; 
	this->work = "Lecturer";
}

Lecturer::Lecturer(string name) {
	this->name = name;
	this->work = "Lecturer";
};

Lecturer::Lecturer(string name, int age, Faculty &faculty) {
	this->name = name;
	this->age = age;
	this->facultyName = faculty.getName();
	this->work = "Lecturer";
}

Lecturer::Lecturer(string name, int age, Faculty &faculty, string prevWork, int exp) {
	this->name = name;
	this->age = age;
	this->facultyName = faculty.getName();
	this->work = "Lecturer";
	this->previousWork = prevWork;
	this->expirience = exp;
}

void Lecturer::PrintInfo() {
	cout << "Name: " << this->name << endl; 
	cout << "Age: " << this->age << endl; 
	cout << "Faculty: " << this->facultyName << endl;
}

void Lecturer::SetMark(Student& student, Exam &exam, int mark) {
	exam.setMark(mark);
	student.marks[student.Number_mark] = exam.getMark();
	student.Number_mark++;
	//cout << "Exam is ended" << endl;
	//cout << student.getName() << " gets " << mark << " points" << endl;
}

void Lecturer::DeductStudent(Student& student) {
	if (student.faculty == "IT") {
		ofstream File("deduction_list.txt", ios::app);
		File << student.getName() << endl;
		cout << "\n" << student.getName() << " was deducted" << endl;
		File.close();
	}
	if(student.faculty == "Psychology") {
		ofstream File("deduction_list_psychology.txt", ios::app);
		File << student.getName() << endl;
		cout << "\n" << student.getName() << " was deducted" << endl;
		File.close();
	}
}

void Lecturer::Work() {
	cout << "\nLecturer is working" << endl;
	bool work = true; 
	while (work == true) {
		char choice;
		cout << "\nType 'p', if you want to check your promotion" << endl;
		cout << "Type 'w' to write data about you to file" << endl;
		cout << "Type '0' if you want to exit" << endl;
		cin >> choice;
		if (choice == 'p') {
			try {
				int age = this->age;
				if (age >= 60) {
					cout << this->name << " is promoted" << endl;
				}
				else {
					throw(age);
				}
			}
			catch (int age) {
				cout << "You don't have a promotion, because your age is " << age << endl;
			}
		}
		else if (choice == 'w') {
			ofstream file("Lecturers.txt", ios::app);
			file << this->name << endl;
			file << this->age << endl;
			file << this->work << endl;
			file << this->expirience << endl;
			file.close();
			cout << "Data has been written" << endl;
		}
		else if (choice == '0') {
			work = false;
		}
	}
}

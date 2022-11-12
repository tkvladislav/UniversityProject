#include "Faculty.h"
#include <fstream>

Faculty::Faculty(string name) {
	this->facultyName = name;
}

void Faculty::ShowInfo() {
	cout << this->facultyName << "\n" << endl; 
}

void Faculty::Add(Lecturer &lecturer) {
	this->lecturersArray.push_back(lecturer); 
	ofstream File("lecturers_list.txt", ios::app);
	File << lecturer.getName() << endl;
	File.close();
}

void Faculty::Add(Student &student) {
	this->studentsArray.push_back(student);
	ofstream File("students_list.txt", ios::app);
	File << student.getName() << endl;
	File.close();
}

void Faculty::PrintLecturers() {
	for (auto i : this->lecturersArray) {
		cout << "Name: " << i.getName() << endl;
	}
}

void Faculty::PrintStudents() {
	for (auto i : this->studentsArray) {
		cout << i.getName() << endl;
	}
}

string Faculty::getName() {
	return this->facultyName;
}

void Faculty::ShowDeductedStudents() {
	cout <<"\nDeducted students: " << endl;
	string read;
	if (facultyName == "IT") {
		ifstream File("deduction_list.txt");
		while (getline(File, read)) {
			cout << read << endl;
		}
		File.close();
	}
	
	if (facultyName == "Psychology") {
		ifstream File2("deduction_list_psychology.txt");
		while (getline(File2, read)) {
			cout << read << endl;
		}
		File2.close();
	}
	
}

Student Faculty::returnStudents(int i) {
	return studentsArray.at(i);
}
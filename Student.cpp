#include "Student.h"
#include "Discipline.h"
#include "Exam.h"

Student::Student() {};

Student::Student(string name, int age) {
	this->name = name; 
	this->age = age;
	this->faculty = "No info";
	this->GroupNumber = 0;
}

Student::Student(string name, Group &group) {
	this->name = name;
	this->faculty = group.FacultyName;
	this->GroupNumber = group.NumberOfGroup;
}

Student::Student(string name, int age, Group &group) {
	this->name = name;
	this->age = age;
	this->faculty = group.FacultyName;
	this->GroupNumber = group.NumberOfGroup;
}

void Student::PrintInfo() {
	cout << "Name: " << this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Faculty: " << this->faculty << endl;
	cout << "Group: " << this->GroupNumber << endl;
	cout << "Disciplines: " << endl;
	cout << discipline[0]->getName() << endl; 
	cout << discipline[1]->getName() << endl;
	cout << discipline[2]->getName() << endl;
	cout << discipline[3]->getName() << "\n" << endl;
}

void Student::ChooseDisciplines(Discipline& dis1, Discipline& dis2, Discipline& dis3, Discipline& dis4) {
	discipline[0] = &dis1;
	discipline[1] = &dis2;
	discipline[2] = &dis3;
	discipline[3] = &dis4;
}

void Student::SeeResults() {
	cout << "\n" << name << " results is: ";
	for (auto i : marks) {
		cout << i << " "; 
	}
	cout << "\n";
}

void Student::DoExam(Exam& exam) {
	cout << name << " is doing exam from " << exam.getDisciplineName() << endl;
}

void Student::Work() {
	cout << "\nStudent " << this->name << " is working " << endl;
	bool work = true;
	while (work == true) {
		char choice;
		cout << "\nType 'r', if you want rework your exams" << endl;
		cout << "Type 'c', to check your ability to get a schoolarship" << endl;
		cout << "Type '0' to exit" << endl;
		cin >> choice;
		if (choice == 'r') {
			int numOfExam;
			cout << "Type number of your exam: ";
			cin >> numOfExam;
			if (marks[numOfExam] < 5) {
				marks[numOfExam] = marks[numOfExam]++;
				cout << "Your new mark is " << marks[numOfExam] << endl;
			}
			else {
				cout << "You don't need to rework this exam" << endl;
			}
		}
		else if (choice == '0') {
			work = false;
		}
		else if (choice == 'c') {
			try {
				int average = (marks[0] + marks[1] + marks[2] + marks[3]) / 4;
				if (average == 5) {
					cout << this->name << " gets schoolarship" << endl;
				}
				else {
					throw(average);
				}
			}
			catch (int average) {
				cout << "You don't able to get schoolarship, because your average point is " << average << endl;
			}
		}
	}
}
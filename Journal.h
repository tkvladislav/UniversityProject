#pragma once
#include "Student.h";
#include <list>
#include <iterator>

class Student; 

template <typename T> class Journal
{
private:
	Student *stud;
	list <T> marks;
	string name;
public:
	Journal(Student &stud, T one, T two, T three, T four) {
		this->name = stud.getName(); 
		marks.push_back(one);
		marks.push_back(two);
		marks.push_back(three);
		marks.push_back(four);
	}
	void ShowJournal() {
		cout << "Journal of " << name << endl;
		for (auto i : marks) {
			cout << i << " ";
		}
		cout << "\n";
	}
	void ClearJournal() {
		marks.clear();
	}
};


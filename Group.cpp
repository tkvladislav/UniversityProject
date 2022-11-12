#include "Group.h"
#include "Faculty.h"

Group::Group(Faculty &faculty, int students, int number) {
	this->FacultyName = faculty.getName();
	this->NumberOfStudents = students; 
	this->NumberOfGroup = number; 
}

void Group::Add(Student &student) {
	students[num] = &student;
	num++;
}
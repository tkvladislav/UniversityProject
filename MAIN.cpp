#include <iostream>
#include "University.h"
#include "Faculty.h"
#include "Discipline.h"
#include "Exam.h"
#include "Stud_Zaochnik.h"

using namespace std;

void DeductStudent(Lecturer &lec, Student students[]) {
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 4; i++) {
			if (students[j].marks[i] == 0) {
				break;
			}
			if (students[j].marks[i] <= 3) {
				lec.DeductStudent(students[j]);
				break;
			}
		}
	}
	
}

void f(class Human &human) {
	human.Work();
}

int main()
{
	//створення базового класу
	Human *pointer = new Human();

	University university("HNU"); // створення університету

	Faculty facultyIT("IT");
	Faculty *facultyPsychology = new Faculty("Psychology"); // створення факультетів

	university.AddFaculty(facultyIT);
	university.AddFaculty(*facultyPsychology);

	Group group(facultyIT, 20, 1);
	Group *group2 = new Group(*facultyPsychology, 15, 1); // створення груп


	// створення масивів студентів та додавання до факультету і групи
	Student students[5] = { Student("Igor", 18, group), Student("Vlad", 18, group), Student("Petro", 19),
							Student("John", 20), Student("Evgen", 20, group) };

	for (auto i : students) {
		facultyIT.Add(i);
		group.Add(i);
	}

	Student *studentsPsychology = new Student[3];

	studentsPsychology[0] = Student("Olesya", 18, *group2);
	studentsPsychology[1] = Student("Olexandra", 19);
	studentsPsychology[2] = Student("Hrystyna", 20, *group2);

	for (int i = 0; i < 3; i++) {
		facultyPsychology->Add(studentsPsychology[i]);
		group2->Add(studentsPsychology[i]);
	}


	// створення викладачів
	Lecturer lec("Ivan", 35, facultyIT);

	Lecturer *lec2 = new Lecturer("Oleksii", 61, *facultyPsychology, "Seller", 5);

	//використання методів класу Employee
	cout << "Work of " << lec2->getName() << " is " << lec2->getWork() << endl;
	cout << "Previous work is " << lec2->getPrevWork() << endl;
	cout << "Expirience: " << lec2->getExpirience() << " years" << endl;
	cout << "\n\n";


	// створення дисциплін
	Discipline disciplines[4] = { Discipline("OOP"), Discipline("Web"), Discipline("Math"), Discipline("Logic") };

	Discipline *disciplinesP = new Discipline[4];
	disciplinesP[0] = Discipline("Psychology");
	disciplinesP[1] = Discipline("Phylosophy");
	disciplinesP[2] = Discipline("Ukrainian Language");
	disciplinesP[3] = Discipline("Anatomy");
	

	// вибір предметів

	for (int i = 0; i < 5; i++) {
		students[i].ChooseDisciplines(disciplines[0], disciplines[1], disciplines[2], disciplines[3]);
	}

	for (int i = 0; i < 3; i++) {
		studentsPsychology[i].ChooseDisciplines(disciplinesP[0], disciplinesP[1], disciplinesP[2], disciplinesP[3]);
	}


	// перегляд результатів

	students[1].PrintInfo();
	studentsPsychology->PrintInfo();


	// створення екзаменів
	Exam exam_oop(disciplines[0]);
	Exam exam_web (disciplines[1]);
	Exam exam_math(disciplines[2]);
	Exam exam_logic(disciplines[3]);

	Exam *exam_psychology = new Exam(disciplinesP[0]);
	Exam *exam_phylosophy = new Exam(disciplinesP[1]);
	Exam *exam_ukr = new Exam(disciplinesP[2]);
	Exam *exam_anatomy = new Exam(disciplinesP[3]);

	// проходження тестів та оцінювання студентів викладачем
	students[0].DoExam(exam_oop);
	lec.SetMark(students[0], exam_oop, 2);
	students[0].DoExam(exam_web);
	lec.SetMark(students[0], exam_web, 3);
	students[0].DoExam(exam_math);
	lec.SetMark(students[0], exam_math, 4);
	students[0].DoExam(exam_logic);
	lec.SetMark(students[0], exam_logic, 5);

	lec.SetMark(students[3], exam_oop, 4);
	lec.SetMark(students[3], exam_web, 4);
	lec.SetMark(students[3], exam_math, 4);
	lec.SetMark(students[3], exam_logic, 4);

	lec2->SetMark(studentsPsychology[0], *exam_phylosophy, 5);
	lec2->SetMark(studentsPsychology[0], *exam_phylosophy, 5);
	lec2->SetMark(studentsPsychology[0], *exam_ukr, 5);
	lec2->SetMark(studentsPsychology[0], *exam_anatomy, 5);

	lec2->SetMark(studentsPsychology[2], *exam_phylosophy, 3);
	lec2->SetMark(studentsPsychology[2], *exam_phylosophy, 4);
	lec2->SetMark(studentsPsychology[2], *exam_ukr, 2);
	lec2->SetMark(studentsPsychology[2], *exam_anatomy, 2);

	//посилання на похідні класи і застовсування віртуальної функції

	//1st
	/*pointer = &students[0];
	pointer->Work();

	pointer = &studentsPsychology[0];
	pointer->Work();

	pointer = lec2;
	lec2->Work();

	pointer = &lec;
	pointer->Work();

	//2nd

	f(*pointer);
	f(students[1]);
	f(*lec2);*/

	//3d 

	pointer = &students[2];
	pointer->Work();
	Stud_Zaochnik zaochnik(students[2]);
	pointer = (Human *)&zaochnik;
	pointer->Work();
	pointer = (Human*)&students[2];
	cout << students[2].getName() << " is student of day form again" << endl;
	pointer->Work();


	// operators overloading

	++students[1];
	--lec;
	lec + *lec2;
	// перегляд результатів

	students[0].SeeResults();
	studentsPsychology[2].SeeResults();


	// відрахування студентів
	
	//DeductStudent(lec, students);
	//DeductStudent(*lec2, studentsPsychology);


	// список студентів, які відраховані
	facultyIT.ShowDeductedStudents();
	facultyPsychology->ShowDeductedStudents();

	return 0;
}

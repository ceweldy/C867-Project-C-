#include "student.h"

// Getters
string Student::getStudentId()
{
	return StudentId;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getEmail()
{
	return Email;
}

int Student::getAge()
{
	return Age;
}

int* Student::getDaysInCourse()
{
	return DaysInCourse;
}

Degree Student::getDegreeProgram()
{
	return Degree();
}

// Setters
void Student::setStudentId(string studentId)
{
	StudentId = studentId;
}

void Student::setFirstName(string firstName)
{
	FirstName = firstName;
}

void Student::setLastName(string lastName)
{
	LastName = lastName;
}

void Student::setEmail(string email)
{
	Email = email;
}

void Student::setAge(int age)
{
	Age = age;
}

void Student::setDaysInCourse(int* daysInCourse)
{
	// 
	for (int i = 0; i < 3; i++) {
		DaysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegreeType(Degree degreeType)
{
	DegreeType = degreeType;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[3], Degree degreeType)
{
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysInCourse(daysInCourse);
	setDegreeType(degreeType);
}

void Student::print()
{
	int* daysInCourse = getDaysInCourse();

	cout << getStudentId() << "\t";
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}\t";

	cout << "Degree Program: ";

	if (getDegreeProgram() == SECURITY) {
		cout << "Security";
	}
	else if (getDegreeProgram() == NETWORKING) {
		cout << "Networking";
	}
	else if (getDegreeProgram() == SOFTWARE) {
		cout << "Software";
	}
	else{
		cout << "Other";
	}

	cout << "\n";
}

Student::~Student(){
	// Empty Deconstructor
}
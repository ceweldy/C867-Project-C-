#pragma once

// Header Guards
#ifndef Student_H
#define Student_H

#include<iostream>
#include<string>

#include "degree.h"

using namespace std;

class Student {	// D1
public:
	//getters
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();

	//setters
	void setStudentId(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysInCourse(int[3]);
	void setDegreeType(Degree);

	//additional methods
	virtual void print(); // D2D
	virtual Degree getDegreeProgram(); // D2F

	//constructor
	Student(string, string, string, string, int, int[3], Degree);
	~Student();
private:
	int Age, DaysInCourse[3];
	string Email, FirstName, LastName, StudentId;
	Degree DegreeType;
};


#endif
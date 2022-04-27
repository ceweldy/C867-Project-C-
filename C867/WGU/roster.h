#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

class Roster {
	public:
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
		void printAll();
		void printByDegreeProgram(Degree degreeProgram);	// E3F
		void printDaysInCourse(string studentID, int i);
		void printInvalidEmails();
		void remove(string studentID);
		~Roster();
		Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	private:
		int index = 0;
};
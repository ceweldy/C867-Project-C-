#include<iostream>
#include<sstream>
#include<string>
#include"roster.h"


using namespace std;

void main() {

    cout << "Scripting and Programming - Applications - C867 \n";
    cout << "C++ \n";
    cout << "001106451 \n";
    cout << "Connor Weldy \n\n";

    Roster classRoster;


    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Connor,Weldy,cweldy3@wgu.edu,21,20,17,10,SOFTWARE"  // A
    };

    for (int i = 0; i < 5; i++) { // add students to classRosterArray
        string in = studentData[i];
        istringstream ss(in);

        string temp;
        string placeholder[9];

        int j = 0;
        while (getline(ss, temp, ',')) {
            placeholder[j] = temp;
            j++;
        }

        Degree studentDegree;

        if (placeholder[8] == "NETWORK") {
            studentDegree = NETWORKING;
        }
        else if (placeholder[8] == "SECURITY") {
            studentDegree = SECURITY;
        }
        else if (placeholder[8] == "SOFTWARE") {
            studentDegree = SOFTWARE;
        }
        else {
            studentDegree = OTHER;
        }

        classRoster.add(placeholder[0], placeholder[1], placeholder[2], placeholder[3], stoi(placeholder[4]), stoi(placeholder[5]), stoi(placeholder[6]), stoi(placeholder[7]), studentDegree);
    }

    classRoster.printAll();
    classRoster.printInvalidEmails();

    cout << "Average days in course:" << "\n";
    for (int i = 0; i < 5; i++) {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentId(), i);
    }
    cout << "\n";

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.remove("A3");
    classRoster.~Roster();
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) { // E3A
     // I have an issue here with degreeProgram assigning the wrong Degree. It defaults the enum to 0 because the enum in the degree type header types are all 0, so the degrees its assigning it to is 0 causing all students to be a security student.
    int days[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
  
    if (degreeProgram == NETWORKING) {
        classRosterArray[index] = new NetworkStudent::Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
        classRosterArray[index]->setDegreeType(NETWORKING);
    }
    else if (degreeProgram == SECURITY) {
        classRosterArray[index] = new SecurityStudent::Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
        classRosterArray[index]->setDegreeType(SECURITY);
    }
    else if (degreeProgram == SOFTWARE) {
        classRosterArray[index] = new SoftwareStudent::Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
        classRosterArray[index]->setDegreeType(SOFTWARE);
    }
    else {
        classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
        classRosterArray[index]->setDegreeType(degreeProgram);
    }
    index++;
}

void Roster::printAll() { // E3C; Made public in header file
    cout << "All Students:" << "\n";
    for (int i = 0; i < 5; i++) {
        classRosterArray[i]->print();
    }
    cout << "\n";
}

void Roster::printByDegreeProgram(Degree degreeProgram) {  // E3F; Made public in header file
    if (degreeProgram == NETWORKING) {
        cout << "Networking Students:" << "\n";
    }
    else if (degreeProgram == SECURITY) {
        cout << "Security Students:" << "\n";
    }
    else if (degreeProgram == SOFTWARE) {
        cout << "Software Students:" << "\n";
    }
    else {
        cout << "Other Students:" << "\n";
    }

    for (int i = 0; i < 5; i++) {
        if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
            classRosterArray[i]->print();
        }
    }

    cout << "\n";
}

void Roster::printDaysInCourse(string studentID, int i) {
    cout << "Student " << studentID << ": ";
    int* numberOfDays = classRosterArray[i]->getDaysInCourse();
    int a = numberOfDays[0];
    int b = numberOfDays[1];
    int c = numberOfDays[2];
    double average;

    average = (a + b + c) / 3;
    cout << average;
    cout << "\n";
}

void Roster::printInvalidEmails() { // E3E
    cout << "Invalid Emails:" << "\n";
    bool validEmail;

    for (int i = 0; i < 5; i++) {
        string email = classRosterArray[i]->getEmail();
        size_t foundAt = email.find('@');
        size_t foundPeriod = email.find('.');
        size_t foundSpace = email.find(' ');

        if (foundAt != string::npos && foundPeriod != string::npos && foundSpace == string::npos) {
            validEmail = true;
        }
        else {
            validEmail = false;
        }

        if (validEmail == false) {
            cout << classRosterArray[i]->getEmail();
            cout << "\n";
        }
    }
    cout << "\n";
}

void Roster::remove(string studentID) { // E3B
    bool remove = false;

    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentId() == studentID) {
            classRosterArray[i] = nullptr;
            remove = true;
            break;
        }
    }

    if (remove == false) {
        cout << "Student ID: " << studentID << " was not found.\n";
    }
    else if (remove == true) {
        cout << "Student ID: " << studentID << " successfully removed. \n";
    }
}

Roster::~Roster() {

}
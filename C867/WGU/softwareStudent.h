#pragma once

// Header Guards
#ifndef Software_H
#define Software_H

#include "student.h"

class SoftwareStudent : public Student {
public:
	virtual Degree getDegree();
	
private:
	Degree DegreeType = SOFTWARE;
};


#endif
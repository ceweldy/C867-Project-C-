#pragma once

// Header Guards
#pragma once

// Header Guards
#ifndef Security_H
#define Security_H

#include "student.h"

class SecurityStudent : public Student {
public:
	virtual Degree getDegree();
	
private:
	Degree DegreeType = SECURITY;
};


#endif
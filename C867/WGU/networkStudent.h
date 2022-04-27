#pragma once

// Header Guards
#ifndef Network_H
#define Network_H

#include "student.h"

class NetworkStudent : public Student {
public:
	virtual Degree getDegree();
	
private:
	Degree DegreeType = NETWORKING;
};


#endif
#ifndef _SHAPE_CPP
#define _SHAPE_CPP

#include <iostream>

#include "Shape.h"

std::ofstream& operator<<(std::ofstream& out, const Shape* shape) {
	shape->writeInFile(out);
	return out;
}

#endif // !_SHAPE_CPP
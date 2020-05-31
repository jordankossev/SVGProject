#ifndef _SHAPE_2D_CPP
#define _SHAPE_2D_CPP

#include <iostream>

#include "Shape2D.h"

Shape2D::Shape2D() : fill("none") {};

Shape2D::Shape2D(const std::string& fill) : fill(fill) {};

const std::string& Shape2D::getFill() const {
	return this->fill;
}

void Shape2D::setFill(const std::string& fill) {
	this->fill = fill;
}

//void Shape2D::print() const {
//	std::cout << "Shape2D: " << this->fill << "|\n";
//}

#endif
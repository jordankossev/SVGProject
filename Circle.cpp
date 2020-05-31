#include <iostream>

#include "Circle.h"

const double EPSILON = 0.001;

Circle::Circle() : radius(0) {};

Circle::Circle(const Point& center, const std::string& fill, double radius)
	  : Shape2D(fill), center(center), radius(radius) {};

const Point& Circle::getCenter() const {
	return this->center;
}

double Circle::getRadius() const {
	return this->radius;
}

void Circle::setCenter(const Point& center) {
	this->center = center;
}

void Circle::setRadius(double radius) {
	this->radius = radius;
}

bool Circle::isWithin(const Point& otherCenter, double otherRadius) const {
	double radiiDistance = this->center.distanceTo(otherCenter);

	if (this->radius + radiiDistance - otherRadius < EPSILON) {
		return true;
	}
	return false;
}

bool Circle::isWithin(const Point& rectangleTopLeft, const Point& rectangleBottomRight) const {
	if (this->center.getX() + this->radius > rectangleBottomRight.getX()) {
		return false; // the circle is out from the right
	}
	if (this->center.getX() - this->radius < rectangleTopLeft.getX()) {
		return false; // the circle is out from the left
	}
	if (this->center.getY() - this->radius < rectangleTopLeft.getY()) {
		return false; // the circle is out from the top
	}
	if (this->center.getY() + this->radius > rectangleBottomRight.getY()) {
		return false; // the circle is out from the bottom
	}
	return true;
}

void Circle::translate(double deltaX, double deltaY) {
	this->center.translate(deltaX, deltaY);
}

void Circle::writeInFile(std::ofstream& out) const {
	out << "<circle cx=\"" << this->center.getX() << "\" cy=\"" << this->center.getY()
		<< "\" r=\"" << this->radius << "\" fill=\"" << this->fill << "\" />\n";
}

void Circle::print() const {
	std::cout << "circle: " << this->center.getX() << " " << this->center.getY()
			  << " " << this->radius << " " << this->fill << std::endl;
}
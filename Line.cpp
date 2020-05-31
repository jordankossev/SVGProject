#include <iostream>

#include "Line.h"

Line::Line() {}

Line::Line(const Point& start, const Point& end) : start(start), end(end) {}

Point Line::getStartPoint() const {
	return this->start;
}

Point Line::getEndPoint() const {
	return this->end;
}

void Line::setStartPoint(const Point& start) {
	this->start = start;
}

void Line::setEndPoint(const Point& end) {
	this->end = end;
}

bool Line::isWithin(const Point& circleCenter, double radius) const {
	if (this->start.isWithin(circleCenter, radius) && this->end.isWithin(circleCenter, radius)) {
		return true;
	}
	return false;
}

bool Line::isWithin(const Point& rectangleTopLeft, const Point& rectangleBottomRight) const {
	if (this->start.isWithin(rectangleTopLeft, rectangleBottomRight)
		&& this->end.isWithin(rectangleTopLeft, rectangleBottomRight)) {
		return true;
	}
	return false;
}

void Line::translate(double deltaX, double deltaY) {
	this->start.translate(deltaX, deltaY);
	this->end.translate(deltaX, deltaY);
}

void Line::writeInFile(std::ofstream& out) const {
	out << "<line x1=\"" << this->start.getX() << "\" y1=\"" << this->start.getY()
		<< "\" x2=\"" << this->end.getX() << "\" y2=\"" << this->end.getY() << "\" />\n";
}

void Line::print() const {
	std::cout << "line: " << this->start.getX() << " " << this->start.getY()
			  << " " << this->end.getX() << " " << this->end.getY() << std::endl;
}
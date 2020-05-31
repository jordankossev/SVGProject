#include <iostream>
#include <math.h>

#include "Point.h"

const double EPSILON = 0.001;

/// <summary>
/// (0, 0) are the default coordinates
/// </summary>
Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y) {
	if (x < 0) {
		this->x = -x;
	}
	else {
		this->x = x;
	}
	if (y < 0) {
		this->y = -y;
	}
	else {
		this->y = y;
	}
}

double Point::getX() const {
	return this->x;
}

double Point::getY() const {
	return this->y;
}

void Point::setX(double x) {
	if (x < 0) {
		this->x = -x;
	}
	else {
		this->x = x;
	}
}

void Point::setY(double y) {
	if (y < 0) {
		this->y = -y;
	}
	else {
		this->y = y;
	}
}

/// <summary>
/// Checks if the rectangle formed by the origin and this point
/// can fit in the rectangle formed by the origin and another point
/// </summary>
/// <param name="other"></param>
/// <returns>
/// true: if the rectangle formed by this point can fit in the other rectangle\n
/// false: else
/// </returns>
bool Point::isInnerTo(const Point& other) const {
	if (this->x - other.x < 0 && this->y - other.y < 0) {
		return true;
	}
	return false;
}

bool Point::isWithin(const Point& rectangleTopLeft, const Point& rectangleBottomRight) const {
	if (rectangleTopLeft.isInnerTo(*this) && this->isInnerTo(rectangleBottomRight)) {
		return true;
	}
	return false;
}

bool Point::isWithin(const Point& circleCenter, double radius) const {
	double distance = this->distanceTo(circleCenter);

	if (distance * distance - radius * radius < EPSILON) {
		return true;
	}
	return false;
}

double Point::distanceTo(const Point& other) const {
	double dx = this->x - other.x, dy = this->y - other.y;
	return sqrt(dx * dx + dy * dy);
}

void Point::translate(double deltaX, double deltaY) {
	this->x += deltaX;
	this->y += deltaY;
}
#ifndef _RECTANGLE_CPP
#define _RECTANGLE_CPP

#include <iostream>
#include <cassert>

#include "Rectangle.h"
#include "Functions.h"

void Rectangle::calculateBottomRight() {
	this->bottomRight.setX(this->topLeft.getX() + this->width);
	this->bottomRight.setY(this->topLeft.getY() + this->height);
}

Rectangle::Rectangle() : Shape2D(), width(0), height(0) {
	this->calculateBottomRight();
};

Rectangle::Rectangle(const Point& topLeft, const std::string& fill, double width, double height)
		 : Shape2D(fill), topLeft(topLeft), width(width), height(height) {
	this->calculateBottomRight();
};

const Point& Rectangle::getTopLeftPoint() const {
	return this->topLeft;
}

const Point& Rectangle::getBottomRightPoint() const {
	return this->bottomRight;
}

double Rectangle::getWidth() const {
	return this->width;
}

double Rectangle::getHeight() const {
	return this->height;
}

const std::string& Rectangle::getFill() const {
	return this->fill;
}

void Rectangle::setTopLeftPoint(const Point& topLeft) {
	this->topLeft = topLeft;
	this->calculateBottomRight();
}

void Rectangle::setWidth(double width) {
	if (width < 0) {
		this->width = -width;
	}
	else {
		this->width = width;
	}
	this->calculateBottomRight();
}

void Rectangle::setHeight(double height) {
	if (height < 0) {
		this->height = -height;
	}
	else {
		this->height = height;
	}
	this->calculateBottomRight();
}

void Rectangle::setFill(const std::string& fill) {
	this->fill = fill;
}

bool Rectangle::isWithin(const Point& circleCenter, double radius) const {
	if (this->topLeft.isWithin(circleCenter, radius) && this->bottomRight.isWithin(circleCenter, radius)) {
		return true;
	}
	return false;
}

bool Rectangle::isWithin(const Point& otherTopLeft, const Point& otherBottomRight) const {
	if (this->topLeft.isWithin(otherTopLeft, otherBottomRight)
		&& this->bottomRight.isWithin(otherTopLeft, otherBottomRight)) {
		return true;
	}

	return false;
}

void Rectangle::translate(double deltaX, double deltaY) {
	this->topLeft.translate(deltaX, deltaY);
}

void Rectangle::writeInFile(std::ofstream& out) const {
	out << "<rect x=\"" << this->topLeft.getX() << "\" y=\"" << this->topLeft.getY() << "\" width=\""
		<< this->width << "\" height=\"" << this->height << "\" fill=\"" << this->fill << "\" />\n";
}

void Rectangle::print() const {
	std::cout << "rectangle: " << this->topLeft.getX() << " " << this->topLeft.getY()
			  << " " << this->width << " " << this->height << " " << this->fill << std::endl;
}

#endif // !_RECTANGLE_CPP
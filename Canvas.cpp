#include <iostream>
#include <cassert>
#include <string>

#include "Canvas.h"
#include "Functions.h"

void Canvas::addFigure(Shape* shape) {
	this->figures.push_back(shape);
}

const Shape* Canvas::getFigureAt(size_t index) const {
	assert(index < this->figures.size());
	return this->figures[index];
}

void Canvas::parseRectangle(const std::string& str) {
	size_t x, y, width, height;
	std::string fill;

	x = retrieveDoubleTagValue("x", str);
	y = retrieveDoubleTagValue("y", str);
	width = retrieveDoubleTagValue("width", str);
	height = retrieveDoubleTagValue("height", str);
	fill = retrieveStringTagValue("fill", str);

	this->figures.push_back(new Rectangle(Point(x, y), fill, width, height));
}

void Canvas::parseCircle(const std::string& str) {
	size_t x, y, radius;
	std::string fill;

	x = retrieveDoubleTagValue("cx", str);
	y = retrieveDoubleTagValue("cy", str);
	radius = retrieveDoubleTagValue("r", str);
	fill = retrieveStringTagValue("fill", str);

	this->figures.push_back(new Circle(Point(x, y), fill, radius));
}

void Canvas::parseLine(const std::string& str) {
	size_t x1, y1, x2, y2;

	x1 = retrieveDoubleTagValue("x1", str);
	y1 = retrieveDoubleTagValue("y1", str);
	x2 = retrieveDoubleTagValue("x2", str);
	y2 = retrieveDoubleTagValue("y2", str);

	this->figures.push_back(new Line(Point(x1, y1), Point(x2, y2)));
}

bool Canvas::loadFromFile(std::ifstream& file) {
	std::string fileLine;

	while (std::getline(file, fileLine, '\n')) {
		if (file.fail()) {
			return false;
		}

		int found = fileLine.find("<rect ");
		if (found >= 0) {
			this->parseRectangle(fileLine);
		}

		found = fileLine.find("<circle ");
		if (found >= 0) {
			this->parseCircle(fileLine);
		}

		found = fileLine.find("<line ");
		if (found >= 0) {
			this->parseLine(fileLine);
		}
	}
	return true;
}

bool Canvas::saveChangesInFile(std::ofstream& file) const {
	//writing initial tags
	file << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
	file << "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\"\n \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n\n";
	
	// writing the <svg> tag
	file << "<svg>\n";
	size_t figuresCount = this->figures.size();
	for (size_t i = 0; i < figuresCount; i++) {
		file << '\t';
		if (!(file << this->figures[i])) {
			return false;
		}
	}
	file << "</svg>\n";
	
	return true;
}

void Canvas::translate(double deltaX, double deltaY) {
	size_t figuresCount = this->figures.size();

	for (size_t i = 0; i < figuresCount; i++) {
		this->figures[i]->translate(deltaX, deltaY);
	}
}

void Canvas::translate(double deltaX, double deltaY, size_t index) {
	assert(index < this->figures.size());
	this->figures[index]->translate(deltaX, deltaY);
}

void Canvas::within(const Circle& region) const {
	size_t figuresCount = this->figures.size(), figuresWithinRegion = 0;

	for (size_t i = 0; i < figuresCount; i++) {
		if (this->figures[i]->isWithin(region.getCenter(), region.getRadius())) {
			this->figures[i]->print();
			figuresWithinRegion++;
		}
	}

	if (figuresWithinRegion == 0) {
		std::cout << "No figures in this region\n";
	}
}

void Canvas::within(const Rectangle& region) const {
	size_t figuresCount = this->figures.size(), figuresWithinRegion = 0;

	for (size_t i = 0; i < figuresCount; i++) {
		if (this->figures[i]->isWithin(region.getTopLeftPoint(), region.getBottomRightPoint())) {
			this->figures[i]->print();
			figuresWithinRegion++;
		}
	}

	if (figuresWithinRegion == 0) {
		std::cout << "No figures in this region\n";
	}
}

void Canvas::erase(size_t index) {
	if (index < 1 || index > this->figures.size()) {
		std::cout << "No figure with index " << index << "!\n";
		return;
	}

	this->figures.erase(this->figures.begin() + index - 1);
	std::cout << "Figure " << index << " erased.\n";
}

void Canvas::print() const {
	size_t figuresCount = this->figures.size();

	for (size_t i = 0; i < figuresCount; i++) {
		this->figures[i]->print();
	}
}
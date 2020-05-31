#ifndef _CANVAS_H
#define _CANVAS_H

#include <fstream>
#include <vector>

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"

/// \brief Represents the coordinate system and all figures in it
class Canvas {
private:
	/// \brief a container for the figures
	std::vector<Shape*> figures;

	/// \brief Parse the information in \b str to a rectangle
	/// <param name="str">A line from an SVG file</param>
	/// \details Extracts the parameters from the SVG file and creates a rectangle that is added to the canvas.
	/// \sa retrieveDoubleTagValue() and retrieveStringTagValue() from Functions.h
	void parseRectangle(const std::string&);
	/// \brief Parse the information in \b str to a circle
	/// <param name="str">A line from an SVG file</param>
	/// \details Extracts the parameters from the SVG file and creates a circle that is added to the canvas.
	/// \sa retrieveDoubleTagValue() and retrieveStringTagValue() from Functions.h
	void parseCircle(const std::string&);
	/// \brief Parse the information in \b str to a line
	/// <param name="str">A line from an SVG file</param>
	/// \details Extracts the parameters from the SVG file and creates a line that is added to the canvas.
	/// \sa retrieveDoubleTagValue() and retrieveStringTagValue() from Functions.h
	void parseLine(const std::string&);
public:
	void addFigure(Shape*);
	
	const Shape* getFigureAt(size_t) const;
	
	/// \brief Loads the info from \b file into \b figures
	/// <param name="file">SVG input file</param>
	/// <returns>
	/// \b *true*: if the loading was successful\n
	/// \b *false*: else
	///</returns>
	/// \attention Reads the file line by line and raises the eof() flag.
	bool loadFromFile(std::ifstream&);
	/// \brief Saves the info from \b figures into \b file
	/// <param name="file">SVG output file</param>
	/// <returns>
	/// \b *true*: if the saving was successful\n
	/// \b *false*: else
	///</returns>
	bool saveChangesInFile(std::ofstream&) const;

	/// \brief Performs translation on all figures in \b figures
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	void translate(double, double);
	/// \brief Performs translation on figure with index \b index in \b figures
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	/// <param name="index">Index of a figure to be translated</param>
	void translate(double, double, size_t);
	/// \brief Prints all figures that are within a circle
	/// <param name="region">The circle region</param>
	/// \details Iterates through all figures in \b figures. Those within the circle are printed.
	/// \sa Shape::isWithin
	void within(const Circle&) const;
	/// \brief Prints all figures that are within a rectangle
	/// <param name="region">The rectangle region</param>
	/// \details Iterates through all figures in \b figures. Those within the rectangle are printed.
	/// \sa Shape::isWithin
	void within(const Rectangle&) const;
	
	/// \brief Erases figure with index \b index
	/// <param name="index">Index of a figure to be erased</param>
	/// \details If index is out of bounds a console message is printed
	void erase(size_t);

	void print() const;
};

#endif // !_CANVAS_H
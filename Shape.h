#ifndef _SHAPE_H
#define _SHAPE_H

#include <string>
#include <fstream>

#include "Point.h"


/// \brief Interface class for all supported shapes
class Shape {
public:
	/// \brief Checks if \b this shape is in a circle
	/// <param name="circleCenter">Center point of the cirlce</param>
	/// <param name="radius">Radius of the circle</param>
	/// <returns>
	/// \b *true*: if \b this shape is in the circle\n
	/// \b *false*: else
	///</returns>
	virtual bool isWithin(const Point&, double) const = 0;
	/// \brief Checks if \b this shape is in a rectangle
	/// <param name="">Top-left point of the rectangle</param>
	/// <param name="">Bottom-right of the rectangle</param>
	/// <returns>
	/// \b *true*: if \b this shape is in the rectangle\n
	/// \b *false*: else
	///</returns>
	virtual bool isWithin(const Point&, const Point&) const = 0;
	/// \brief Performs translation on \b this shape
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	virtual void translate(double, double) = 0;
	/// \brief Specifies how to write \b this shape into a file
	/// <param name="file">File to write into</param>
	virtual void writeInFile(std::ofstream&) const = 0;
	/// \brief Specifies how to print \b this shape on the console
	virtual void print() const = 0;

	/// \brief Overloading \b operator<<
	/// \details Calls \b writeInFile(std::ofstream&). Since \b writeInFile is purely virtual, \b operator<<, in a way, also "becomes virtual"
	/// \sa writeInFile
	friend std::ofstream& operator<<(std::ofstream&, const Shape*);
};
#endif // !_SHAPE_H
#ifndef _LINE_H
#define _LINE_H

#include "Shape.h"
#include "Point.h"

/// \brief Represents a line in the plane
/// \attention Class Line inherits Shape (not Shape2D) directly since lines are one-dimensional objects
class Line : public Shape {
private:
	/// \brief Initail point of the line
	Point start;
	/// \brief End point of the line
	Point end;
public:
	Line();
	Line(const Point&, const Point&);

	Point getStartPoint() const;
	Point getEndPoint() const;

	void setStartPoint(const Point&);
	void setEndPoint(const Point&);
	
	/// \brief Checks if \b this line is within a circle
	/// <param name="circleCenter">Center point of the circle</param>
	/// <param name="radius">Radius of the circle</param>
	/// <returns>
	/// \b *true*: if \b this line is in the circle\n
	/// \b *false*: else
	///</returns>
	/// \details The functionality is implemented using the \b Point::isWithin(const Point&, double) method
	/// \sa Point::isWithin
	virtual bool isWithin(const Point&, double) const;
	/// \brief Checks if \b this line is within a rectangle
	/// <param name="otherTopLeft">Top-left point of the other rectangle</param>
	/// <param name="otherBottomRight">Bottom-left point of the other rectangle</param>
	/// <returns>
	/// \b *true*: if \b this line is in the rectangle\n
	/// \b *false*: else
	///</returns>
	/// \details The functionality is implemented using the \b Point::isWithin(const Point&, const Point&) method
	/// \sa Point::isWithin
	virtual bool isWithin(const Point&, const Point&) const;
	virtual void writeInFile(std::ofstream&) const;
	/// \brief Performs translation on \b this line
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	/// \details The function utilizes Point::translate(double, double)
	/// \sa Point::translate
	virtual void translate(double, double);
	virtual void print() const;
};

#endif // !_LINE_H

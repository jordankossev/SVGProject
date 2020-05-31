#ifndef _CIRCLE_H
#define _CIRCLE_H

#include "Shape2D.h"
#include "Point.h"

/// \brief Represents a circle on the plane
class Circle : public Shape2D {
private:
	/// \brief Center point of the circle
	Point center;
	/// \brief Radius of the circle
	double radius;
public:
	Circle();
	Circle(const Point&, const std::string&, double);

	const Point& getCenter() const;
	double getRadius() const;

	void setCenter(const Point&);
	void setRadius(double);

	/// \brief Checks if \b this circle is within another circle
	/// <param name="circleCenter">Center point of the other circle</param>
	/// <param name="radius">Radius of the other circle</param>
	/// <returns>
	/// \b *true*: if \b this circle is in the other circle\n
	/// \b *false*: else
	///</returns>
	/// \details The functionality is implemented using the \b Point::isWithin(const Point&, double) method
	/// \sa Point::isWithin
	virtual bool isWithin(const Point&, double) const;
	/// \brief Checks if \b this circle is within rectangle
	/// <param name="rectangleTopLeft">Top-left point of the rectangle</param>
	/// <param name="rectangleBottomRight">Bottom-right point of the rectangle</param>
	/// <returns>
	/// \b *true*: if \b this circle is in the rectangle\n
	/// \b *false*: else
	///</returns>
	/// \details The functionality is implemented using the \b Point::isWithin(const Point&, const Point&) method
	/// \sa Point::isWithin
	virtual bool isWithin(const Point&, const Point&) const;
	/// \brief Performs translation on \b this circle
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	/// \details The function utilizes Point::translate(double, double)
	/// \sa Point::translate
	virtual void translate(double, double);
	virtual void writeInFile(std::ofstream&) const;
	virtual void print() const;
};

#endif // !_CIRCLE_H
#ifndef _RECTANGLE_H
#define _RECTANGLE_H

#include "Shape2D.h"
#include "Point.h"

/// \brief Represents a rectangle in the plane
class Rectangle : public Shape2D {
private:
	/// \brief Top-left point of the rectangle
	Point topLeft;
	/// \brief Bottom-right point of the rectangle
	Point bottomRight;
	/// \brief width of the rectangle
	double width;
	/// \brief height point of the rectangle
	double height;
	
	/// \brief Calculates the coordinates of the bottom-right point
	/// \details Since there are no coordinates for the bottom-right point in the SVG file,\n they are determined based on the top-left, the width and the height
	void calculateBottomRight();
public:
	Rectangle();
	Rectangle(const Point&, const std::string&, double, double);

	const Point& getTopLeftPoint() const;
	const Point& getBottomRightPoint() const;
	double getWidth() const;
	double getHeight() const;
	const std::string& getFill() const;

	/// \details if the top-left point is changed the bottom-right one must be recalculated
	void setTopLeftPoint(const Point&);
	/// \details if the width is changed the bottom-right point must be recalculated
	void setWidth(double);
	/// \details if the height is changed the bottom-right point must be recalculated
	void setHeight(double);
	void setFill(const std::string&);

	/// \brief Checks if \b this rectangle is within a circle
	/// <param name="circleCenter">Center point of the circle</param>
	/// <param name="radius">Radius of the circle</param>
	/// <returns>
	/// \b *true*: if \b this rectangle is in the circle\n
	/// \b *false*: else
	///</returns>
	/// \details The functionality is implemented using the \b Point::isWithin(const Point&, double) method
	/// \sa Point::isWithin
	virtual bool isWithin(const Point&, double) const;
	/// \brief Checks if \b this rectangle is within a rectangle
	/// <param name="otherTopLeft">Top-left point of the other rectangle</param>
	/// <param name="otherBottomRight">Bottom-left point of the other rectangle</param>
	/// <returns>
	/// \b *true*: if \b this rectangle is in the other rectangle\n
	/// \b *false*: else
	///</returns>
	/// \details The functionality is implemented using the \b Point::isWithin(const Point&, const Point&) method
	/// \sa Point::isWithin
	virtual bool isWithin(const Point&, const Point&) const;
	/// \brief Performs translation on \b this rectangle
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	/// \details The function utilizes Point::translate(double, double)
	/// \sa Point::translate
	virtual void translate(double, double);
	virtual void writeInFile(std::ofstream&) const;
	virtual void print() const;
};

#endif // !_RECTANGLE_H
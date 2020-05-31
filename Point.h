#ifndef _POINT_H
#define _POINT_H

/// <summary>
/// Represents a point on the plane
/// </summary>
class Point {
private:
	double x;
	double y;
public:
	/// <summary>
	/// Default constructor
	/// </summary>
	Point();

	/// <summary>
	/// Constructor with parameters. Uses the absolute values of the parameters.
	/// </summary>
	/// <param name="x">X-axis coordinate</param>
	/// <param name="y">Y-axis coordinate</param>
	Point(double, double);

	/// <returns>X-coordinate</returns>
	double getX() const;
	/// <returns>Y-coordinate</returns>
	double getY() const;

	/// <summary>
	/// Sets the absolute value of the parameter
	/// </summary>
	void setX(double);
	/// <summary>
	/// Sets the absolute value of the parameter
	/// </summary>
	void setY(double);

	/// <summary>
	/// Compares the position of \b this relative to another point
	/// </summary>
	bool isInnerTo(const Point&) const;
	/// <summary>
	/// Checks if \b this point is within a rectangle
	/// </summary>
	/// <param name="rectangleTopLeft">Top-left corner of the rectangle</param>
	/// <param name="rectangleBottomRight">Bottom-right corner of the rectangle</param>
	/// <returns>
	/// \b *true*: if \b this point is in the rectangle\n
	/// \b *false*: else
	/// </returns>
	bool isWithin(const Point&, const Point&) const;
	/// <summary>
	/// Checks if \b this point is within a circle
	/// </summary>
	/// <param name="circleCenter">Center point of the circle</param>
	/// <param name="radius">radius of the circle</param>
	/// <returns>
	/// \b *true*: if \b this point is in the circle\n
	/// \b *false*: else
	/// </returns>
	bool isWithin(const Point&, double) const;
	/// <summary>
	/// Calculates the distance to another point
	/// </summary>
	/// <returns>The distance between the two points</returns>
	double distanceTo(const Point&) const;

	/// <summary>
	/// Performs translation on \b this point
	/// </summary>
	/// <param name="deltaX">X-axis translation</param>
	/// <param name="deltaY">Y-axis translation</param>
	void translate(double, double);
};
#endif // !_POINT_H
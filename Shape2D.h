#ifndef _SHAPE2D_H
#define _SHAPE2D_H

#include <string>

/// \brief Represents a 2-dimensional shape 
#include "Shape.h"

class Shape2D : public Shape {
protected:
	/// \brief The class introduces the \b fill property
	std::string fill;
public:
	Shape2D();
	Shape2D(const std::string&);

	const std::string& getFill() const;
	void setFill(const std::string&);
};

#endif // !_SHAPE2D_H
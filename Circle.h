#pragma once
#include "shape.h"

class Circle : public Shape{
private:
	//Data members
	static const char m_identity = 'C';
	float m_radius;
	std::string m_utility;

public:
	//Constructor
	Circle(float Radius);

	//Member function
	float* Dimension() const;
	float Area() const;
	float Perimeter() const;
	char Identity() const;

	void SetUtility(const std::string& Str);
	std::string& GetUtility();

	//Destructor
	~Circle(void);
};
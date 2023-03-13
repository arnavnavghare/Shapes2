#pragma once
#include "shape.h"

class Triangle : public Shape{
private:
	//Data members
	static const char m_identity = 'T';
	float m_side1, m_side2, m_side3;
	std::string m_utility;

public:
	//Constructor
	Triangle(float Side1, float Side2, float Side3);

	//Member function
	float* Dimension() const;
	float Area() const;
	float Perimeter() const;
	char Identity() const;

	void SetUtility(const std::string& Str);
	std::string&  GetUtility();

	//Destructor
	~Triangle(void);
};
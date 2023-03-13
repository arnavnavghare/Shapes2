#pragma once
#include "shape.h"

class rectangle : public Shape{
private:
	//Data members
	static const char m_identity = 'R';
	float m_length, m_breadth;
	std::string m_utility;

public:
	//Constructor
	rectangle(float Length, float Breadth);

	//Member function
	float* Dimension() const;
	float Area() const;
	float Perimeter() const;
	char Identity() const;

	void SetUtility(const std::string& Str);
	std::string&  GetUtility();

	//Destructor
	~rectangle(void);
};

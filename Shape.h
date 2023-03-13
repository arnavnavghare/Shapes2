#pragma once
#include <string>

class Shape{
private:
	//Data members
	char m_identity;
	float m_area, m_perimeter;

public:
	//Constructor
	Shape(void);

	//Member functions
	virtual float* Dimension() const;
	virtual float Area() const;
	virtual float Perimeter() const;
	virtual char Identity() const;
	virtual std::string& GetUtility();

	//Destructor
	~Shape(void);
};

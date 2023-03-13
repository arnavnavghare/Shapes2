#pragma once
#include <vector>
#include "Shape.h"
#include "ItemAndRate.h"

using std::vector;
using std::pair;

class ShapesInALayout{
private:
	std::vector <pair<Shape*, ItemAndRate*>> m_shapesInALayout;

public:
	//Constructor
	ShapesInALayout(void);

	//Member functions
	void AddShapeAndItem(Shape* Sptr, ItemAndRate* IAndRptr);
	void RemoveShapeAndItem(const int& Index);
	std::pair<Shape*, ItemAndRate*>& const RetrieveShapeAndItem(const int& Index);
	int NumberofObjects() const;

	//Destructor
	~ShapesInALayout(void);
};
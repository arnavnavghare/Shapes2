#include "StdAfx.h"
#include "ShapesInALayout.h"

//--------------------------------------------------------------------------------

ShapesInALayout::ShapesInALayout(void){
}

//--------------------------------------------------------------------------------

void ShapesInALayout::AddShapeAndItem(Shape* Sptr, ItemAndRate* IAndRptr){
	pair<Shape*, ItemAndRate*> temp;
	temp.first = Sptr;
	temp.second = IAndRptr;
	m_shapesInALayout.push_back(temp);
}

//--------------------------------------------------------------------------------

void ShapesInALayout::RemoveShapeAndItem(const int& Index){
	delete (m_shapesInALayout[Index-1].first);
	m_shapesInALayout.erase(m_shapesInALayout.begin()+(Index-1));
}

//--------------------------------------------------------------------------------

std::pair<Shape*, ItemAndRate*>& const ShapesInALayout::RetrieveShapeAndItem(const int& Index){
	return m_shapesInALayout[Index];
}

//--------------------------------------------------------------------------------

int ShapesInALayout::NumberofObjects() const{
	return ShapesInALayout::m_shapesInALayout.size();
}

//--------------------------------------------------------------------------------


ShapesInALayout::~ShapesInALayout(void){
}

//--------------------------------------------------------------------------------
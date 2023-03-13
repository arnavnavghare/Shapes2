#include "StdAfx.h"
#include "rectangle.h"

//--------------------------------------------------------------------------------

rectangle::rectangle(float Length, float Breadth){
	m_length = Length;
	m_breadth = Breadth;
}

//--------------------------------------------------------------------------------

float* rectangle::Dimension() const{
	float Dim[3] = {m_length, m_breadth, 0.0};
	return Dim;
}

//--------------------------------------------------------------------------------

float rectangle::Area() const{
	return (m_length*m_breadth);
}

//--------------------------------------------------------------------------------

float rectangle::Perimeter() const{
	return (2.0*(m_length+m_breadth));
}

//--------------------------------------------------------------------------------

char rectangle::Identity() const{
	return m_identity;
}

//--------------------------------------------------------------------------------

void rectangle::SetUtility(const std::string& Str){
	m_utility = Str;
}

//--------------------------------------------------------------------------------

std::string&  rectangle::GetUtility(){
	return m_utility;
}

//--------------------------------------------------------------------------------

rectangle::~rectangle(void){
}

//--------------------------------------------------------------------------------
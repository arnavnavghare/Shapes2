#include "StdAfx.h"
#include "Triangle.h"
#include <cmath>

//--------------------------------------------------------------------------------

Triangle::Triangle(float Side1, float Side2, float Side3){
	m_side1 = Side1;
	m_side2 = Side2;
	m_side3 = Side3;
}

//--------------------------------------------------------------------------------

float* Triangle::Dimension() const{
	float Dim[3] = {m_side1, m_side2, m_side3};
	return Dim;
}

//--------------------------------------------------------------------------------

float Triangle::Area() const{
	float S = ((m_side1+m_side2+m_side3)/2.0);
	return sqrt(S*(S-m_side1)*(S-m_side2)*(S-m_side3));
}

//--------------------------------------------------------------------------------

float Triangle::Perimeter() const{
	return (m_side1+m_side2+m_side3);
}

//--------------------------------------------------------------------------------

char Triangle::Identity() const{
	return m_identity;
}

//--------------------------------------------------------------------------------

void Triangle::SetUtility(const std::string& Str){
	m_utility = Str;
}

//--------------------------------------------------------------------------------

std::string&  Triangle::GetUtility(){
	return m_utility;
}

//--------------------------------------------------------------------------------

Triangle::~Triangle(void){
}

//--------------------------------------------------------------------------------
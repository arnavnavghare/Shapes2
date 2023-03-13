#pragma once
#include "Shape.h"
#include "rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ItemAndRate.h"
#include "ItemAndRateChart.h"
#include "ShapesInALayout.h"

class UserInterface{
public:
	//Constructor
	UserInterface(void);

	//Member functions
	static Shape* ReturnShapePointer();

	static rectangle* CreateRectangleUsingInputFromUser();
	static rectangle* CreateRectangleUsingInputFromUser(float Length, float Breadth, std::string Utility);
	static Triangle* CreateTriangleUsingInputFromUser();
	static Triangle* CreateTriangleUsingInputFromUser(float Side1, float Side2, float Side3, std::string Utility);
	static Circle* CreateCircleUsingInputFromUser();
	static Circle* CreateCircleUsingInputFromUser(float Radius, std::string Utility);

	void DisplayMainMenuSelectionOptions();
	void DisplayShapeSelectionOptions();
	void DisplayRemoveShapeStatement();
	void DisplayRemoveItemStatement();
	void DisplaySaveSuccessfulStatement();
	void DisplayEntryAddedSuccessfullyStatement();
	void DisplayRemoveSuccessfulStatement();
	void DisplayItemSelectionFromUser();

	int GetChoiceFromUser();
	std::string GetUtilityNameFromUser();

	void ShowShapesInLayout(ShapesInALayout& const Layout);
	void ShowItemsInRateChart(ItemAndRateChart& const ItemAndRateChart);

	static ItemAndRate* CreateNewItem();
	static ItemAndRate* CreateNewItem(std::string Itemname, float Rate, std::string Measurementunit);
	ItemAndRate* GetItemSelectionFromUser(ItemAndRateChart& const ItemsAndRates, const int& Index);

	float CostCalculator(ShapesInALayout& const Layout, int& const Index);

	//Destructor
	~UserInterface(void);
};
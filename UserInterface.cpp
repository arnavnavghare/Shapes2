#include "StdAfx.h"
#include <iostream>
#include "UserInterface.h"
#include <string>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;

//--------------------------------------------------------------------------------

UserInterface::UserInterface(void){
}

//--------------------------------------------------------------------------------

Shape* UserInterface::ReturnShapePointer(){
		Shape* ptr = new Shape;
		return ptr;
	}

//--------------------------------------------------------------------------------

rectangle* UserInterface::CreateRectangleUsingInputFromUser(){
	float Length = 0, Breadth = 0;
	string temp;
	cout<<"Enter length of Rectangle (In Meters) = ";
	std::getline(cin,temp);
	Length = atoi(temp.c_str());
	cout<<"Enter breadth of Rectangle (In Meters) = ";
	std::getline(cin,temp);
	Breadth = atoi(temp.c_str());
	rectangle* Rptr = new rectangle(Length, Breadth);
	cout<<"Enter utility type = ";
	getline(cin, temp);
	(*Rptr).SetUtility(temp);
	return Rptr;
}

//--------------------------------------------------------------------------------

rectangle* UserInterface::CreateRectangleUsingInputFromUser(float Length, float Breadth, std::string Utility){
	rectangle* Rptr = new rectangle(Length, Breadth);
	(*Rptr).SetUtility(Utility);
	return Rptr;
}

//--------------------------------------------------------------------------------

Triangle* UserInterface::CreateTriangleUsingInputFromUser(){
	int Side1 = 0, Side2 = 0, Side3 = 0;
	string temp;
	cout<<"Enter length of first side of Triangle (In Meters) = ";
	std::getline(cin,temp);
	Side1 = atoi(temp.c_str());
	cout<<"Enter length of second side of Triangle (In Meters) = ";
	std::getline(cin,temp);
	Side2 = atoi(temp.c_str());
	cout<<"Enter length of third side of Triangle (In Meters) = ";
	std::getline(cin,temp);
	Side3 = atoi(temp.c_str());
	Triangle* Tptr = new Triangle(Side1, Side2, Side3);
	cout<<"Enter utility type = ";
	getline(cin, temp);
	(*Tptr).SetUtility(temp);
	return Tptr;
}

//--------------------------------------------------------------------------------

Triangle* UserInterface::CreateTriangleUsingInputFromUser(float Side1, float Side2, float Side3, std::string Utility){
	Triangle* Tptr = new Triangle(Side1, Side2, Side3);
	(*Tptr).SetUtility(Utility);
	return Tptr;
}

//--------------------------------------------------------------------------------

Circle* UserInterface::CreateCircleUsingInputFromUser(){
	int Radius = 0;
	string temp;
	cout<<"Enter radius of Circle (In Meters) = ";
	std::getline(cin,temp);
	Radius = atoi(temp.c_str());
	Circle* Cptr = new Circle(Radius);
	cout<<"Enter utility type = ";
	getline(cin, temp);
	(*Cptr).SetUtility(temp);
	return Cptr;
}

//--------------------------------------------------------------------------------

Circle* UserInterface::CreateCircleUsingInputFromUser(float Radius, std::string Utility){
	Circle* Cptr = new Circle(Radius);
	(*Cptr).SetUtility(Utility);
	return Cptr;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayMainMenuSelectionOptions(){
	int Choice = 0;
	string temp;
	cout<<endl << std::setw(12)<<std::right<< ' ' <<"**********************  WELCOME TO LAYOUT PLANNING SYSTEM  ***********************"<<std::endl<<std::endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Show rate chart                  -->   [1]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Add item to rate chart           -->   [2]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Remove item from rate chart      -->   [3]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Show all shapes in the layout    -->   [4]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Add new shape to the layout      -->   [5]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Remove a shape from the layout   -->   [6]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Save all                         -->   [7]"<<endl;
	cout<<std::setw(30)<<std::right<<'\t'<<"Save & Exit                      -->   [8]"<<endl;
	cout<<endl << std::setw(12)<<std::right<< ' ' <<"**********************************************************************************"<<std::endl<<std::endl; 
	cout<<std::setw(30)<<std::right<<'\t'<<"Make choice from above options   -->    ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayShapeSelectionOptions(){
	int Choice = 0;
	string temp;
	cout<<"Add Rectangle  -->  [1]"<<endl;
	cout<<"Add Triangle   -->  [2]"<<endl;
	cout<<"Add Circle     -->  [3]"<<endl;
	cout<<"Make choice of shape from above options --> ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayRemoveShapeStatement(){
	cout<< "Enter the shape number to remove = ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayRemoveItemStatement(){
	cout<< "Enter the item number to remove = ";
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayEntryAddedSuccessfullyStatement(){
	cout<< "Entry added successfully!"<<endl;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplaySaveSuccessfulStatement(){
	cout<< "Data Saved Successfully!"<<endl;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayRemoveSuccessfulStatement(){
	cout<< "Entry removed Successfully!"<<endl<<endl;
}

//--------------------------------------------------------------------------------

void UserInterface::DisplayItemSelectionFromUser(){
	cout<< "Enter item selection = ";
}

//--------------------------------------------------------------------------------

int UserInterface::GetChoiceFromUser() {
	std::string str;
	int Choice = 0;
	getline(std::cin, str);
	Choice = (atoi(str.c_str()));
	return Choice;
}

//--------------------------------------------------------------------------------

std::string UserInterface::GetUtilityNameFromUser(){
	std::string Str;
	cout<<"Enter utility type = ";
	getline(std::cin, Str);
	return Str;
}

//--------------------------------------------------------------------------------

void UserInterface::ShowShapesInLayout(ShapesInALayout& const Layout){
	int Total = 0;
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<std::setw(04)<<std::left<<"|"<<std::setw(10)<<"Sr. No."<<std::setw(8)<<"Shape"<<std::setw(12)<<"Utility"<<std::setw(17)<<"Dimensions (m)"<<std::setw(12)<<"Area (m2)"<<std::setw(17)<<"Perimeter (m)"<<std::setw(20)<<"Type"<<std::setw(10)<<"Rate"<<std::setw(14)<<"Unit"<<std::setw(9)<<"Cost (Rs)"<<std::setw(04)<<std::right<<"|"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	for (int i = 0; i<Layout.NumberofObjects(); i++){
		cout<<std::setw(07)<<std::left<<"|"<<std::setw(9)<<i+1;
		cout<<std::setw(06)<<(Layout.RetrieveShapeAndItem(i).first) -> Identity();
		cout<<std::setw(14)<<(Layout.RetrieveShapeAndItem(i).first) -> GetUtility();
		if ((Layout.RetrieveShapeAndItem(i).first) -> Identity() == 'C'){
			cout<<std::setw(18)<<(Layout.RetrieveShapeAndItem(i).first) -> Dimension()[0];
		}
		else if ((Layout.RetrieveShapeAndItem(i).first) -> Identity() == 'R'){
			cout<<(Layout.RetrieveShapeAndItem(i).first) -> Dimension()[0]<<std::setw(3)<<',';
			cout<<std::setw(14)<<(Layout.RetrieveShapeAndItem(i).first) -> Dimension()[1];
		}
		else if ((Layout.RetrieveShapeAndItem(i).first) -> Identity() == 'T'){
			cout<<(Layout.RetrieveShapeAndItem(i).first) -> Dimension()[0]<<std::setw(3)<<',';
			cout<<(Layout.RetrieveShapeAndItem(i).first) -> Dimension()[1]<<std::setw(3)<<',';
			cout<<std::setw(10)<<(Layout.RetrieveShapeAndItem(i).first) -> Dimension()[2];
		}
		
		cout<<std::setw(13)<<(Layout.RetrieveShapeAndItem(i).first) -> Area();
		cout<<std::setw(13)<<(Layout.RetrieveShapeAndItem(i).first) -> Perimeter();
		cout<<std::setw(20)<<(Layout.RetrieveShapeAndItem(i).second) -> GetItemName();
		cout<<std::setw(10)<<(Layout.RetrieveShapeAndItem(i).second) -> GetItemRate();
		cout<<std::setw(10)<<(Layout.RetrieveShapeAndItem(i).second) -> GetMeasurementUnit();
		cout<<std::setw(10)<<std::right<<std::fixed<<std::setprecision(0)<<ceil(UserInterface::CostCalculator(Layout,i))<<" Rs"<<std::setw(04)<<std::right<<"|"<<endl;
		Total = Total + ceil(UserInterface::CostCalculator(Layout,i));
	}
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<std::setw(04)<<std::left<<"|"<<std::setw(112)<<std::left<< "The total quote cost is = "<<std::setw(14)<<std::right<<std::fixed<<std::setprecision(0)<<Total<<" Rs"<<std::setw(04)<<std::right<<"|"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
  
//--------------------------------------------------------------------------------

void UserInterface::ShowItemsInRateChart(ItemAndRateChart& const ItemAndRateChart){
	cout<<"--------------------------------------------------------------------------------"<<endl;
	cout<<std::setw(04)<<std::left<<"|"<<std::setw(7)<<std::right<<"Sr. No."<<'\t'<<'\t'<<std::setw(10)<<std::left<<"Item"<<'\t'<<'\t'<<std::setw(10)<<std::left<<"Rate"<<'\t'<<'\t'<<std::setw(4)<<std::left<<"Unit"<<std::setw(04)<<std::right<<"|"<<endl;
	cout<<"--------------------------------------------------------------------------------"<<endl;
	for (int i=0; i<ItemAndRateChart.NumberofObjects(); i++){
		cout<<std::setw(04)<<std::left<<"|"<<std::setw(04)<<std::right<<i+1<<"            "<<std::setw(15)<<std::left<<(*ItemAndRateChart.RetrieveItemAndRate(i)).GetItemName();
		cout<<std::setw(17)<<std::right<<(*ItemAndRateChart.RetrieveItemAndRate(i)).GetItemRate()<<'\t'<<'\t';
		cout<<std::setw(12)<<std::right<<(*ItemAndRateChart.RetrieveItemAndRate(i)).GetMeasurementUnit()<<std::setw(04)<<std::right<<"|"<<'\n';
	}
	cout<<"--------------------------------------------------------------------------------"<<endl;
}

//--------------------------------------------------------------------------------

ItemAndRate* UserInterface::CreateNewItem(){
	std::string itemname, measurementunit, tempstring;
	float rate;
	cout<<"Enter item name = ";
	getline(cin,itemname);
	cout<<"Enter item rate = ";
	getline(cin,tempstring);
	rate = atof(tempstring.c_str());
	cout<<"Enter measurement unit = ";
	getline(cin,measurementunit);
	ItemAndRate* IAndRptr = new ItemAndRate(itemname, rate, measurementunit);
	return IAndRptr;
}

//--------------------------------------------------------------------------------

ItemAndRate* UserInterface::CreateNewItem(std::string Itemname, float Rate, std::string Measurementunit){
	ItemAndRate* IAndRptr = new ItemAndRate(Itemname, Rate, Measurementunit);
	return IAndRptr;
}

//--------------------------------------------------------------------------------

ItemAndRate* UserInterface::GetItemSelectionFromUser(ItemAndRateChart& const ItemsAndRates, const int& Index){
	return ItemsAndRates.RetrieveItemAndRate(Index);
}

//--------------------------------------------------------------------------------

float UserInterface::CostCalculator(ShapesInALayout& const Layout, int& const Index){
	if (Layout.RetrieveShapeAndItem(Index).second -> GetMeasurementUnit() == "Rs/sq.m"){
		return ((Layout.RetrieveShapeAndItem(Index).first -> Area())*(Layout.RetrieveShapeAndItem(Index).second -> GetItemRate()));
	}
	else if(Layout.RetrieveShapeAndItem(Index).second -> GetMeasurementUnit() == "Rs/m"){
		return ((Layout.RetrieveShapeAndItem(Index).first -> Perimeter())*(Layout.RetrieveShapeAndItem(Index).second -> GetItemRate()));
	}
	else{
		cout<<"Invalid Unit!"<<endl;
	}
}

//--------------------------------------------------------------------------------

UserInterface::~UserInterface(void){
}

//--------------------------------------------------------------------------------
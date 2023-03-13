#include "StdAfx.h"
#include "FileHandling.h"
#include <fstream>
#include <sstream>
#include "UserInterface.h"

//--------------------------------------------------------------------------------

FileHandling::FileHandling(void){
}

//--------------------------------------------------------------------------------


void FileHandling::WriteToShapesFile (ShapesInALayout& const Layout){
	std::fstream WriteShapes ("ShapesInALayout.txt", std::ios::out | std::ios::trunc);
	for (int i=0; i<Layout.NumberofObjects(); i++){
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).first -> Identity())<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).first -> Dimension()[0])<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).first -> Dimension()[1])<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).first -> Dimension()[2])<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).first -> GetUtility())<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).second -> GetItemName())<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).second -> GetItemRate())<<",";
		WriteShapes<<(Layout.RetrieveShapeAndItem(i).second -> GetMeasurementUnit())<<"\n";
	}
	WriteShapes.close();
}

//--------------------------------------------------------------------------------

ShapesInALayout& FileHandling::ReadFromShapesFile (ShapesInALayout& Layout){
	std::string Line = " ", TempString = " ";

	std::fstream ReadShapes ("ShapesInALayout.txt", std::ios::in);

	while(std::getline(ReadShapes, Line)){
		std::stringstream SStream(Line);
		getline(SStream, TempString,',');
		Shape* Sptr = UserInterface::ReturnShapePointer();
		if (TempString == "R"){
			int Length = 0, Breadth = 0;
			std::string Utility = " ";
			getline(SStream, TempString,',');
			Length = atof(TempString.c_str());
			getline(SStream, TempString,',');
			Breadth = atof(TempString.c_str());
			getline(SStream, Utility,',');
			getline(SStream, Utility,',');
			Sptr = UserInterface::CreateRectangleUsingInputFromUser(Length,Breadth,Utility);
		}
		else if (TempString == "T"){
			int Side1 = 0, Side2 = 0, Side3 = 0;
			std::string Utility = " ";
			getline(SStream, TempString,',');
			Side1 = atof(TempString.c_str());
			getline(SStream, TempString,',');
			Side2 = atof(TempString.c_str());
			getline(SStream, TempString,',');
			Side3 = atof(TempString.c_str());
			getline(SStream, Utility,',');
			Sptr = UserInterface::CreateTriangleUsingInputFromUser(Side1,Side2,Side3,Utility);
		}
		else if (TempString == "C"){
			int Radius = 0;
			std::string Utility = " ";
			getline(SStream, TempString,',');
			Radius = atof(TempString.c_str());
			getline(SStream, Utility,',');
			getline(SStream, Utility,',');
			getline(SStream, Utility,',');
			Sptr = UserInterface::CreateCircleUsingInputFromUser(Radius,Utility);
		}
		else{
		}
		std::string Itemname = " ", Measurementunit = " ";
		float Rate = 0.0;
		getline(SStream, TempString,',');
		Itemname = TempString.c_str();
		getline(SStream, TempString,',');
		Rate = atof(TempString.c_str());
		getline(SStream, TempString,',');
		Measurementunit = TempString.c_str();
		ItemAndRate* IAndRptr = UserInterface::CreateNewItem(Itemname, Rate, Measurementunit);
		Layout.AddShapeAndItem(Sptr,IAndRptr);
	}
	return Layout;
}


//--------------------------------------------------------------------------------

void FileHandling::WriteToItemsFile (ItemAndRateChart& const ItemAndRateChart){
	std::fstream WriteItems ("ItemAndRateChart.txt", std::ios::out | std::ios::trunc);
	for (int i=0; i<ItemAndRateChart.NumberofObjects(); i++){
		WriteItems<<(*ItemAndRateChart.RetrieveItemAndRate(i)).GetItemName()<<',';
		WriteItems<<(*ItemAndRateChart.RetrieveItemAndRate(i)).GetItemRate()<<',';
		WriteItems<<(*ItemAndRateChart.RetrieveItemAndRate(i)).GetMeasurementUnit()<<'\n';
	}
	WriteItems.close();
}

//--------------------------------------------------------------------------------

ItemAndRateChart& FileHandling::ReadFromItemsFile (ItemAndRateChart& ItemAndRateChart){
	std::string Line = " ", TempString = " ";
	std::fstream ReadItems ("ItemAndRateChart.txt", std::ios::in);
	while(std::getline(ReadItems, Line)){
		std::string itemname = " ", measurementunit = " ";
		float rate = 0.0;
		std::stringstream SStream(Line);
		getline(SStream, TempString,',');
		itemname = TempString.c_str();
		getline(SStream, TempString,',');
		rate = atof(TempString.c_str());
		getline(SStream, TempString,',');
		measurementunit = TempString.c_str();
		ItemAndRate* IAndR = UserInterface::CreateNewItem(itemname, rate, measurementunit);
		ItemAndRateChart.AddItem(IAndR);
	}
	return ItemAndRateChart;
}

//--------------------------------------------------------------------------------

FileHandling::~FileHandling(void){
}

//--------------------------------------------------------------------------------
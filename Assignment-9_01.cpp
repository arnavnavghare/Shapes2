#include "stdafx.h"
#include "Shape.h"
#include "rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "ItemAndRate.h"
#include "ItemAndRateChart.h"
#include "ShapesInALayout.h"
#include "UserInterface.h"
#include "FileHandling.h"


int main(){
	ShapesInALayout Layout;
	ItemAndRateChart ItemsAndRates;
	UserInterface UI;
	FileHandling FH;

	FH.ReadFromShapesFile(Layout);
	FH.ReadFromItemsFile(ItemsAndRates);

	enum CHOICE {ShowRateChart  = 1, AddItemToRateChart, RemoveItemFromRateChart, ShowAllShapesInTheLayout, AddNewShapeToTheLayout, RemoveAShapeFromTheLayout, SaveAll, SaveAndExit};
	enum SHAPE {Rec = 1, Tri, Cir};
	
	while(true){
		system("cls");
		UI.DisplayMainMenuSelectionOptions();
		int Choice = UI.GetChoiceFromUser();
		switch (Choice){
		case (CHOICE::ShowRateChart):{
			system("cls");
			UI.ShowItemsInRateChart(ItemsAndRates);
			system("pause");
			break;
			   }

		case (CHOICE::AddItemToRateChart):{
			system("cls");
			UI.ShowItemsInRateChart(ItemsAndRates);
			ItemAndRate* IAndRptr = UI.CreateNewItem();
			ItemsAndRates.AddItem(IAndRptr);
			system("cls");
			UI.DisplayEntryAddedSuccessfullyStatement();
			UI.ShowItemsInRateChart(ItemsAndRates);
			system("pause");
			break;
			   }

		case (CHOICE::RemoveItemFromRateChart):{
			system("cls");
			UI.ShowItemsInRateChart(ItemsAndRates);
			UI.DisplayRemoveItemStatement();
			ItemsAndRates.RemoveItemAndRate(UI.GetChoiceFromUser());
			system("cls");
			UI.DisplayRemoveSuccessfulStatement();
			UI.ShowItemsInRateChart(ItemsAndRates);
			system("pause");
			break;
			   }

		case (CHOICE::ShowAllShapesInTheLayout):{
			system("cls");
			UI.ShowShapesInLayout(Layout);
			system("pause");
			break;
			   }

		case (CHOICE::AddNewShapeToTheLayout):{
			system("cls");
			UI.ShowShapesInLayout(Layout);
			UI.DisplayShapeSelectionOptions();
			int Choice = UI.GetChoiceFromUser(); 
			Shape* ptr;
			Shape Shape;
			switch (Choice){
			case (SHAPE::Rec):{
				rectangle* R = UI.CreateRectangleUsingInputFromUser();
				ptr = R;
				break;
				   }

			case (SHAPE::Tri):{
				Triangle* T = UI.CreateTriangleUsingInputFromUser();
				ptr = T;
				break;
				   }

			case (SHAPE::Cir):{
				Circle* C = UI.CreateCircleUsingInputFromUser();
				ptr = C;
				break;
				   }
			}
			UI.ShowItemsInRateChart(ItemsAndRates);
			UI.DisplayItemSelectionFromUser();
			Layout.AddShapeAndItem(ptr, UI.GetItemSelectionFromUser(ItemsAndRates, UI.GetChoiceFromUser()-1));
			system("cls");
			UI.DisplayEntryAddedSuccessfullyStatement();
			UI.ShowShapesInLayout(Layout);
			system("pause");
			   }
			   break;

		case (CHOICE::RemoveAShapeFromTheLayout):{
			system("cls");
			UI.ShowShapesInLayout(Layout);
			UI.DisplayRemoveShapeStatement();
			Layout.RemoveShapeAndItem(UI.GetChoiceFromUser());
			system("cls");
			UI.DisplayRemoveSuccessfulStatement();
			UI.ShowShapesInLayout(Layout);
			system("pause");
			break;
			   }

		case (CHOICE::SaveAll):{
			system("cls");
			FH.WriteToShapesFile(Layout);
			FH.WriteToItemsFile(ItemsAndRates);
			UI.DisplaySaveSuccessfulStatement();
			system("pause");
			break;
			   }

		case (CHOICE::SaveAndExit):{
			FH.WriteToShapesFile(Layout);
			FH.WriteToItemsFile(ItemsAndRates);
			return 0;
			break;
			   }
		}
	}

	FH.WriteToShapesFile(Layout);
	FH.WriteToItemsFile(ItemsAndRates);

	return 0;
}
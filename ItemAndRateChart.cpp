#include "StdAfx.h"
#include "ItemAndRateChart.h"

//--------------------------------------------------------------------------------

ItemAndRateChart::ItemAndRateChart(void){
}

//--------------------------------------------------------------------------------

void ItemAndRateChart::AddItem(ItemAndRate* &ItemAndRate){
	m_itemandratechart.push_back(ItemAndRate);
}

//--------------------------------------------------------------------------------

void ItemAndRateChart::RemoveItemAndRate(const int& Index){
	delete m_itemandratechart[Index-1];
	m_itemandratechart.erase(m_itemandratechart.begin()+Index-1);
}

//--------------------------------------------------------------------------------

ItemAndRate* const ItemAndRateChart::RetrieveItemAndRate(const int& Index){
	return m_itemandratechart[Index];
}

//--------------------------------------------------------------------------------

int ItemAndRateChart::NumberofObjects() const{
	return m_itemandratechart.size();
}

//--------------------------------------------------------------------------------

ItemAndRateChart::~ItemAndRateChart(void){
}

//--------------------------------------------------------------------------------
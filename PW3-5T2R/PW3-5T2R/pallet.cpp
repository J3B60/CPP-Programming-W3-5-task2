#include <iostream>
#include <string>
#include <vector>
#include "pallet.h"

using namespace std;

void Pallet::ListAllItems() {					//Print List from pallet.cpp
	if (Pallet::PalletItems.size() == 0) {
		cout << "Pallet EMPTY" << endl;
	}
	else {
		for (int x = 0; x <= PalletItems.size() - 1; x++) {
			cout << Pallet::PalletItems[x] << endl;
		}
	}
}

string Pallet::AddItem(string item) {			//Add new item + ###USER INPUT+###
	if (Pallet::GetCurrentWeight() + 1/*+NewItem(Weight)*/ <= GetMaxWeight()) {
		Pallet::PalletItems.push_back(item);
		return string("Add Successful");
	}
	else {
		return string("Add Fail - Pallet Full");
	}

}

void Pallet::RemoveTopItem() {				//Remove top item
	if (Pallet::PalletItems.size() != 0) {
		PalletItems.pop_back();
	}
}

string Pallet::GetItemAtPosition(int position) {	//Get Pallet Item **Missing Ptc!! for tests (Return to Source.cpp rather than print)
	if (position <= Pallet::PalletItems.size() && position > 0) {	//NOTE START FROM 1
		return Pallet::PalletItems[position - 1];
	}
	else {
		return string("Item does not exist - Incorrect Input");
	}
}

int Pallet::GetCurrentWeight() {
	return Pallet::PalletItems.size();		//Each item weigh 1 unit (Return to Source.cpp rather than print)
}

int Pallet::GetMaxWeight() {
	return Pallet::maxWeight;				//maxWeight defined from?? (Return to Source.cpp rather than print)
}

Pallet::Pallet(int i, int mW) {
	Pallet::id = i;
	Pallet::maxWeight = mW;
}

Pallet::~Pallet() {
	//###
}
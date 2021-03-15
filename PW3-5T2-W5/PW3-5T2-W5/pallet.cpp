#include <iostream>
#include <string>
#include <vector>
#include "pallet.h"

using namespace std;

void Pallet::ListAllItems() {					//Print List from pallet.cpp
	if (Pallet::PalletItems.size() == 0 || PalletItems.size() < 0) {	//If Empty or NULL Pallet from default constructor
		cout << "Pallet EMPTY" << endl;
	}
	else {
		for (int x = 0; x < PalletItems.size(); x++) {
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
	if (PalletItems.size() > 0) {		//Check if Pallet not Empty
		PalletItems.pop_back();			//Remove
	}
	else {
		cout << "Cannot Remove. Pallet Empty" << endl;	//List Empty, so Cannot remove anymore
	}
}

string Pallet::GetItemAtPosition(int position) {	//Get Pallet Item
	if (position < PalletItems.size() && position >= 0) {	//NOTE START FROM 0
		return PalletItems[position];						//Return to MAIN for Print
	}
	else {
		return string("Item does not exist - Incorrect Input"); //Return Invalid position to MAIN for Print
	}
}

int Pallet::GetCurrentWeight() {
	return PalletItems.size();		//Each item weight 1 unit
}

int Pallet::GetMaxWeight() {
	return maxWeight;				//Getter for maxWeight Variable
}

int Pallet::counterP = 0;

Pallet::Pallet(int PID, int mW) { //Constructor
	counterP++;
	id = counterP;	
	maxWeight = mW; //PID NOT USED, JUST FOR PALLET GENERATOR SO, ID IS AUTOASSIGNED TO PREVENT IDENTICALS
}

Pallet::Pallet() { //Default Constructor for an EMPTY/NULL pallet object
	id = -1;
	maxWeight = -1;
}

void Pallet::ClearPallet() {	//Extra //Delete All Pallet Items and Assign new ID (For CargoStorage)
	int x = PalletItems.size();
	for (int count = 0; count < x; count++) { //Remove each Item for the size of pallet
		Pallet::RemoveTopItem();
	}
	counterP++;
	id = counterP;				//New ID (The Previous ID is now in CargoStorage)
}

int Pallet::GetPID() { //Getter for Pallet ID
	return id;
}

Pallet::~Pallet() {
	//###
}
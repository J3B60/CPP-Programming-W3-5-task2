#include <iostream>
#include <string>
#include <vector>
#include "cargostorage.h"
#include "pallet.h"

bool CargoStorage::AddPalletAtPosition(int position, Pallet& pallet) {	//Positions from 0, Pallet pass by reference used!!for ClearPallet()
	for (int countforid = 0; countforid < maxStorage; countforid++) { //ID check to prevent duplicates
		if (pallet.GetPID() == CargoStorageItems[countforid].GetPID()) { //If Identical Pallet found return false (Stop this function)
			return false;
		}
	}
	if (position < maxStorage && position >= 0 && CargoStorageItems[position].GetPID() == e.GetPID() && pallet.GetPID() != e.GetPID()) { //Position value check and NULLPallet check
		CargoStorageItems[position] = pallet; //Assign Pallet to Position in CargoStorageItems
		pallet.ClearPallet();				//Clear Pallet and assign new ID, Passed by Reference
		return true;
	}
	else {
		return false; //If position and ID's dont match then return false
	}
}

Pallet CargoStorage::RetrievePalletFromPosition(int position) { //Retrieve pallet, Positions from 0
	if (position < maxStorage && position >= 0 && CargoStorageItems[position].GetPID() != e.GetPID()) {
		Pallet TempHolder;	//Temp Holder
		TempHolder = CargoStorageItems[position];	//TempHolder takes from Cargostorage
		CargoStorageItems[position] = e;	//CargoStorage Slot = EMPTY
		return TempHolder; //TempHolder is detroyed at the end of function
	}
	else {
		cout << "Check Position input/No Item at position" << endl; //If position is not right or if EMPTY selected then no Pallet Assigned
	}
}

void CargoStorage::ListContents() { //List CargoStorageItems Contents
	for (int x = 0; x < maxStorage; x++) { //List Up to the end of vector CargoStorageItems
		if (CargoStorage::CargoStorageItems[x].GetPID() != e.GetPID()) { //Check that it's not EMPTY
			cout << "SID" << id_cargostorage << " Position" << x << ": CONTAINS: " << endl; //Message to say that this slot contains a pallet (SID = Storage ID)
			CargoStorageItems[x].ListAllItems();	//List's Pallets Contents
		}
		else {
			cout << "SID" << id_cargostorage << " Position" << x << ": EMPTY" << endl; //EMPTY Pallet at this Position
		}
	}
 }

CargoStorage::~CargoStorage() {
	//###
}

int CargoStorage::counterCS = 0; //Set Counter Start

CargoStorage::CargoStorage() {
	counterCS++;
	id_cargostorage = counterCS; //New Unique ID
	maxStorage = 10;	//~~~AS DEFIEND FROM THE WORKSHEET~~~
	CargoStorageItems.resize(maxStorage, e); //Resize to maxStorage and fill with EMPTY/NULL pallet Object
}
int CargoStorage::GetCSID() {
	return id_cargostorage; //Getter for CSID/SID CargoStorage ID/ Storage ID
}

int CargoStorage::GetCSMS() {
	return maxStorage; //Getter for maxStorage
}
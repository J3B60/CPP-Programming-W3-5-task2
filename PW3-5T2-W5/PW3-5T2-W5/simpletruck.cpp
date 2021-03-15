#include <iostream>
#include <string>
#include <vector>
#include "cargostorage.h"
#include "pallet.h"
#include "simpletruck.h"

int SimpleTruck::counterST = 0;

SimpleTruck::SimpleTruck() {
	counterST++;
	SimpleTruck::id_simpletruck = counterST;
}

bool SimpleTruck::PickUpItem(int position, CargoStorage& storage) {
	if (position < storage.GetCSMS() && position >= 0) { //If the position is valid
		if (storage.CargoStorageItems[position].GetPID() != e.GetPID() && Item.GetPID() == e.GetPID()) { //If CargoStorageItems at chosen position is not EMPTY and Simpletruck's Item is EMPTY
			Item = storage.CargoStorageItems[position]; //Assign Cargostorage's chosen item to SimpleTruck
			storage.CargoStorageItems[position] = e;	//Make position in cargoStorage = EMPTY
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

bool SimpleTruck::PutDownItem(int position, CargoStorage& storage) {
	if (position < storage.GetCSMS() && position >= 0) { //If the position is valid
		if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item.GetPID () != e.GetPID()) { //If CargoStorageItems at chosen position IS EMPTY and Simpletruck's Item IS NOT EMPTY
			storage.CargoStorageItems[position] = Item; //Make the Position in CargoStorageItems = Item from SimpleTruck
			Item = e;		//Set Item to EMPTY/NULL Pallet object
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

SimpleTruck::~SimpleTruck() {
	//###
}

int SimpleTruck::GetTID() { //Exrtra
	
	return id_simpletruck;
}

string SimpleTruck::GetTTYPE() {
	return string("ST");
}
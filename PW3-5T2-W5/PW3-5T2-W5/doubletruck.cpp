#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "doubletruck.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

bool DoubleTruck::PickUpItem(int position, CargoStorage& storage) { //Replace SimpleTruck function
	if (position < storage.GetCSMS() && position >= 0) {//Check if position is valid
		if (storage.CargoStorageItems[position].GetPID() != e.GetPID() && Item.GetPID() == e.GetPID()) {//###Inefficient//Check ID's
			Item = storage.CargoStorageItems[position];			//Assign CargoStorageItem in chosen position to doubletrucks 1st Item (ITEM variable used from SimpleTruck)
			storage.CargoStorageItems[position] = e; //Make chosen position in CargosStorageItems to be EMPTY
			return true;
		}
		else {//if Item 1 variable already has an item try item2
			if (storage.CargoStorageItems[position].GetPID() != e.GetPID() && Item2.GetPID() == e.GetPID()) {//Check ID's
				Item2 = storage.CargoStorageItems[position]; //The Same as Item 1 code but adjusted for Item2
				storage.CargoStorageItems[position] = e;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

bool DoubleTruck::PutDownItem(int position, CargoStorage& storage) { //Replace SimpleTruck's Function
	if (position < storage.GetCSMS() && position >= 0) { //Check if position is valid
		if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item.GetPID() != e.GetPID()) {//Inefficient//Check ID's
			storage.CargoStorageItems[position] = Item; //Assign CargoStorageItems at chosen position with the Item1 from double truck
			Item = e; //Item1 = EMPTY
			return true;
		}
		else {
			if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item2.GetPID() != e.GetPID()) { //Same code as item1 but adjusted for Item2
				storage.CargoStorageItems[position] = Item2;
				Item2 = e;
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

string DoubleTruck::GetTTYPE() {
	return string("DT");
}
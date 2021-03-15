#include "pallet.h"
#include "cargostorage.h"
#include "simpletruck.h"
#include "doubletruck.h"
#include <vector>
#include <iostream>
#include <string>
#include "comparatortruck.h"

using namespace std;

bool ComparatorTruck::PutDownItem(int position, CargoStorage& storage) {
	if (Item.GetCurrentWeight() > Item2.GetCurrentWeight()) { //###Inefficient//If Item1 is heavier than item2 then let Item 1 go first, else do the other way round
		if (position < storage.GetCSMS() && position >= 0) {	//If position chosen is valid
			if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item.GetPID() != e.GetPID()) { //If ID's correct...(See doubleTruck or simple truck for this code below since it's the same)
				storage.CargoStorageItems[position] = Item;
				Item = e;
				return true;
			}
			else {
				if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item2.GetPID() != e.GetPID()) {
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
	else {//###Inefficient
		if (position < storage.GetCSMS() && position >= 0) {
			if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item2.GetPID() != e.GetPID()) {
				storage.CargoStorageItems[position] = Item2;
				Item2 = e;
				return true;
			}
			else {
				if (storage.CargoStorageItems[position].GetPID() == e.GetPID() && Item.GetPID() != e.GetPID()) {
					storage.CargoStorageItems[position] = Item;
					Item = e;
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

}

string ComparatorTruck::GetTTYPE() {
	return string("CT");
}
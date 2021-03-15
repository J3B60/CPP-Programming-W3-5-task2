#include <iostream>
#include <string>
#include <vector>
#include "cargostorage.h"
#include "pallet.h"
#include "simpletruck.h"

SimpleTruck::SimpleTruck(int id_st) {
	Pallet e;
	SimpleTruck::id_simpletruck = id_st;
	id_simpletruck++;
	Item = e;
}

bool SimpleTruck::PickUpItem(int position, CargoStorage& storage) {
	Pallet e;
	if (position < storage.CargoStorageItems.size() -1 && storage.CargoStorageItems[position].GetID() != -1 && Item.GetID() == -1){
		Item = storage.RetrievePalletFromPosition(0);	//NEED TO USE CARGOSTORAGE ID
		return true;
	}
	else{
		return false;
	}
	
}

bool SimpleTruck::PutDownItem(int position, CargoStorage& storage) {
	Pallet e;
	if (position < storage.CargoStorageItems.size() - 1 && storage.CargoStorageItems[position].GetID() == -1 && Item.GetID() != -1){
		storage.AddPalletAtPosition(position, Item);	//NEED TO USE CARGOSTORAGE ID
		Item = e;
		return true;
	}
	else{
		return false;
	}
}

SimpleTruck::~SimpleTruck() {
	//###
}

SimpleTruck::SimpleTruck() {
	id_simpletruck = -1;
}

int SimpleTruck::id_simpletruck = 0;
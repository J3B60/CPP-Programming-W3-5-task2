#include <iostream>
#include <string>
#include <vector>
#include "cargostorage.h"
#include "pallet.h"

CargoStorage::CargoStorage(int maxS) {
	Pallet e;
	id_cs++;
	for (int i = 0; i < maxS; i++)
	{
		CargoStorageItems.push_back(e);
	}
}

bool CargoStorage::AddPalletAtPosition(int position, Pallet pallet) {
	Pallet e;
	if (position < CargoStorageItems.size()-1 && position >= 0 && CargoStorageItems[position].GetID() == -1/* && pallet.GetID() != -1*/) { //NEED EMPTY PALLET NULL
		CargoStorageItems[position] = pallet;
		pallet = e;
		return true;
	}
	else {
		return false;
	}
}

Pallet CargoStorage::RetrievePalletFromPosition(int position) {
	Pallet e;
	if (position < CargoStorageItems.size() -1 && position >= 0 && CargoStorageItems[position].GetID() == -1) { //NEED EMPTY PALLET NULL
		Pallet x;	//Buffer?!? Destroyed after function ends?!?!
		x = CargoStorageItems[position];
		CargoStorageItems[position] = e; //NEED EMPTY PALLET NULL
		return x;
		//Delete!??!
	}
	else {
		cout << "Check Position input/No Item at position" << endl;
		return e;
	}
}

void CargoStorage::ListContents() {
	for (int x = 0; x < CargoStorageItems.size(); x++) {
		if (CargoStorageItems[x].GetID() != -1) {	//NEED EMPTY PALLET NULL
			cout << x << endl;
			CargoStorageItems[x].ListAllItems();
		}
		else {
			cout << x << "EMPTY" << endl;
		}
	}
 }

CargoStorage::~CargoStorage() {
	//###
}

int CargoStorage::id_cs = 1;

CargoStorage::CargoStorage() {
	id_cs = -1;
}
#include <iostream>
#include <string>
#include <vector>
#include "cargostorage.h"
#include "pallet.h"

CargoStorage::CargoStorage(int id_cs, int mS) {
	CargoStorage::maxStorage = mS;
	CargoStorage::id_cargostorage = id_cs;
}

bool CargoStorage::AddPalletAtPosition(int position, Pallet pallet) {
	if (position < CargoStorage::maxStorage && position > 0 && CargoStorage::CargoStorageItems[position] == NULL) {
		CargoStorage::CargoStorageItems[position] = pallet;
		//delete pallet; //Check if this is right?!??! or use destructor to destroy (To prevent duplications and putting the same pallet into the cargostorage)
		for (int x = 0; x < pallet.GetMaxWeight(); x++) {

		}
		return true;
	}
	else {
		return false;
	}
}

Pallet CargoStorage::RetrievePalletFromPosition(int position) {
	if (position < CargoStorage::maxStorage && position > 0 && CargoStorage::CargoStorageItems[position] != NULL) {
		Pallet x;	//Buffer?!?
		x = CargoStorage::CargoStorageItems[position];
		CargoStorage::CargoStorageItems[position] = NULL;
		return x;
		//Delete!??!
	}
	else {
		cout << "Check Position input/No Item at position" << endl;
	}
}

void CargoStorage::ListContents() {
	for (int x = 0; x < CargoStorage::maxStorage; x++) {
		if (CargoStorage::CargoStorageItems[x] != NULL) {
			(CargoStorage::CargoStorageItems[x]).ListAllItems();
		}
		else {
			cout << x << "EMPTY" << endl;
		}
	}
 }

CargoStorage::~CargoStorage() {
	//###
}
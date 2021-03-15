#ifndef CARGOSTORAGE_H
#define CARGOSTORAGE_H
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "pallet.h"

using namespace std;

class CargoStorage {
public:
	bool AddPalletAtPosition(int position, Pallet pallet);
	Pallet RetrievePalletFromPosition(int position);
	void ListContents();
	CargoStorage(){}
	CargoStorage(int id_cs, int mS);
	~CargoStorage();
protected:
	int maxStorage;
	int id_cargostorage;
	vector<Pallet> CargoStorageItems; //Set to 10 as in worksheet
	
};
#endif
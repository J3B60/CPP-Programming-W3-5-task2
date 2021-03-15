#ifndef CARGOSTORAGE_H
#define CARGOSTORAGE_H
#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"

using namespace std;

class CargoStorage {
public:
	bool AddPalletAtPosition(int position, Pallet& pallet);
	Pallet RetrievePalletFromPosition(int position);
	void ListContents();
	int GetCSID();
	int GetCSMS();
	CargoStorage();
	~CargoStorage();
	vector<Pallet> CargoStorageItems; //Set to 10 as in worksheet, Cargo's Storage
protected:
	Pallet e;
	static int counterCS;
	int maxStorage;
	int id_cargostorage;
};
#endif
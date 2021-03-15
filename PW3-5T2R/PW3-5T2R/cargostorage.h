#ifndef CARGOSTORAGE_H
#define CARGOSTORAGE_H
#include <iostream>
#include <vector>
#include <string>

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
	int id_cs;
	
};
#endif
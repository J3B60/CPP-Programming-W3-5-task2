#ifndef SIMPLETRUCK_H
#define SIMPLETRUCK_H
#include <iostream>
#include <vector>
#include <string>
#include "cargostorage.h"
#include "pallet.h"

using namespace std;

class SimpleTruck {
public:
	virtual bool PickUpItem(int position, CargoStorage& storage);
	virtual bool PutDownItem(int position, CargoStorage& storage);
	int GetTID(); //EXTRA
	virtual string GetTTYPE(); //Extra
	SimpleTruck();
	~SimpleTruck();
protected:
	Pallet e;
	static int counterST;
	int id_simpletruck;
	Pallet Item;	//Hold a Pallet Item
};
#endif
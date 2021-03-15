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
	bool PickUpItem(int position, CargoStorage& storage);
	bool PutDownItem(int position, CargoStorage& storage);
	SimpleTruck();
	SimpleTruck(int id_st);
	~SimpleTruck();
protected:
	static int id_simpletruck;
	Pallet Item;//####

};
#endif
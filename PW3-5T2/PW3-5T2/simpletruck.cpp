#include <iostream>
#include <string>
#include <vector>
#include "cargostorage.h"
#include "pallet.h"
#include "simpletruck.h"

SimpleTruck::SimpleTruck(int id_st) {
	SimpleTruck::id_simpletruck = id_st;
}

bool SimpleTruck::PickUpItem(int position, CargoStorage& storage) {
	Item = storage.at(position);
}

bool SimpleTruck::PutDownItem(int position, CargoStorage& storage) {
	
}

SimpleTruck::~SimpleTruck() {
	//###
}
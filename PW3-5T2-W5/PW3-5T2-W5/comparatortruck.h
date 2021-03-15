#ifndef COMPARATORTRUCK_H
#define COMPARATORTRUCK_H
#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"
#include "simpletruck.h"
#include "cargostorage.h"
#include "doubletruck.h"

using namespace std;

class ComparatorTruck : public DoubleTruck {
public:
	bool PutDownItem(int position, CargoStorage& storage);
	string GetTTYPE(); //Extra
};
#endif
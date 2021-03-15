#ifndef DOUBLETRUCK_H
#define DOUBLETRUCK_H
#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"
#include "simpletruck.h"
#include "cargostorage.h"

using namespace std;

class DoubleTruck : public SimpleTruck {
	public:
		bool PickUpItem(int position, CargoStorage& storage);
		virtual bool PutDownItem(int position, CargoStorage& storage);
		virtual string GetTTYPE(); //Extra
	protected:
		Pallet Item2; //Hold a second Pallet item, including variable from simpletruck
};
#endif
#ifndef LOADINGBAY_H
#define LOADINGBAY_H
#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"
#include "cargostorage.h"

using namespace std;

class LoadingBay : public CargoStorage{
	public:
		void Arrive();
		void Leave();
};
#endif
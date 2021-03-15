#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"
#include "cargostorage.h"
#include "palletgenerator.h"
#include "loadingbay.h"

using namespace std;

void LoadingBay::Arrive(){		//Fill Loading Bay with Generated Pallets
	for (int x = 0; x < maxStorage; x++) { //For Each position in Loading Bay
		if (CargoStorageItems[x].GetPID() == e.GetPID()) { //If slot is empty
			Pallet p = GeneratePallet();	//Have Pallet P = a Generated Pallet
			CargoStorageItems[x] = p;		//The Slot = That new pallet
		}
		else {
			cout << "Position: " << x << "FULL" << endl; //If Position has Pallet print, pallet at position is FULL
		}
	}
}

void LoadingBay::Leave(){
	Pallet e;
	for (int x = 0; x < maxStorage; x++){ //For Each Position
		//Can Add Code to transfer Pallets Here to a truck or cargostorage
		CargoStorageItems[x] = e; //Each Position in LoadingBay = EMPTY
	}
}
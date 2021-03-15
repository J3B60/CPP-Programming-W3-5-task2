#include "loadingbay.h"
#include "palletgenerator.h"

using namespace std

void LoadingBay::Arrive(){
	if (LoadingBay_Storage.size() < 10){
		//Pallet Generator code + Add code/cargostorage
	}
	else{
		cout << "Unable to add, LoadingBay FULL" << endl;
	}
}

void LoadingBay::Leave(){
	Pallet e;
	for (int x = 0; x < LoadingBay_Storage.size(); x++){
		
	}
}

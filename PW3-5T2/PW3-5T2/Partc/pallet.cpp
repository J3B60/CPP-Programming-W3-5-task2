#include <iostream>
#include <string>
#include <vector>
#include "pallet.h"

using namespace std;

void Pallet::ListAllItems() {
	if (Pallet::PalletItems.size() == 0) {
		cout << "Pallet EMPTY" << endl;
	}
	else {
		for (int x = 0; x <= PalletItems.size() - 1; x++) {
			cout << Pallet::PalletItems[x] << endl;
		}
	}
}

void Pallet::AddItem(string item) {			//Add new item(USER INPUT to add once test is done)
	Pallet::PalletItems.push_back(item);
}

void Pallet::RemoveTopItem() {				//Remove top item
	if (Pallet::PalletItems.size() != 0) {
		PalletItems.pop_back();
	}
}

string Pallet::GetItemAtPosition(int position) {
	return string();
}
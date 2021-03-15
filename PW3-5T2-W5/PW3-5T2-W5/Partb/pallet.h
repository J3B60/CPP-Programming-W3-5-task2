#ifndef PALLET_H
#define PALLET_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pallet {
	public:
		Pallet() {};
		void ListAllItems();
		void AddItem(string item);
		void RemoveTopItem();
		string GetItemAtPosition(int position);
	protected:
		std::vector<std::string> PalletItems;
};
#endif
#ifndef PALLET_H
#define PALLET_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Pallet {
public:
	void ListAllItems();
	string AddItem(string item);
	void RemoveTopItem();
	string GetItemAtPosition(int position);
	int GetCurrentWeight();
	int GetMaxWeight();
	Pallet() {};
	Pallet(int i, int mW);
	~Pallet();
protected:
	int id;
	int maxWeight;
	vector<string> PalletItems;
};
#endif
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
	int GetPID();		//Extra
	void ClearPallet(); //Extra
	Pallet();
	Pallet(int PID, int mW);
	~Pallet();
protected:
	static int counterP;	//Extra
	int id;
	int maxWeight;
	vector<string> PalletItems; //Pallets Storage
};
#endif
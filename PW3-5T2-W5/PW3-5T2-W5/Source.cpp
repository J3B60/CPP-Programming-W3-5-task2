#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include "pallet.h"
#include "cargostorage.h"
#include "doubletruck.h"
#include "loadingbay.h"
#include "simpletruck.h"
#include "comparatortruck.h"

using namespace std;

void TrucksList();
void StoragesList();
void BaysList();
bool TrucksSearchAssign(int UIN, int& TUIN, int& TLUIN);
void TrucksSearchType(int TLUIN, int TUIN);
int StoragesSearch();
bool BaysSearchArrive(int UIN);
bool BaysSearchLeave(int UIN);

Pallet p;
CargoStorage cs1, cs2, cs3;
LoadingBay lb1, lb2;
SimpleTruck st1, st2, st3, st4, st5;
DoubleTruck dt1, dt2, dt3;
ComparatorTruck ct1, ct2;
vector<SimpleTruck> STrucks = { st1, st2, st3, st4, st5 };
vector <DoubleTruck> DTrucks = { dt1, dt2, dt3 };
vector <ComparatorTruck> CTrucks = {ct1, ct2 };
vector<CargoStorage> Storages = { cs1, cs2, cs3 };
vector<LoadingBay> Bays = { lb1, lb2 };

int main() {
	int MUIN, 
	int UIN = -1;
	int TUIN = -1; //Main Menu User Input, User Input, Truck User Input //Must be changed, can be changed back to -1
	int TLUIN = -1;
	int PUIN = -1;//Will be changed when user uses program //Position in Sotrage
	int SUIN = -1;//Will be changed when user uses program //Storage Selected
	cout << "---BoxMovers Ltd. Warehouse #1--- " << endl;
	while (1) {
		//#################################################################
		cout << endl << "MENU - PLEASE INPUT NUMBER" << endl << "1 - Delivery into Loading Bay" << endl << "2 - Delivery out of Loading Bay" << endl << "3 - Select a Truck" << endl << "4 - Truck Task" << endl << "5 - List Items in Storage" << endl << "Current Selected Truck: ";
		if (TUIN == -1 || TLUIN == -1) {
			cout << "NONE" << endl;
		}
		else {
			TruckListType(TLUIN, TUIN);
		}
		cin >> MUIN;
		//#################################################################
		switch (MUIN) {
		case 1: //Works for Any Number of Loading Bays
			cout << "Select Loading Bay by ID Number" << endl;	//List all Loading Bay Areas (Can be Made into a search function)
			BaysList();
			cin >> UIN;	//Select a Loading Bay Area
			if (BaysSearchArrive(UIN) == true) {
				cout << "Arrive Successful" << endl;
			}
			else {
				cout << "Arrive Unsuccessful, please check the input is a NUMBER and exists" << endl;
			}
			break;
		case 2: //Works for any Number of Loading Bays
			cout << "Select Loading Bay by ID Number" << endl; //List all Loading Bay Areas
			BaysList();
			cin >> UIN;	//Select a Loading Bay Area
			if (BaysSearchLeave(UIN) == true) {
				cout << "Leave Successful" << endl;
			}
			else {
				cout << "Leave Unsuccessful, please check the input is a NUMBER and exists" << endl;
			}
			break;
		//###########################Working
		case 3:
			cout << "Select Truck by ID Number, Set to -1 for NONE" << endl;
			TrucksList();
			cin >> UIN; //User Select Truck
			if (UIN == -1) {
				TUIN = -1;
				cout << "Truck set to NONE" << endl;
			}
			else {
				//##########TODO
			}
			break;
		case 4:
			if (TUIN == -1) {
				cout << "Truck set to NONE, Please Select a Truck and Try again" << endl;
			}
			else {
				cout << "Select task for truck" << endl << "1. Pick Up Item" << endl << "2. Put Down Item" << endl << ":";
				cin >> UIN;
				if (UIN == 1) {
					cout << "Please Select Storage By ID" << endl;
					StoragesList();
					BaysList();
					cin >> UIN;
					for (int Case4LOOP3 = 0; Case4LOOP3 < Storages.size(); Case4LOOP3++) {
						if (UIN == Storages[Case4LOOP3].GetCSID()) {
							SUIN = UIN;
							cout << "Select Pallet" << endl;	//PickUp Function
							Storages[Case4LOOP3].ListContents();
							cin >> UIN;
							PUIN = UIN;
							Trucks[TUIN].PickUpItem(PUIN, Storages[SUIN]);
							break;	//Break for Loop
						}
						if (Case4LOOP3 + 1 == Storages.size()) {
							for (int Case4LOOP4 = 0; Case4LOOP4 < Bays.size(); Case4LOOP4++) {
								if (UIN == Bays[Case4LOOP4].GetCSID()) {
									SUIN = UIN;
									cout << "Select Pallet" << endl;	//PickUp Function
									Bays[Case4LOOP3].ListContents();
									cin >> UIN;
									PUIN = UIN;
									Trucks[TUIN].PickUpItem(PUIN, Bays[SUIN]);
									break;	//Break for Loop
								}
								if (Case4LOOP4 + 1 == Bays.size()) {
									cout << "Invalid Input, Try agian, Input NUMBERS only" << endl; //If othing found then output message (if Case4LOOP3 - 1 is valid this code will not run due to the break which is the wanted outcome)
								}
							}
						}
					}
					break;
				}
				else {
					if (UIN == 2) {
						cout << "Please Select Storage By ID" << endl;
						for (int Case4LOOP = 0; Case4LOOP < Storages.size(); Case4LOOP++) {
							cout << "CS" << Storages[Case4LOOP].GetCSID() << endl;
						}
						for (int Case4LOOP2 = 0; Case4LOOP2 < Bays.size(); Case4LOOP2++) {
							cout << "LB" << Bays[Case4LOOP2].GetCSID() << endl;
						}
						cin >> UIN;
						for (int Case4LOOP3 = 0; Case4LOOP3 < Storages.size(); Case4LOOP3++) {
							if (UIN == Storages[Case4LOOP3].GetCSID()) {
								SUIN = UIN;
								cout << "Select Pallet" << endl;	//PickUp Function
								Storages[Case4LOOP3].ListContents();
								cin >> UIN;
								PUIN = UIN;
								Trucks[TUIN].PickUpItem(PUIN, Storages[SUIN]);
								break;	//Break for Loop
							}
							if (Case4LOOP3 + 1 == Storages.size()) {
								for (int Case4LOOP4 = 0; Case4LOOP4 < Bays.size(); Case4LOOP4++) {
									if (UIN == Bays[Case4LOOP4].GetCSID()) {
										SUIN = UIN;
										cout << "Select Pallet" << endl;	//PickUp Function
										Bays[Case4LOOP3].ListContents();
										cin >> UIN;
										PUIN = UIN;
										Trucks[TUIN].PickUpItem(PUIN, Bays[SUIN]);
										break;	//Break for Loop
									}
									if (Case4LOOP4 + 1 == Bays.size()) {
										cout << "Invalid Input, Try agian, Input NUMBERS only" << endl; //If othing found then output message (if Case4LOOP3 - 1 is valid this code will not run due to the break which is the wanted outcome)
									}
								}
							}
						}
						break;
					}
				}
			}
			break;
		case 5:
			cout << "Select Storage" << endl;
			StoragesList();
			BaysList();
			cin >> UIN;
			for (int Case5LOOP3 = 0; Case5LOOP3 < Storages.size(); Case5LOOP3++) {
				if (UIN == Storages[Case5LOOP3].GetCSID()) {
					Storages[Case5LOOP3].ListContents();
					break;	//Break for Loop
				}
				if (Case5LOOP3 + 1 == Storages.size()) {
					for (int Case5LOOP4 = 0; Case5LOOP4 < Bays.size(); Case5LOOP4++) {
						if (UIN == Bays[Case5LOOP4].GetCSID()) {
							Bays[Case5LOOP4].ListContents();
							break;	//Break for Loop
						}
						if (Case5LOOP3 + 1 == Bays.size()) {
							cout << "Invalid Input, Try agian, Input NUMBERS only" << endl; //If othing found then output message (if Case4LOOP3 - 1 is valid this code will not run due to the break which is the wanted outcome)
						}
					}
				}
			}
			break;
		default:
			cout << "Please Input Valid Number" << endl;
			break;
		}
	}

}

void TrucksList() {
	for (int ListLOOP = 0; ListLOOP < STrucks.size(); ListLOOP++) { //List through Trucks in Vector, covers any number of trucks (NEED TO CHECK IF DOUBLE AND COMPARATOR WORK IN THIS VECTOR)
		cout << STrucks[ListLOOP].GetTTYPE() << STrucks[ListLOOP].GetTID() << endl;
	}
	for (int ListLOOP = 0; ListLOOP < DTrucks.size(); ListLOOP++) { //List through Trucks in Vector, covers any number of trucks (NEED TO CHECK IF DOUBLE AND COMPARATOR WORK IN THIS VECTOR)
		cout << DTrucks[ListLOOP].GetTTYPE() << DTrucks[ListLOOP].GetTID() << endl;
	}
	for (int ListLOOP = 0; ListLOOP < CTrucks.size(); ListLOOP++) { //List through Trucks in Vector, covers any number of trucks (NEED TO CHECK IF DOUBLE AND COMPARATOR WORK IN THIS VECTOR)
		cout << CTrucks[ListLOOP].GetTTYPE() << CTrucks[ListLOOP].GetTID() << endl;
	}
}

void StoragesList() {
	for (int Case4LOOP = 0; Case4LOOP < Storages.size(); Case4LOOP++) {
		cout << "CS" << Storages[Case4LOOP].GetCSID() << endl;
	}
}

void BaysList() {
	for (int Case4LOOP2 = 0; Case4LOOP2 < Bays.size(); Case4LOOP2++) {
		cout << "LB" << Bays[Case4LOOP2].GetCSID() << endl;
	}
}

bool TrucksSearchAssign(int UIN, int& TUIN, int& TLUIN) {//##############TODO
	for (int Case3LOOP2 = 0; Case3LOOP2 < STrucks.size(); Case3LOOP2++) {
		if (UIN == STrucks[Case3LOOP2].GetTID()) {
			TUIN = Case3LOOP2;
			TLUIN = 1;
			return true;	//Break for Loop
		}
	}
	for (int Case3LOOP2 = 0; Case3LOOP2 < DTrucks.size(); Case3LOOP2++) {
		if (UIN == DTrucks[Case3LOOP2].GetTID()) {
			TUIN = Case3LOOP2;
			TLUIN = 2;
			return true;	//Break for Loop
		}
	}
	for (int Case3LOOP2 = 0; Case3LOOP2 < CTrucks.size(); Case3LOOP2++) {
		if (UIN == CTrucks[Case3LOOP2].GetTID()) {
			TUIN = Case3LOOP2;
			TLUIN = 3;
			return true;	//Break for Loop
		}
	}
	return false;
}

int StoragesSearch() {

}

bool BaysSearchArrive(int UIN) {//Inefficient
	for (int Case1LOOP2 = 0; Case1LOOP2 < Bays.size(); Case1LOOP2++) { //Find the right Loading Bay Area
		if (UIN == Bays[Case1LOOP2].GetCSID()) {
			Bays[Case1LOOP2].Arrive();	//Arrive Function
			return true;
		}
		if (Case1LOOP2 + 1 == Bays.size()) {
			return false; //If Nothing found then output message
		}
	}
}

bool BaysSearchLeave(int UIN) {
	for (int Case2LOOP2 = 0; Case2LOOP2 < Bays.size(); Case2LOOP2++) {
		if (UIN == Bays[Case2LOOP2].GetCSID()) {
			Bays[Case2LOOP2].Leave();	//Leave Function
			return true;	//Break for Loop
		}
		if (Case2LOOP2 + 1 == Bays.size()) {
			return false; //If othing found then output message
		}
	}
}

void TruckListType(int TLUIN, int TUIN) {
	switch (TLUIN) {
	case 1:
		cout << STrucks[TUIN].GetTTYPE() << STrucks[TUIN].GetTID() << endl;
		break;
	case 2:
		cout << DTrucks[TUIN].GetTTYPE() << DTrucks[TUIN].GetTID() << endl;
		break;
	case 3:
		cout << CTrucks[TUIN].GetTTYPE() << CTrucks[TUIN].GetTID() << endl;
		break;
	default:
		cout << "ERROR#1" << endl;
		break;
	}
}
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

Pallet p;
CargoStorage cs1, cs2, cs3;
LoadingBay lb1, lb2;
SimpleTruck st1, st2, st3;
DoubleTruck dt1, dt2;
ComparatorTruck ct1;
vector<SimpleTruck> STrucks = { st1, st2, st3, dt1, dt2 };
vector <DoubleTruck> DTrucks = { dt1, dt2, };
vector <ComparatorTruck> CTrucks = { ct1 };


int main() {
	int MenuInput;
	int UserInput;
	int TruckSelect = -1;
	int TruckTask;
	int PalletPosition;
	CargoStorage * StorageSelect = NULL;
	cout << "---BoxMovers Ltd. Warehouse #1--- " << endl;
	while (1) {
		cout << endl << "MENU - PLEASE INPUT NUMBER" << endl << "1 - Delivery into Loading Bay" << endl << "2 - Delivery out of Loading Bay" << endl << "3 - Select a Truck" << endl << "4 - Truck Task" << endl << "5 - List Items in Storage" << endl << "Current Selected Truck: ";
		switch (TruckSelect) {
		case -1:
			cout << "NONE" << endl;
			break;
		case 1:
			cout << st1.GetTTYPE() << st1.GetTID() << endl;
			break;
		case 2:
			cout << st2.GetTTYPE() << st2.GetTID() << endl;
			break;
		case 3:
			cout << st3.GetTTYPE() << st3.GetTID() << endl;
			break;
		case 4:
			cout << dt1.GetTTYPE() << dt1.GetTID() << endl;
			break;
		case 5:
			cout << dt2.GetTTYPE() << dt2.GetTID() << endl;
			break;
		case 6:
			cout << ct1.GetTTYPE() << ct1.GetTID() << endl;
			break;
		}
		cin >> MenuInput;
		switch (MenuInput) {
		case 1:
			cout << "Select LoadingBay" << endl << "LB" << lb1.GetCSID() << endl << "LB" << lb2.GetCSID() << endl;
			cin >> UserInput;
			switch (UserInput) {
			case 4:
				lb1.Arrive();
				cout << "Loading Bay Arrive Successful" << endl;
				break;
			case 5:
				lb2.Arrive();
				cout << "Loading Bay Arrive Successful" << endl;
				break;
			default:
				cout << "Invalid Input, Please try again" << endl;
			}
			break;
		case 2:
			cout << "Select LoadingBay" << endl << "LB" << lb1.GetCSID() << endl << "LB" << lb2.GetCSID() << endl;
			cin >> UserInput;
			switch (UserInput) {
			case 4:
				lb1.Leave();
				cout << "Loading Bay Leave Successful" << endl;
				break;
			case 5:
				lb2.Leave();
				cout << "Loading Bay Leave Successful" << endl;
				break;
			default:
				cout << "Invalid Input, Please try again" << endl;
			}
			break;
		case 3:
			cout << "Select a Truck" << endl << st1.GetTTYPE() << st1.GetTID() << endl << st2.GetTTYPE() << st2.GetTID() << endl << st3.GetTTYPE() << st3.GetTID() << endl << dt1.GetTTYPE() << dt1.GetTID() << endl << dt2.GetTTYPE() << dt2.GetTID() << endl << ct1.GetTTYPE() << ct1.GetTID() << endl;
			cin >> TruckSelect;
			if (TruckSelect < 1 || TruckSelect > 6) {
				TruckSelect = -1;
				cout << "Invalid Input, Please try again" << endl;
			}
			break;
		case 4:
			if (TruckSelect != -1) {
				cout << "Select Task" << endl << "1 - Pick Up Item" << endl << "2 - Put Down Item" << endl;
				cin >> TruckTask;
				cout << "Select Storage" << endl << "CS" << cs1.GetCSID() << endl << "CS" << cs2.GetCSID() << endl << "CS" << cs3.GetCSID() << endl << "CS" << cs3.GetCSID() << endl << "LB" << lb1.GetCSID() << endl << "LB" << lb2.GetCSID() << endl;
				cin >> UserInput;
				switch (UserInput) {
				case 1:
					StorageSelect = &cs1;
					break;
				case 2:
					StorageSelect = &cs2;
					break;
				case 3:
					StorageSelect = &cs3;
					break;
				case 4:
					StorageSelect = &lb1;
					break;
				case 5:
					StorageSelect = &lb2;
					break;
				default:
					cout << "Invalid Input Please Try Again" << endl;
					break;
				}
				if (StorageSelect != NULL) {
					StorageSelect->ListContents();
					cout << "Select Pallet Position" << endl;
					cin >> PalletPosition;
					if (PalletPosition >= 0 && PalletPosition < 10) {
						switch (TruckTask) {
						case 1:
							switch (TruckSelect) {
							case 1:
								if (st1.PickUpItem(PalletPosition, *StorageSelect) == true) {
									cout << "Pick Up Successful" << endl;
								}
								else {
									cout << "Pick Up Unsuccessful" << endl;
								}
								break;
							case 2:
								if (st2.PickUpItem(PalletPosition, *StorageSelect) == true) {
									cout << "Pick Up Successful" << endl;
								}
								else {
									cout << "Pick Up Unsuccessful" << endl;
								}
								break;
							case 3:
								if (st3.PickUpItem(PalletPosition, *StorageSelect) == true) {
									cout << "Pick Up Successful" << endl;
								}
								else {
									cout << "Pick Up Unsuccessful" << endl;
								}
								break;
							case 4:
								if (dt1.PickUpItem(PalletPosition, *StorageSelect) == true) {
									cout << "Pick Up Successful" << endl;
								}
								else {
									cout << "Pick Up Unsuccessful" << endl;
								}
								break;
							case 5:
								if (dt2.PickUpItem(PalletPosition, *StorageSelect) == true) {
									cout << "Pick Up Successful" << endl;
								}
								else {
									cout << "Pick Up Unsuccessful" << endl;
								}
								break;
							case 6:
								if (ct1.PickUpItem(PalletPosition, *StorageSelect) == true) {
									cout << "Pick Up Successful" << endl;
								}
								else {
									cout << "Pick Up Unsuccessful" << endl;
								}
								break;
							}
							break;
						case 2:
							switch (TruckSelect) {
							case 1:
								if (st1.PutDownItem(PalletPosition, *StorageSelect) == true) {
									cout << "Put Down Successful" << endl;
								}
								else {
									cout << "Put Down Unsuccessful" << endl;
								}
								break;
							case 2:
								if (st2.PutDownItem(PalletPosition, *StorageSelect) == true) {
									cout << "Put Down Successful" << endl;
								}
								else {
									cout << "Put Down Unsuccessful" << endl;
								}
								break;
							case 3:
								if (st3.PutDownItem(PalletPosition, *StorageSelect) == true) {
									cout << "Put Down Successful" << endl;
								}
								else {
									cout << "Put Down Unsuccessful" << endl;
								}
								break;
							case 4:
								if (dt1.PutDownItem(PalletPosition, *StorageSelect) == true) {
									cout << "Put Down Successful" << endl;
								}
								else {
									cout << "Put Down Unsuccessful" << endl;
								}
								break;
							case 5:
								if (dt2.PutDownItem(PalletPosition, *StorageSelect) == true) {
									cout << "Put Down Successful" << endl;
								}
								else {
									cout << "Put Down Unsuccessful" << endl;
								}
								break;
							case 6:
								if (ct1.PutDownItem(PalletPosition, *StorageSelect) == true) {
									cout << "Put Down Successful" << endl;
								}
								else {
									cout << "Put Down Unsuccessful" << endl;
								}
								break;
							}
							break;
						}
					}
					else {
						cout << "Incorrect Pallet Position Please, try again" << endl;
					}
					break;
				}
			}
			else {
				cout << "Please Select Truck First" << endl;
			}
			break;
		case 5:
			cout << "Select Storage" << endl << "CS" << cs1.GetCSID() << endl << "CS" << cs2.GetCSID() << endl << "CS" << cs3.GetCSID() << endl << "CS" << cs3.GetCSID() << endl << "LB" << lb1.GetCSID() << endl << "LB" << lb2.GetCSID() << endl;
			cin >> UserInput;
			switch (UserInput) {
			case 1:
				cs1.ListContents();
				break;
			case 2:
				cs2.ListContents();
				break;
			case 3:
				cs3.ListContents();
				break;
			case 4:
				lb1.ListContents();
				break;
			case 5:
				lb1.ListContents();
				break;
			default:
				cout << "Invalid Input Please Try Again" << endl;
				break;
			}
			break;

		}
	}
}
#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"
#include "cargostorage.h"
#include "doubletruck.h"
#include "loadingbay.h"
#include "simpletruck.h"
#include "comparatortruck.h"

using namespace std;

int main() {
	cout << "Test 1: Create pallet" << endl;	//1.Create a new Pallet (expect no output)
	Pallet p(0, 5);
	//Expected: No Errors
	cout << "Test 1.5: Weight of Empty pallet" << endl; //Test for comparing weights in comparator truck
	cout << p.GetCurrentWeight() << endl;
	//Expected: 0
	cout << "Test 2+3: Empty listing" << endl;	//2.New Pallet should have no items
	p.ListAllItems();					//3.Empty Pallet should display some feedback(e.g Output Pallet EMPTY)
	//Expected: Pallet EMPTY
	cout << "Test 4: Adding item" << endl;	//4.Add item to list(shown when calling ListAllItems())
	p.AddItem("Box of live scorpions");
	//Expected: No Errors
	cout << "Test 4cont: List item" << endl; //4. Continued to see what's on Pallet
	p.ListAllItems();
	//Expected: "Box of live scorpions" in Pallet
	cout << "Test 5: Adding more items" << endl; //5.Add another item(should not affect the other elements of Pallet
	p.AddItem("Box of dead scorpions");
	//Expected: No Errors
	cout << "Test 5cont: List Pallet" << endl;	//5.Continued to see all on Pallet
	p.ListAllItems();
	//Expected: "Box of live scorpions" / n "Box of dead scorpions" in Pallet
	cout << "Test 6: Removing item" << endl;	//6. Remove item from pallet(Should remove the most recent item)
	p.RemoveTopItem();
	//Expected: No Errors
	cout << "Test 7: List Pallet" << endl;	//7. To see what's on Pallet(Other Items should not be removed other than the first)
	p.ListAllItems();
	//Expected: "Box of live scorpions" in Pallet
	cout << "Test 8: Get Item info" << endl;	//8. To see what item is at the requested position
	cout << p.GetItemAtPosition(0) << endl;
	//Expected: "Box of live scorpions" retrieved
	cout << "Test 9+10: List Pallet" << endl;	//9+10. Using functions ListAllItems() and GetItemAtPosition() should not affect contents of list
	p.ListAllItems();
	//Expected: "Box of live scorpions" in Pallet
	cout << "Test E1: Get Item info out of range" << endl; //E1. Use GetItemAtPosition() to retrive item outside of current Pallet size(Should not crash)
	cout << p.GetItemAtPosition(100) << endl;
	//Expected: Print "Item does not exist - Incorrect Input"
	cout << "Test E2: Removing from empty list" << endl; //E2. Use RemoveTopItem in Empty list(Should not crash)
	for (int i = 0; i < 5; i++) {
		p.RemoveTopItem();
	}
	//Expected: Print "Cannot Remove. Pallet Empty" * 4
	p.ListAllItems();
	//Expected: Pallet EMPTY
	cout << "Test E3: Get Item info Negative" << endl; //E3. Get info of item in negative position(Should not be error)
	cout << p.GetItemAtPosition(-5) << endl;
	//Expected: Item does not exist - Incorrect Input
	//
	//
	cout << "Test 11--16: Add Items Multiple (looking at weights)" << endl; //11. Add Items with prevent overflow weight(Current weight must not be over maxWeight)
	for (int j = 0; j < 10; j++) {
		cout << p.AddItem("Box of crabs") << endl;				//12+13. Successful/Fail (Should return one of these options)
		cout << "Current:" << p.GetCurrentWeight() << endl;		//14+15. Adding items Should add to current weight by 1 and the weight should add up correctly
	}
	//Expected: 5 Successful inputs and Current reaches 5 max, 5 Fails
	cout << "Max:" << p.GetMaxWeight() << endl;					//16. GetMaxWeight (Should reflect value in constructor code)
	//Expected: 5
	cout << "Test E4: Pallet ID Correct" << endl;				//E4. If the Pallet ID is correct (for pallet p it should be 1)
	cout << "PalletID: " << p.GetPID() << endl;
	//Expected: 1
	cout << "Test E5: Clear The Pallet" << endl;				//E5: Remove all Pallet Items (Used for the CargoStorage and then gives pallet new id so that it doesn't have the same as in storage)
	p.ClearPallet();
	cout << "Pallet's New ID" << p.GetPID() << endl;
	//Expected: ID 2
	cout << "List Pallet Items:" << endl;
	p.ListAllItems();
	//Expected: Pallet EMPTY
	cout << "E6: New Pallets ID" << endl;						//E6. New Pallet's ID
	Pallet q(0, 5);
	cout << "NEW PalletID q: " << q.GetPID() << endl;
	cout << "PalletID p: " << p.GetPID() << endl;
	//Expected: New PalletID q: 3 \n PalletID p: 2
	//
	//PreparePallets for Tests in CargoStorage
	p.AddItem("Box of dead scorpions");
	p.AddItem("Box of live scorpions");
	//
	cout << "Test 17: Cargo Storage Test" << endl;
	CargoStorage c;
	//Expected: No Errors
	cout << "Test 18-20+23: Add Pallet to given Position" << endl;
	cout << c.AddPalletAtPosition(0, p) << endl;	//Note using the same pallet multiple times
	p.AddItem("Box of live scorpions");				//Failure to Add should not delete pallet items
	cout << c.AddPalletAtPosition(0,p) << endl;
	cout << c.AddPalletAtPosition(1, q) << endl;
	cout << c.AddPalletAtPosition(2, p) << endl;
	c.ListContents();
	//Expected: 1, 0, 1, 1
	//Expected: CS1 P0: 2 Box, CS1 P1: Pallet EMPTY, CS1 P2: 1 Box CS1 P3-9: EMPTY
	cout << "Test 21: Retrieve Pallet from given Position" << endl;
	Pallet n;
	n = c.RetrievePalletFromPosition(0);
	//Expected: No Errors
	cout << "Test 22+23: Retrieved Pallet leaves no duplicates" << endl;
	n.ListAllItems();
	c.ListContents();
	//Expected: Box of dead scorpions, Box of live scorpions
	//Expected: CS1 P0: EMPTY everything else remains
	cout << "Test E7: Show CS ID" << endl;
	cout << "CSID:" << c.GetCSID() << endl;
	//Expected: CSID: 1
	cout << "Test E8: Show CS maxStorage" << endl;
	cout << "CS Max:" << c.GetCSMS() << endl;
	//Expected: CS Max: 10
	cout << "Test E9: Create New CargoStorage" << endl;
	CargoStorage d;
	//Expected: No Errors
	cout << "Test E10: Show ID of New CS" << endl;
	cout << "CSID:" << d.GetCSID() << endl;
	//Expected: CSID: 2
	//
	cout << "Test S1: Create a Simple Truck" << endl;
	SimpleTruck s;
	//Expected: No Errors
	cout << "Test S2: Pick Up Item" << endl;
	cout << s.PickUpItem(1, c) << endl;
	//Expected: 1
	c.ListContents();
	//Expected: CS1 P1: EMPTY
	cout << "Test S3: Put Down Item" << endl;
	cout << s.PutDownItem(0, d) << endl;
	//Expected: 1
	d.ListContents();
	//Expected: CS2 P0: Pallet...
	cout << "Test S4: Pick Up EMPTY" << endl;
	cout << s.PickUpItem(0, c) << endl;
	//Expected: 0
	cout << "Test S5: Pick Up Item and Put down in filled slot" << endl;
	cout << s.PickUpItem(0, d) << endl;
	cout << s.PutDownItem(2, c) << endl;
	//Expected: 1, 0
	cout << "Test S6: Hold Item and Pick up another" << endl;
	cout << s.PickUpItem(2, c) << endl;
	//Expected: 0
	cout << "Test S7: PutDown in Non existent location" << endl;
	cout << s.PutDownItem(11, c) << endl;
	//Expected: 0
	//
	//Prepare for Double Truck & Loading Bay
	s.PutDownItem(0, d);
	//
	cout << "Test LB1: Create Loading Bay" << endl;
	LoadingBay l;
	//Expected: No Errors
	cout << "Test LB2: Use Arrive Function" << endl;
	l.Arrive();
	//Expected: No Errors
	cout << "Test LB3: Use List Contents Function" << endl;
	l.ListContents();
	//Expected: List all Slots as full of random Pallets
	cout << "Test LB4: Use Get ID Loading Bay" << endl;
	cout << "ID:" << l.GetCSID() << endl;
	//Expected: To follow CargoStorage ID's , ID = 3
	cout << "Test LB5: Use Arrive a Second Time" << endl;
	l.Arrive();
	//Expected: Loading Bay Full
	cout << "Test LB5: Retrieve Pallet from Loading Bay" << endl;
	Pallet r;
	r = l.RetrievePalletFromPosition(0);
	//Expected: No Errors
	cout << "Test LB5cont: Check Contents of both new pallet and Loading Bay" << endl;
	cout << "Pallet r:" << endl;
	r.ListAllItems();
	//Expected: Contains Items from position 0 in Loading Bay
	cout << "Loading Bay:" << endl;
	l.ListContents();
	//Expected: Position 0 has EMPTY
	cout << "Test LB6 : Leave from Loading Bay" << endl;
	l.Leave();
	//Expected No Errors
	l.ListContents();
	//Expected: All positions EMPTY
	//
	//Prepare for Double Truck Tests
	l.Arrive();
	//
	cout << "Test DT1: Creating a Double Truck" << endl;
	DoubleTruck dt;
	//Expected: No Errors
	cout << "Test DT2: Picking Up Two Items" << endl;
	cout << dt.PickUpItem(0, l) << endl;
	cout << dt.PickUpItem(1, l) << endl;
	//Expected: 1, 1
	l.ListContents();
	//Expected: Positions 0 and 1 are EMPTY
	cout << "Test DT3: Pick up More Items" << endl;
	cout << dt.PickUpItem(2, l) << endl;
	//Expected: 0
	l.ListContents();
	//Expected: Position 2 Not EMPTY
	cout << "Test DT4: Put Down Item from DoubleTruck" << endl;
	cout << dt.PutDownItem(7, d) << endl;
	cout << dt.PutDownItem(8, d) << endl;
	//Expected: 1, 1
	d.ListContents();
	//Expected: P7 and 8 Not EMPTY
	cout << "Test DT5: Put Down Empty Double Truck" << endl;
	cout << dt.PutDownItem(6, d) << endl;
	cout << dt.PutDownItem(5, d) << endl;
	//Expected: 0, 0
	cout << "Test DT6: Pick up from non existent position" << endl;
	cout << dt.PickUpItem(10, c) << endl;
	//Expected: 0
	//
	//Prepare for Comparator Truck
	l.Arrive();
	CargoStorage e;
	//
	cout << "Test CT1: Create Comparator Truck" << endl;
	ComparatorTruck ct;
	//Expected: No Errors
	cout << "Test CT2: PickUp 2 Items" << endl;
	cout << "Weight of Item1 to be Picked up: " << l.CargoStorageItems[0].GetCurrentWeight() <<endl; //Done here because CargoSotrageItems is Public
	l.CargoStorageItems[0].ListAllItems();
	cout << "Weight of Item2 to be Picked up: " << l.CargoStorageItems[1].GetCurrentWeight() << endl;
	l.CargoStorageItems[1].ListAllItems();
	cout << ct.PickUpItem(0, l) << endl;
	cout << ct.PickUpItem(1, l) << endl;
	//Expected: 1, 1
	cout << "Test CT3: Heaviest Item Dropped First" << endl;
	ct.PutDownItem(0, e);
	e.ListContents();
	//Expected: Heaviest is in first
	ct.PutDownItem(1, e);
	e.ListContents();
	//Expected: Final Item Dropped
	return 0;
}
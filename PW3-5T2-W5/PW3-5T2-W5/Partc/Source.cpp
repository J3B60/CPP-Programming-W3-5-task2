#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"

using namespace std;

int main() {
	std::cout << "Test 1: Create pallet" << endl;	//1.Create a new Pallet (expect no output)
	Pallet p;
	cout << "Test 2+3: Empty listing" << endl;	//2.New Pallet should have no items
	p.ListAllItems();						//3.Empty Pallet should display some feedback(e.g Output Pallet EMPTY)
	cout << "Test 4: Adding item" << endl;	//4.Add item to list(shown when calling ListAllItems()
	p.AddItem("Box of live scorpions");
	cout << "Test 4cont: List item" << endl; //4. Continued to see what's on Pallet
	p.ListAllItems();
	cout << "Test 5: Adding more items" << endl; //5.Add another item(should not affect the other elements of Pallet
	p.AddItem("Box of dead scorpions");
	cout << "Test 5cont: List Pallet" << endl;	//5.Continued to see what's on Pallet
	p.ListAllItems();
	cout << "Test 6: Removing item" << endl;	//6. Remove item from pallet(Should remove the most recent item)
	p.RemoveTopItem();
	cout << "Test 7: List Pallet" << endl;	//7. To see what's on Pallet(Other Items should not be removed other than the first)
	p.ListAllItems();
	cout << "Test 8: Get Item info" << endl;	//8. To see what item is at the requested position
	p.GetItemAtPosition(0);
	cout << "Test 9+10: List Pallet" << endl;	//9+10. Using functions ListAllItems() and GetItemAtPosition() should not affect contents of list
	p.ListAllItems();
	cout << "Test E1: Get Item info out of range" << endl; //E1. Use GetItemAtPosition() to retrive item outside of current Pallet size(Should not be error)
	p.GetItemAtPosition(100);
	cout << "Test E2: Removing from empty list" << endl; //E2. Use RemoveTopItem in Empty list(Should not be error)
	for (int i = 0; i < 100; i++) {
		p.RemoveTopItem();
	}

}
#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"

using namespace std;

int main() {
	std::cout << "Test 1: Create pallet" << endl;	//1.Create a new Pallet (expect no output)
	Pallet p(1, 5);
	p = Pallet(id, maxWeight);
	cout << "Test 2+3: Empty listing" << endl;	//2.New Pallet should have no items
	p.ListAllItems();						//3.Empty Pallet should display some feedback(e.g Output Pallet EMPTY)
	cout << "Test 4: Adding item" << endl;	//4.Add item to list(shown when calling ListAllItems())
	p.AddItem("Box of live scorpions");
	cout << "Test 4cont: List item" << endl; //4. Continued to see what's on Pallet
	p.ListAllItems();
	cout << "Test 5: Adding more items" << endl; //5.Add another item(should not affect the other elements of Pallet
	p.AddItem("Box of dead scorpions");
	cout << "Test 5cont: List Pallet" << endl;	//5.Continued to see all on Pallet
	p.ListAllItems();
	cout << "Test 6: Removing item" << endl;	//6. Remove item from pallet(Should remove the most recent item)
	p.RemoveTopItem();
	cout << "Test 7: List Pallet" << endl;	//7. To see what's on Pallet(Other Items should not be removed other than the first)
	p.ListAllItems();
	cout << "Test 8: Get Item info" << endl;	//8. To see what item is at the requested position
	cout << p.GetItemAtPosition(1) << endl;
	cout << "Test 9+10: List Pallet" << endl;	//9+10. Using functions ListAllItems() and GetItemAtPosition() should not affect contents of list
	p.ListAllItems();
	cout << "Test E1: Get Item info out of range" << endl; //E1. Use GetItemAtPosition() to retrive item outside of current Pallet size(Should not crash)
	cout << p.GetItemAtPosition(100) << endl;
	cout << "Test E2: Removing from empty list" << endl; //E2. Use RemoveTopItem in Empty list(Should not crash)
	for (int i = 0; i < 100; i++) {
		p.RemoveTopItem();
	}
	//
	cout << "Test E3: Get Item info Negative" << endl; //E3. Get info of item in negative position(Should not be error)
	cout << p.GetItemAtPosition(-5) << endl;
	//
	cout << "Test 11--16: Add Items Multiple (looking at weights)" << endl; //11. Add Items with prevent overflow weight(Current weight must not be over maxWeight)
	for (int j = 0; j < 10; j++) {
		cout << p.AddItem("Box of crabs") << endl;				//12+13. Successful/Fail (Should return one of these options)
		cout << "Current:" << p.GetCurrentWeight() << endl;		//14+15. Adding items Should add to current weight by 1 and the weight should add up correctly
	}
	cout << "Max:" << p.GetMaxWeight() << endl;					//16. GetMaxWeight (Should reflect value in constructor code)
	//
	cout << "Test 17: Cargo Storage Test" << endl;
	CargoStorage c(1, 10);
	cout << "Test 18-20: Add Pallet to given Position" << endl;
	cout << c.AddPalletAtPosition(0, p) << endl;	//Note using the same pallet multiple times
	cout << c.AddPalletAtPosition(0,p) << endl;
	cout << c.AddPalletAtPosition(1, p) << endl;
	cout << c.ListContents() << endl;
	cout << "Test 21: Retrieve Pallet from given Position" << endl;
	cout << c.RetrievePalletFromPosition(0, p) << endl;
}
	
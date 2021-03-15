#include <iostream>
#include <vector>
#include <string>
#include "pallet.h"

using namespace std;

int main() {
	std::cout << "Test 1: Create pallet" << endl;
	Pallet p;
	cout << "Test 2: Empty listing" << endl;
	p.ListAllItems();
	cout << "Test 3: Adding item" << endl;
	p.AddItem("Box of live scorpions");
	cout << "Test 4: List item" << endl;
	p.ListAllItems();

}
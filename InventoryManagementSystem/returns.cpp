#include "returns.h"
/*
Instantiation  of object and an initialise object data members, Barcode or InventoryName will act as a unique identifiers for the search
through the vector.  Derived class has additional construction parameter t, t wil be a string that prompts the user for a reason for the return
*/
Returns::Returns(string code, string iName, string iQuantity, string t)
	: Stock(code, iName, iQuantity), t(t)
{

};

//display returns list
void Returns::displayTotal(const vector <Returns> &a) {
	cout << "Items held in inventory" << endl;
	cout << setw(1) << "Inventory Name:" << setfill(' ') << setw(15) << "Barcode:" << setw(15) << "Quantity:" << endl;
	for (Returns const item : a) {
		cout << setw(15) << item.getInventoryName() << setfill(' ') << setw(15) << item.getBarcode() << setw(15) << item.getInvQty() << "\n" << endl;
		cout << "Reason for return:\n" << item.getRetDesc() << endl;
	}
}

//setter for string t
void Returns::setDesc(string v) {
	bool valiCode;
	do {
		if (regex_match(v, regex("^[A-Z a-z]+$")) == true && v.size() <= 240) {
			valiCode = true;
		}
		else {
			cout << "Invalid input, please enter text only" << endl;
			valiCode = false;
		}
	} while (valiCode == false);
	t = v;
}

//getter
string Returns::getRetDesc() const {
	return t;
}
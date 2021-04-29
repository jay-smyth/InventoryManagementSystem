#include "returns.h"
using namespace std;

/*
Program is built with the intention that an object of class Stock is instaniatated and object entities house the important information,
this way no more than one object is created at a time.
Derived Class Returns, uses a lot of the public member functions in class Stock to repeat the process, 
returns could be calculated and added back to their relevant position in their contained vector
*/
int main() {
	vector<class Stock> itemInfo;
	vector<class Returns> rItems;
	string code, invItem, invQty;
	string rCode, rName, rQty, rDesc;
	string newItemName, newCode, newItemQty;
	char options;
	bool prog; //boolean to repeat and exit main program
	//Instantiate stock object for passing to vector
	Stock Stock1(code, invItem, invQty);
	Returns retItems(rCode, rName, rQty, rDesc);

	cout << "Welcome to your inventory management system!\n" << endl;

	do {
		cout << "Please enter a number from the following options" << endl;

		cout << "To add a product: 1" << endl; 
		cout << "To remove a product : 2" << endl;
		cout << "To view complete product inventory : 3" << endl;
		cout << "To edit a product quantity: 4" << endl;
		cout << "View returns menu: 5" << endl;
		cout << "To exit the program : 6" << endl;
	
	
		cin >> options;
		cin.ignore();
		//test input character is within range
		if (options >= 49 || options <= 54) { // test char options within the ascii range between 1 and 5
			switch (options)
			{
				//add object and entities to vector 
			case '1':
				do {
					cout << "Please enter item name:" << endl;
					getline(cin, newItemName);				
				} while (Stock1.tItem(newItemName, itemInfo) == false);
				Stock1.setItemName(newItemName);

				do {
					cout << "Please enter barcode:" << endl;
					getline(cin, newCode);
				} while (Stock1.tCode(newCode, itemInfo) == false);
				Stock1.setBarcode(newCode);

				cout << "Please enter item quantity:" << endl;
				getline(cin, newItemQty);
				if(Stock1.tQty(newItemQty) == true)
				Stock1.setInvQty(newItemQty); //pass arguments for user input

				itemInfo.push_back(Stock1); //add object to vector range
				cout << "New product added, please select another option!\n" << endl;
				prog = true;
				break;

				//find and erase item from vector
			case '2': 
				if (!itemInfo.empty()) {
					cout << "To remove an item, please enter name or barcode to product\n" << endl;
					getline(cin, invItem);
					Stock1.removeItem(invItem, itemInfo); //pass vector to removeItem function for iteration and search for removal of Stock object and it's entities
				}
				else
				cout << "Inventory is currently empty\n" << endl;
				prog = true;
				break;

			//display total list  of input so far
			case '3': 
				if (!itemInfo.empty()) {
					cout << "View all products, please enter name or barcode to product\n" << endl;
					Stock1.displayTotal(itemInfo);//pass vector to displayTotal function for iteration and search for a printed list of all items held in vector
				}
				else
					cout << "Inventory is currently empty\n" << endl;
				prog = true;
				break;

			// adjust quantity levels of stock
			case '4':
				if (!itemInfo.empty()) {
				cout << "Add or remove quantity from item, please enter name or barcode to product\n" << endl;
				getline(cin, invItem);
				Stock1.adjustQty(invItem, itemInfo);//pass string arguments to find item to adjustQty, that will be pushed back to the itemInfo(vector)
				itemInfo.push_back(Stock1);
				}
				else
					cout << "Inventory is currently empty\n" << endl;
				prog = true;
				break;

			//derived class returns options
			case '5':
				bool rRrog; //boolean to repeat and exit main program
				char rOptions;
					do {
						cout << "To add a returns item enter: 1" << endl;
						cout << "To display items in the returns list enter: 2" << endl;
						cout << "To return to the main inventory options enter: 3" << endl;
						cin >> rOptions;
						cin.ignore();

						if (rOptions >= 49 || rOptions <= 51) { // test char options within the ascii range between 1 and 2
							switch (rOptions)
							{
							case '1':
								bool t;
								do {
									cout << "Please enter item name:" << endl;
									getline(cin, rName);
									if (regex_match(rName, regex("^[A-Z a-z]+$")) == true && rName.size() <= 15) {
										t = true;
									}
									else {
										cout << "Invalid input, No numbers allowed in inventory name and only 15 cahracters long" << endl;
										t = false;
									}
								} while (t == false);
								retItems.setItemName(rName);

								do {
									cout << "Please enter barcode:" << endl;
									getline(cin, rCode);
									if (regex_match(rCode, regex("^[0-9]+$")) == true && rCode.size() == 6) {
										t = true;
									}
									else {
										cout << "Invalid input, values must be number values and 6 characters long" << endl;
										t = false;
									}
								} while (t == false);
								retItems.setBarcode(rCode);
								
								cout << "Please enter item quantity:" << endl;
								getline(cin, rQty);
								if (retItems.tQty(rQty) == true)
									retItems.setInvQty(rQty); //pass arguments for user input

								cout << "Please enter return reason:" << endl;
								getline(cin, rDesc);
								retItems.setDesc(rDesc);

								rItems.push_back(retItems);
								rRrog = true;
								break;
							case'2':
								if (!rItems.empty()) 
									retItems.displayTotal(rItems);
								else
									cout << "No items current in list: returns. \nPlease select another option" << endl;
								rRrog = true;
								break;
							case '3':
								rRrog = false;
								break;
							}
						}
					} while (rRrog == true);
				prog = true;
				break;

			//exit program
			case '6': 
				cout << "Exit program" << endl;
				prog = false;
				break;
			}
		}
		else {
			cout << "Your input is not within the options list\n" << endl;
			prog = true;
			cin.sync();
		}
	} while (prog == true);

}
#include "inventory.h" //include inventory header file

using namespace std;

/*
Instantiation  of object and an initialise object data members, Barcode or InventoryName will act as a unique identifiers for the search
through the vector.
*/
Stock::Stock(string code, string iName, string iQuantity)
	: Barcode(code), InventoryName(iName), InventoryQty(iQuantity) 	//member initiailiser list
	{	
	
	};

/*
@param vector &a
vector a parameter is fed from the itemInfo vector by argument during function call in the driver program,
displayTotal displays the entire vector or "inventory"
*/
void Stock::displayTotal(const vector <Stock> &a) {
	cout << "Items held in inventory" << endl;
	cout << setw(1) << "Inventory Name:" << setfill(' ') << setw(15) << "Barcode:" << setw(15) << "Quantity:" << endl;
	for (Stock const item : a) {
		cout << setw(15) << item.getInventoryName() << setfill(' ') << setw(15) << item.getBarcode() << setw(15) << item.getInvQty() << "\n" << endl;
	}
}

/*
@param vector itemInfo from main
@param invItem takes input from main
removeItem pulls the vector itemInfo from main and iterates through the vector to find
searched item, if user input from main returns true remove intem at index[i], I had to use a range based loop as I needed to pass a variable type to
iterate through the objects and search their entities.
*/
void Stock::removeItem(string invItem, vector <Stock> &a) {
	string name, code;
	int i = 0;
	for (Stock const &item : a) {
		name = item.getInventoryName();
		code = getBarcode();
		if (name == invItem || code == invItem) {
			cout << "item found and removed: from index: " << i << "\n" << endl;
			a.erase(a.begin() + i);
			break;
		}
		else {
			++i;
		}
	}
}

/*
@param string, string, string take strings that are constructed for Stock object and prepare setting as new object
@param vector, vector that holds Stock objects for their entity data.
Parameter for vector is passed so that the stock item can be found, if found get information like InventoryName and Barcode; hold them in new variables.
Update InventoryQty by placing stock items qty in new variable, convert to int, add or subtract and replace.  Return values for push_back() to vector itemInfo,
essentially as a completely new stock item.
As I have built this application and this has been the last function created, I have noticed and can see a far more O.O.P based approach which would be far
cleaner but I have no more time :/
*/
string Stock::adjustQty(string adjustItem, vector<Stock>&a) {
	string name, code, q, newQty;
	char options;
	int x = 0;
	int i = 0;
	int y = 0;
	for (Stock const &item : a) {


		name = item.getInventoryName();
		code = item.getBarcode();
		q = item.getInvQty();
		int x = stoi(q);
		int* qty_ptr = &x;

		//test if item exists in inventory vector
		if (name == adjustItem || code == adjustItem) {
			cout << "item found:\n" << endl;
			cout << "To subtract from this item quantity enter: 1" << endl;
			cout << "To add to this item quantity enter: 2" << endl;
			cin >> options;
			cin.ignore();
			//test input character is within range
			if (options >= 49 || options <= 50) {
				switch (options) {
				case '1':
					cout << "subtract from item quantity" << endl;
					cin >> y;
					cin.ignore();					
					InventoryQty = *qty_ptr;
					*qty_ptr -= y;
					newQty = to_string(*qty_ptr);
					InventoryName = name;
					Barcode = code;
					InventoryQty = newQty;
					a.erase(a.begin() + i);
					return InventoryName, Barcode, InventoryQty;
				case '2':
					cout << "Add to item quantity" << endl;
					cin >> y;
					cin.ignore();
					*qty_ptr += y;
					newQty = to_string(*qty_ptr);
					InventoryName = name;
					Barcode = code;
					InventoryQty = newQty;
					a.erase(a.begin() + i);
					return InventoryName, Barcode, InventoryQty;
				}
			}

			break;
		}
		else {
			++i;
		}
	}
}
//setters

/*
@param string from driver program user input
setter
*/
void Stock::setItemName(string newItemName) {
	InventoryName = newItemName;
}

/*
@param string a user input from newItemName and passed as argument from setItemName
@param vector itemInfo from driver program and passed as argument from setItemName
Function call from setItemName for test of duplicate and input from user
*/
bool Stock::tItem(string a, const vector <Stock>&b) {
	bool test;
	string newItemName;

	if (regex_match(a, regex("^[A-Z a-z]+$")) == true && a.size() <= 15) // test for correct input
	{
		if (!b.empty())
		{
			for (Stock const &item : b) //iterate array
			{
				newItemName = item.getInventoryName(); // get Inventory names
				if (newItemName != a) // if user input doesn't equal stored name return true
				{
					test = true;
				}
				else
				{
					cout << "Error: Product of the same name exists" << endl;

					test = false;
					return test;
				}
			}
		}
		else
		{
			test = true;
			return test;
		}
	}
	else
	{
		cout << "Invalid input, No numbers allowed in inventory name and only 15 cahracters long" << endl;
		test = false;
		return test;
	}
}

/*
@param string newItemCode
setter
*/
void Stock::setBarcode(string c) {
		Barcode = c;
}

/*
@param string a user input from newItemCode and passed as argument from setBarcode
@param vector itemInfo from driver program and passed as argument from setBarcode
Function call from driver program to test duplicates and input from user
*/
bool Stock::tCode(string a, const vector <Stock>&b) {
	string newCode;
	bool test;

	if (regex_match(a, regex("^[0-9]+$")) == true && a.size() == 6) {
		if (!b.empty())
		{
			for (Stock const &item : b) //iterate array
			{
				newCode = item.getBarcode(); // get Inventory Barcode
				if (newCode != a) // if user input doesn't equal stored name return true
				{
					test = true;
				}
				else
				{
					cout << "Error: Barcode of the already exists" << endl;
					test = false;
					return test;
				}
			}
		}
		else
		{
			test = true;
			return test;
		}
	}
	else {
		cout << "Invalid input, values must be number values and 6 characters long" << endl;
		test = false;
		return test;
	}
}

/*
@param string newItemQty
setter
*/
void Stock::setInvQty(string q) {
	InventoryQty = q;
}

/*
@param string argument user input
test for valid amount and number values only
*/
bool Stock::tQty(string a) {
	bool valiQty;
	bool test;
	do {
		if (regex_match(a, regex("^[0-9]+$")) == true && a.size() <= 6) {
			valiQty = true;
			test = true;
			return test;
		}
		else {
			cout << "Invalid input, input number value with max of 999,999" << endl;
			valiQty = false;
		}
	} while (valiQty == false);
}

//getters

string Stock::getInventoryName() const{
	return InventoryName;
}
string Stock::getBarcode() const {
	return Barcode;
}
string Stock::getInvQty() const {
	return InventoryQty;
}

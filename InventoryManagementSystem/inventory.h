#include <iomanip> //include iomanip to pretty up output to console
#include <iostream> //include iostream for user input and output
#include <string> //include string library to access string types and test
#include <vector> //include vector library for iterator and searching of vectors
#include <regex> //include regex to test user input and validate


class Stock {
public:
	// Initialise object of class Stock with data members
	explicit Stock(std::string, std::string, std::string);

	//prototype to displayStckItem, search for stock item and display it's information
	//void displayStckItem(const std::vector<Stock>&);

	//function prototype to add items to the vector array invName (Setters)
	void setItemName(std::string);
	void setBarcode(std::string);
	void setInvQty(std::string);

	//setters control statements and test for duplicates
	bool tItem(std::string, const std::vector <Stock>&);
	bool tCode(std::string, const std::vector <Stock>&);
	bool tQty(std::string);

	//getters for the data members housed in the vector
	std::string getInventoryName() const;
	std::string getBarcode() const;
	std::string getInvQty() const;

	// function to remove stock item based on matched arguments
	void removeItem(std::string, std::vector<Stock>&);

	//prototype to adjust the quantity of items in stock
	std::string adjustQty(std::string, std::vector <Stock>&);

	// Prototype for member function DisplayStckItem, Displays entire stock
	void displayTotal(const std::vector <Stock> &);
	
private:
	std::string InventoryName; //data member of stock name
	std::string Barcode; // data member of stock barcodes
protected:
	std::string InventoryQty; //data member for stock levels
};
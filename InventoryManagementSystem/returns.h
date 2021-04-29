#include "inventory.h" //include inventory header file

using namespace std;

class Returns : public Stock {
public:
	explicit Returns(std::string, std::string, std::string, std::string);
	void setDesc(std::string);
	virtual void displayTotal(const vector <Returns> &a);
	string getRetDesc() const;
private:
	std::string t; //returned item reason/defect
};

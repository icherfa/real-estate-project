#include "HouseSale.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
HouseSale::HouseSale() : Property() {
    this->houseType = "";
    this->yearBuilt = 0;
    this->numRooms = 0;
    this->salePrice = 0;
}
HouseSale::HouseSale(const string& address, const Customer& owner, int agentID, const Date& listingDate, const string& houseType, int yearBuilt, int numRooms, int salePrice)
        : Property(address, owner, agentID, listingDate) {
    this->houseType = houseType; // Default house type
    this->yearBuilt = yearBuilt; // Default year built
    this->numRooms = numRooms; // Total rooms
    this->salePrice = salePrice; // Set sale price
}

// Set functions
HouseSale& HouseSale::setHouseType(const string& houseType) {
    this->houseType = houseType;
    return *this;
}
HouseSale& HouseSale::setYearBuilt(int yearBuilt) {
    this->yearBuilt = yearBuilt;
    return *this;
}
HouseSale& HouseSale::setNumRooms(int numRooms) {
    this->numRooms = numRooms;
    return *this;
}
HouseSale& HouseSale::setSalePrice(int salePrice) {
    this->salePrice = salePrice;
    return *this;
}

// Get functions
string HouseSale::getHouseType() const {
    return houseType;
}
int HouseSale::getYearBuilt() const {
    return yearBuilt;
}
int HouseSale::getNumRooms() const {
    return numRooms;
}
int HouseSale::getSalePrice() const {
    return salePrice; // Sale price of the house
}
int HouseSale::getSoldPrice() const {
    return Property::getSoldPrice();
}

// Print function
void HouseSale::printInformation() const {
    Property::printInformation(); // Base class print function
    cout << "House type: " << houseType << endl;
    cout << "Year built: " << yearBuilt << endl;
    cout << "Number of rooms: " << numRooms << endl;
    cout << "Sale price: " << salePrice << "$" << endl;
}

// Destructor
HouseSale::~HouseSale() {
    cout << "House object at " << Property::getAddress() << " destroyed." << endl;
}
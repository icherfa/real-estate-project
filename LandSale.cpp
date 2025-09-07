#include "LandSale.h"
#include <string>
#include <iostream>
using namespace std;

// Constructors
LandSale::LandSale() : Property() {
    this->area = 0.0;
    this->salePrice = 0;
}
LandSale::LandSale(const string& address, const Customer& owner, int agentID, const Date& listingDate, double area, int salePrice)
        : Property(address, owner, agentID, listingDate) {
    this->area = area; // Default area
    this->salePrice = salePrice; // Set land sale price
}

// Set functions
LandSale& LandSale::setArea(double area) {
    this->area = area;
    return *this;
}
LandSale& LandSale::setSalePrice(int salePrice) {
    this->salePrice = salePrice;
    return *this;
}

// Get functions
double LandSale::getArea() const {
    return area;
}
int LandSale::getSalePrice() const {
    return salePrice; // Cost, not what it was sold for
}
int LandSale::getSoldPrice() const {
    return Property::getSoldPrice();
}

// Print function
void LandSale::printInformation() const {
    Property::printInformation(); // Base class print function
    cout << "Area: " << area << " sq ft" << endl;
    cout << "Land sale price: " << salePrice << "$" << endl;
}

// Destructor
LandSale::~LandSale() {
    cout << "Land object at " << Property::getAddress() << " destroyed." << endl;
}
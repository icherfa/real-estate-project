#include "ApartmentSale.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
ApartmentSale::ApartmentSale() : Property() {
    this->condominumFee = 0.0;
    this->yearBuilt = 0;
    this->numRooms = 0;
    this->salePrice = 0;
}
ApartmentSale::ApartmentSale(const string& address, const Customer& owner, int agentID, const Date& listingDate, double condominumFee, int yearBuilt, int numRooms, int salePrice)
            : Property(address, owner, agentID, listingDate) {
    this->condominumFee = condominumFee;
    this->yearBuilt = yearBuilt;
    this->numRooms = numRooms;
    this->salePrice = salePrice;
}

// Set functions
ApartmentSale& ApartmentSale::setCondominumFee(double condominumFee) {
    this->condominumFee = condominumFee;
    return *this;
}
ApartmentSale& ApartmentSale::setYearBuilt(int yearBuilt) {
    this->yearBuilt = yearBuilt;
    return *this;
}
ApartmentSale& ApartmentSale::setNumRooms(int numRooms) {
    this->numRooms = numRooms;
    return *this;
}
ApartmentSale& ApartmentSale::setSalePrice(int salePrice) {
    this->salePrice = salePrice;
    return *this;
}

// Get functions
double ApartmentSale::getCondominumFee() const {
    return condominumFee;
}
int ApartmentSale::getYearBuilt() const {
    return yearBuilt;
}
int ApartmentSale::getNumRooms() const {
    return numRooms;
}
int ApartmentSale::getSalePrice() {
    return salePrice;
}
int ApartmentSale::getSoldPrice() const {
    return Property::getSoldPrice();
}

// Print function
void ApartmentSale::printInformation() const {
    Property::printInformation();
    cout << "Condominum fee: " << condominumFee << "$" << endl;
    cout << "Year built: " << yearBuilt << endl;
    cout << "Number of rooms: " << numRooms << endl;
    cout << "Sale price: " << salePrice << "$" << endl;
}

// Destructor
ApartmentSale::~ApartmentSale() {
    cout << "Apartment object at " << Property::getAddress() << " destroyed." << endl;
}
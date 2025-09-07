#include "Property.h"
#include "Customer.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

// Static counter
int Property::counter = 0;

// Constructors
Property::Property() {
    this->propertyID = 1000 + ++counter; // ID = preincremented counter  + 1000 (for format)
    this->address = "";
    this->owner = Customer();
    this->agentID = 0;
    this->listingDate = Date();
    this->soldDate = Date();
    this->soldPrice = 0;
}
Property::Property(const string& address, const Customer& owner, int agentID, const Date& listingDate) { // Property not sold yet, so soldDate/Price are 0.
    propertyID = 1000 + ++counter; // ID = preincremented counter  + 1000 (for format)
    this->address = address;
    this->owner = owner;
    this->agentID = agentID;
    this->listingDate = listingDate;
    this->soldDate = Date();
    this->soldPrice = 0;
}

// Set functions
Property& Property::setAddress(const string& address) {
    this->address = address;
    return *this;
}
Property& Property::setOwner(const Customer& owner) {
    this->owner = owner;
    return *this;
}
Property& Property::setAgentID(int agentID) {
    this->agentID = agentID;
    return *this;
}
Property& Property::setListingDate(const Date& listingDate) {
    this->listingDate = listingDate;
    return *this;
}
Property& Property::setSoldDate(const Date& soldDate) {
    this->soldDate = soldDate;
    return *this;
}
Property& Property::setSoldPrice(int soldPrice) {
    this->soldPrice = soldPrice;
    return *this;
}

// Get functions
int Property::getPropertyID() const {
    return propertyID;
}
string Property::getAddress() const {
    return address;
}
Customer Property::getOwner() const {
    return owner;
}
int Property::getAgentID() const {
    return agentID;
}
Date Property::getListingDate() const {
    return listingDate;
}
Date Property::getSoldDate() const {
    return soldDate;
}
int Property::getSoldPrice() const {
    return soldPrice;
}

// Print function
void Property::printInformation() const {
    cout << "-------Property Information-------" << endl;
    cout << "Property ID: " << propertyID << endl;
    cout << "Address: " << address << endl;
    cout << "Owner's name: " << owner.getName() << endl;
    cout << "Agent ID: " << agentID << endl;
    cout << "Listing Date: "; listingDate.printDate(); cout << endl;
    if (soldDate.getYear() != 0) { // CHecking to make sure properly has been sold
        cout << "Date sold: "; soldDate.printDate(); cout << endl;
        cout << "Price sold: " << soldPrice << "$ " << endl;
    } else {
        cout << "Property is for sale!" << endl;
    }
}

// Destructor
Property::~Property() {
    cout << "Property object at " << address << " destroyed." << endl;
}
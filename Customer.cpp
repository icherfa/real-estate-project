#include "Customer.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
Customer::Customer() : Person() { // Calls Person class' constructor
    SIN = "";
}
Customer::Customer(const string& name, const Date& dateOfBirth, const string& SIN) : Person::Person(name, dateOfBirth) {
    this->SIN = SIN;
}

// Set function
Customer& Customer::setSIN(const string& SIN) {
    this->SIN = SIN;
    return *this;
}

// Get function
string Customer::getSIN() const {
    return SIN;
}

// Print function
void Customer::printInformation() const {
    Person::printInformation(); // Prints Name and DOB
    cout << "Social Insurance Number: " << SIN << endl;
}

// Destructor
Customer::~Customer() {
    cout << "Customer object for " << Customer::getName() << " destroyed." << endl;
}
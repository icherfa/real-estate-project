#include "Person.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
Person::Person() {
    name = "";
    dateOfBirth.setDate(1, 1, 2000);
}
Person::Person(const string& name, const Date& dateOfBirth) {
    this->name = name;
    this-> dateOfBirth = dateOfBirth;
}

// Set functions
Person& Person::setInformation(const string& name, const Date& dateOfBirth) {
    this->name = name;
    this->dateOfBirth = dateOfBirth;
    return *this;
}
Person& Person::setName(const string& name) {
    this->name = name;
    return *this;
}
Person& Person::setDateOfBirth(const Date& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
    return *this;
}

// Get functions
string Person::getName() const {
    return name;
    
}
Date Person::getDateOfBirth() const {
    return dateOfBirth;
}

// Print function
void Person::printInformation() const {
    cout << "--------Information--------" << endl;
    cout << "Name: " << name << endl;
    cout << "Date of birth: "; dateOfBirth.printDate(); cout << endl;
}

// Destructor
Person::~Person() {
    cout << "Person object for " << Person::getName() << " destroyed." << endl;
}
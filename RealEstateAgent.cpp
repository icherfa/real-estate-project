#include "RealEstateAgent.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
RealEstateAgent::RealEstateAgent() : Person() {
    employeeID = 0;
    for (int i = 0; i < 20; i++)
        properties[i] = nullptr;
}
RealEstateAgent::RealEstateAgent(const std::string& name, const Date& dateOfBirth, int employeeID, const Date& employmentDate) : Person(name, dateOfBirth) {
    this->employeeID = employeeID;
    this->employmentDate = employmentDate;
    for (int i = 0; i < 20; i++) // Initialize pointer array to nullptr
        properties[i] = nullptr;
}

// Set functions
RealEstateAgent& RealEstateAgent::setID(int employeeID) {
    this->employeeID = employeeID;
    return *this;
}
RealEstateAgent& RealEstateAgent::setEmpDate(const Date& employmentDate) {
    this->employmentDate = employmentDate;
    return *this;
}

// Get functions
int RealEstateAgent::getID() const {
    return employeeID;
}
Date RealEstateAgent::getEmpDate() const {
    return employmentDate;
}
Property* RealEstateAgent::getProperty(const std::string& address) const {
    for (int i = 0; i < 20; i++) {
        if (properties[i] && properties[i]->getAddress() == address) {
            return properties[i]; // Return if found
        }
    }
    cout << "Property at " << address << " not found." << endl;
    return nullptr; // not found
}

// Add/remove properties
RealEstateAgent& RealEstateAgent::addProperty(Property* property) {
    for (int i = 0; i < 20; i++) { // Check is property is already present
        if (properties[i] == property) {
            cout << "Property at " << property->getAddress() << "already exists." << endl;
            return *this;
        }
    }
    for (int i = 0; i < 20; i++) { // Check if a slot is available
        if (!properties[i]) {
            properties[i] = property;
            cout << "Property at " << properties[i]->getAddress() << " added to " << RealEstateAgent::getName() << "'s properties." << endl;
            return *this;
        }
    }
    cout << "This agent already has the maximum amount of properties for sale." << endl;
    return *this;

}
RealEstateAgent& RealEstateAgent::removeProperty(Property* property) {
    for (int i = 0; i < 20; i++) { // Check if the property  is present in the array
        if(properties[i] == property){
            properties[i] = nullptr;
            cout << "Property at " << property->getAddress() << " removed from " << RealEstateAgent::getName() << "'s properties." << endl;
            return *this;
        }
    }
    cout << "Property not found." << endl;
    return *this;
}

// Print information
void RealEstateAgent::printInformation() const{
    Person::printInformation(); // Prints name and DOB
    cout << "Employee ID: " << employeeID << endl;
    cout << "Property list:" << endl; // Print ID & Address of each property
    int count = 0;
    for (int i = 0; i < 20; i++) {
        if (properties[i]) {
            count++;
            cout << "\t1. " << properties[i]->getAddress()<< ", ID:  " << properties[i]->getPropertyID() << endl;
        }
    }
    cout << "Total properties: " << count << endl;
}

// Destructor
RealEstateAgent::~RealEstateAgent() {
    cout << "RealEstateAgent object for " << RealEstateAgent::getName() << " destroyed." << endl;
}
                  
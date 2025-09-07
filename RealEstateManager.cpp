#include "RealEstateManager.h"
#include "Property.h"
#include "Date.h"
#include <iostream>
#include <string>
using namespace std;

// Constructors
RealEstateManager::RealEstateManager() {
    for (int i = 0; i < 30; i++)
        agents[i] = nullptr;
    for (int i = 0; i < 1000; i++)
        propertyForSale[i] = nullptr;
    for (int i = 0; i < 500; i++)
        propertySold[i] = nullptr;
}

// Add functions
RealEstateManager& RealEstateManager::addAgent(RealEstateAgent* agent) {
    for (int i = 0; i < 30; i++) {
        if (!agents[i]) {
            agents[i] = agent;
            return *this;
        }
    }
    // If no empty slot found
    cout << "Agent could not be added (maximum reached)." << endl;
    return *this;
}
RealEstateManager& RealEstateManager::addPropertyForSale(Property* property) {
    for (int i = 0; i < 30; i++) { 
        if (agents[i] && agents[i]->getID() ==  property->getAgentID()) { // Check agent is the same/exists
            for (int j = 0; j < 1000; j++) {
                if (!propertyForSale[j]) { // Check if slot is free
                    propertyForSale[j] = property;
                    agents[i]->addProperty(property);
                    return *this;
                } 
            }
        }
    }
    // If no empty slot found or if agent not found
    cout << "Property could not be added." << endl;
    return *this;
}

// Set property as sold
RealEstateManager& RealEstateManager::completeSale(Property* soldProperty, int priceSold, const Date& dateSold) {
    for (int i = 0; i < 1000; i++) {
        if (propertyForSale[i] && propertyForSale[i]->getAddress() == soldProperty->getAddress()) { // Found property
                for (int j = 0; j < 30; j++) {
                    if (agents[j] && agents[j]->getID() == soldProperty->getAgentID()) { // Found agent
                            // Move property to sold array and clear arrays
                            agents[j]->removeProperty(propertyForSale[i]); 
                            propertySold[i] = propertyForSale[i];
                            propertyForSale[i] = nullptr;
                            propertySold[i]->setSoldPrice(priceSold);
                            propertySold[i]->setSoldDate(dateSold);
                            propertySold[i]->setAgentID(0);
                            cout << "Property at " << propertySold[i]->getAddress() << " sold for " << priceSold << "$ on "; dateSold.printDate(); cout << "." << endl;
                            return *this;
                    }
                }
                // If agent not found
                cout << "Property's agent not found." << endl;
                return *this;
            }
    }
    // If property not found in forSale array
    cout << "Property not found." << endl;
    return *this;
}

// Search+Print function
void RealEstateManager::findProperty(int ID) const { // Print property info
    for (int i = 0; i < 1000; i++) { // Search in forSale array
        if (propertyForSale[i] && propertyForSale[i]->getPropertyID() == ID) {
            propertyForSale[i]->printInformation();
            return;
        }
    }
    for (int i = 0; i < 500; i++) { // Search in sold array}
        if (propertySold[i] && propertySold[i]->getPropertyID() == ID) {
            propertySold[i]->printInformation();
            return;
        }
    }
    // If property not found
    cout << "Property with ID " << ID << " not found." << endl;
}
void RealEstateManager::findAgent(int ID) const { // Print all property info of agent
    for (int i = 0; i < 30; i ++) {
        if (agents[i] && agents[i]->getID() == ID) {
            agents[i]->printInformation();
            return;
        }
    }
    cout << "Agent with ID " << ID << " not found." << endl;
}
// Print function
void RealEstateManager::printAll() const {
    int countA = 0;
    int countPFS = 0;
    int countPS = 0;
    cout << "-------Real Estate Manager Information-------" << endl;
    cout << "Agents:" << endl;
    for (int i = 0; i < 30; i++) {
        if (agents[i]) {
            cout << "\t" << ++countA << ". ";
            cout << agents[i]->getName() << ", ID: " << agents[i]->getID() << endl;
        }
    }
    if (countA == 0)
        cout << "\tNo agents registered." << endl;

    cout << "Properties for sale:" << endl;
    for (int i = 0; i < 1000; i++) {
        if (propertyForSale[i]) {
            cout << "\t" << ++countPFS << ". ";
            cout << propertyForSale[i]->getAddress() << ", ID: " << propertyForSale[i]->getPropertyID() << endl;
        }
    }
    if (countPFS == 0) 
        cout << "\tNo properties for sale." << endl;
        
    cout << "Properties Sold:" << endl;
    for (int i = 0; i < 500; i++) {
        if (propertySold[i]) {
            cout << "\t" << ++countPS << ". ";
            cout << propertySold[i]->getAddress() << ", ID: " << propertySold[i]->getPropertyID() << endl;
        }
    }
    if (countPS == 0) 
        cout << "\tNo properties sold." << endl;
}

// Destructor
RealEstateManager::~RealEstateManager() {
    for (int i = 0; i < 30; i++)
        agents[i] = nullptr;

    for (int i = 0; i < 1000; i++)
        propertyForSale[i] = nullptr;

    for (int i = 0; i < 500; i++)
        propertySold[i] = nullptr;

    cout << "RealEstateManager object destroyed." << endl;
}


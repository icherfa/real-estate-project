#ifndef REALESTATEMANAGER_H
#define REALESTATEMANAGER_H

#include "RealEstateAgent.h"
#include "Date.h"
#include "Property.h"

class RealEstateManager {

    public:

        // Constructors
        RealEstateManager();

        // Add functions
        RealEstateManager& addAgent(RealEstateAgent*);
        RealEstateManager& addPropertyForSale(Property*);

        // Set property as sold
        RealEstateManager& completeSale(Property*, int, const Date&);

        // Search+Print function
        void findProperty(int) const; // Print property info
        void findAgent(int) const; // Print all property info of agent

        // Print function
        void printAll() const; 

        // Destructor
        ~RealEstateManager();



    private:
        RealEstateAgent* agents[30];
        Property* propertyForSale[1000];
        Property* propertySold[500];

};


#endif
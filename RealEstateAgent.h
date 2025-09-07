#ifndef REALESTATEAGENT_H
#define REALESTATEAGENT_H

#include <string>
#include "Person.h"
#include "Property.h"

 class RealEstateAgent : public Person {

    public:
        // Constructors
        RealEstateAgent();
        RealEstateAgent(const std::string&, const Date&, int, const Date&);

        // Set functions
        RealEstateAgent& setID(int);
        RealEstateAgent& setEmpDate(const Date&);
        // RealEstateAgent& setProperties(Property*);
        
        // Get functions
        int getID() const;
        Date getEmpDate() const;
        Property* getProperty(const std::string&) const; // Get property from ID

        // Add or remove Properties
        RealEstateAgent& addProperty(Property*);
        RealEstateAgent& removeProperty(Property*);

        // Print function
        void printInformation() const override; // Overrides base class
    
        // Destructor
        ~RealEstateAgent();


    private:
        int employeeID;
        Date employmentDate;
        Property* properties[20];

 };

#endif
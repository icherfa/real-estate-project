#ifndef PROPERTY_H
#define PROPERTY_H

#include "Customer.h"
#include "Date.h"
#include <string>

class Property {

    private:
        static int counter;
        int propertyID;
        std::string address;
        Customer owner;
        int agentID;
        Date listingDate;
        Date soldDate;
        int soldPrice;

    public:
        // Constructors
        Property();
        Property(const std::string&, const Customer&, int, const Date&); // Property not sold yet, so soldDate/Price are 0.

        // Set functions
        Property& setAddress(const std::string&);
        Property& setOwner(const Customer&);
        Property& setAgentID(int);
        Property& setListingDate(const Date&);
        Property& setSoldDate(const Date&);
        Property& setSoldPrice(int);

        // Get functions
        int getPropertyID() const;
        std::string getAddress() const;
        Customer getOwner() const;
        int getAgentID() const;
        Date getListingDate() const;
        Date getSoldDate() const;
        virtual int getSoldPrice() const = 0; // Pure virtual function

        // Print function
        virtual void printInformation() const;

        // Destructor
        ~Property();

};

#endif
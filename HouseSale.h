#ifndef HOUSESALE_H
#define HOUSESALE_H

#include "Property.h"
#include <string>

class HouseSale : public Property {
    
    public:
        // Constructors
        HouseSale();
        HouseSale(const std::string&, const Customer&, int, const Date&, const std::string&, int, int, int);

        // Set functions
        HouseSale& setHouseType(const std::string&);
        HouseSale& setYearBuilt(int);
        HouseSale& setNumRooms(int);
        HouseSale& setSalePrice(int);

        // Get functions
        std::string getHouseType() const;
        int getYearBuilt() const;
        int getNumRooms() const;
        int getSalePrice() const; // Sale price of the house
        int getSoldPrice() const override; // Overrides function in Property

        // Print function
        void printInformation() const override; // Overrides Property::printInformation()

        // Destructor
        ~HouseSale();

    private:
        std::string houseType; // single or town
        int yearBuilt;
        int numRooms;
        int salePrice;
};

#endif
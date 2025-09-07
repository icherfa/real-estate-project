#ifndef LANDSALE_H
#define LANDSALE_H

#include "Property.h"

class LandSale : public Property {
    
    public:
        // Constructors
        LandSale();
        LandSale(const std::string&, const Customer&, int, const Date&, double, int);

        // Set functions
        LandSale& setArea(double);
        LandSale& setSalePrice(int);
        

        // Get functions
        double getArea() const;
        int getSalePrice() const;
        int getSoldPrice() const override; // Overrides function in Property

        // Print function
        void printInformation() const override; // Overrides Property::printInformation()

        // Destructor
        ~LandSale();

    private:
        double area;
        int salePrice; // Different than salePrice
};

#endif
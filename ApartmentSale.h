#ifndef APARTMENTSALE_H
#define APARTMENTSALE_H

#include "Property.h"
#include <string>

class ApartmentSale : public Property {

    public:
        // Constructors
        ApartmentSale();
        ApartmentSale(const std::string&, const Customer&, int, const Date&, double, int, int, int);

        // Set functions
        ApartmentSale& setCondominumFee(double);
        ApartmentSale& setYearBuilt(int);
        ApartmentSale& setNumRooms(int);
        ApartmentSale& setSalePrice(int);

        // Get functions
        double getCondominumFee() const;
        int getYearBuilt() const;
        int getNumRooms() const;
        int getSalePrice();
        int getSoldPrice() const override; // Overrides function in Property

        // Print function
        void printInformation() const override;

        // Destructor
        ~ApartmentSale();


    private:
        double condominumFee;
        int yearBuilt;
        int numRooms;
        int salePrice;
};

#endif
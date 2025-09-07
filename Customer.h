#ifndef Customer_H
#define Customer_H

#include <string>
#include "Person.h"
#include "Date.h"

class Customer : public Person {

    public:
        // Constructors
        Customer();
        Customer(const std::string&, const Date&, const std::string&);

        // Set functions (Reminder: setName and setDateOfBirth are in Person class!)
        Customer& setSIN(const std::string&);

        // Get functions
        std::string getSIN() const;

        // Print function
        void printInformation() const override; // Overrides base class

        // Destructor
        ~Customer();

    private:
        std::string SIN;
        


};

#endif
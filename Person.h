#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Date.h"

class Person {

    public:

        // Constructors
        Person();
        Person(const std::string&, const Date&);

        // Set functions
        Person& setInformation(const std::string&, const Date&);
        Person& setName(const std::string&);
        Person& setDateOfBirth(const Date&);

        // Get functions
        std::string getName() const;
        Date getDateOfBirth() const;

        // Print function
        virtual void printInformation() const; // Derived RealEstateAgent and Customer's print functions override

        // Destructor
        ~Person();

    protected: // So that they're inherited in class RealEstateAgent & Customer
        std::string name;
        Date dateOfBirth;

};

#endif
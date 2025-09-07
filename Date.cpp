#include "Date.h"
#include <iostream>
using namespace std;

// Constructor
Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

// Set functions
Date& Date::setDate(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    return *this;
}
Date& Date::setDay(int day) {
    this->day = day;
    return *this;
}
Date& Date::setMonth(int month) {
    this->month = month;    
    return *this;
}
Date& Date::setYear(int year) {
    this->year = year;
    return *this;
}

// Get functions
int Date::getDay() const {
    return day;
}
int Date::getMonth() const {
    return month;
}
int Date::getYear() const {
    return year;
}

// Print functions
void Date::printDate() const {
    cout << day << "/" << month << "/" << year;
}

// Destructor
Date::~Date() {
    // cout << "Date object destroyed." << endl;
    // No text to avoid large blocks of text each time a date is destroyed (e.g. during Person object creation)
}
#ifndef DATE_H
#define DATE_H

class Date {

    public:
    
        // Constructor
        Date();
        Date(int, int, int);

        // Set functions
        Date& setDate(int, int, int);
        Date& setDay(int);
        Date& setMonth(int);
        Date& setYear(int);

        // Get functions
        int getDay() const;
        int getMonth() const;
        int getYear() const;

        // Print function
        void printDate() const;

        // Destructor
        ~Date();

    private:

        int day, month, year;

};

#endif
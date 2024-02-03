#ifndef _DATE_H_

#define _DATE_H_

using namespace std;

#include <iostream>
#include <string>

class Date
{ 
    private:
        string name; //name of user    
        unsigned int d; // 1-31
        unsigned int m; // 1-12
        unsigned int y; // 1000-9999 (must be a 4-digit year)    
    public:
      Date();  // initialise members to valid default values, e.g. 1/1/2019
      Date(unsigned int day, unsigned int month, unsigned int year);
          // initialise using arguments
          // use default valid values and output a warning message
          //    if any argument is out of range
          //    or if day is 29, 30 or 31 and month has fewer days
      int getD() const;
          //gets day of birth of user
      int getM() const;
          //gets month of user;
      int getY() const;
          //gets year of user;
      bool isDefault() const;
          //checks if the default value is being used.
      string getName() const;
          //gets name of user
      void setName(string nameOfPersom);
          // sets name of user 
      int toDaysDifference(const Date & d) const;
          //converts the dates to days and find the differences
      bool isValid(unsigned int day, unsigned int month, unsigned int year) const;
          //return true if dat is valid, false if it isn't
      bool operator<(const Date& other) const;
          // return true if this date is before other, false otherwise
      bool operator>(const Date& other) const;
          // return true if this date is after other, false otherwise
      operator string() const;
          // return a string of the form "Day Month Year"
    friend ostream& operator<<(ostream& o, const Date& d);
        // output date in format dd/mm/yyyy, e.g. 02/11/2019
};

#endif
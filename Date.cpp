/*
    including header file
*/
#include "Date.h"
/*
    constructor to initialise default values
*/
Date::Date()
{
    d = 1;
    m = 1;
    y = 2021;
    name = "";
}
/*
    function that checks if the default value is being used to the main class can verify if the date was valid or not
*/
bool Date::isDefault() const
{
    if(name == "")
        return true;
    return false;
}
/*
    a function that checks if the date is valid, it also checks for leap years as well
*/
bool Date::isValid(unsigned int day, unsigned int month, unsigned int year) const
{
    if((year >= 1000 && year <= 2021) && 
        ((day > 0 && day <= 31 && (month == 1 || month == 3 || month == 5|| month == 7 || month == 8 || month == 10 || month == 12)) ||
        (day > 0 && day <= 30 && month == 4 || month == 6 || month == 9 || month == 11) ||
        (month == 2 && ((day > 0 && day <= 28) || day > 0 && day <= 29 &&  (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))))))
        return true;
    return false;
}
/*
    setter to set the name once the date has been verifed
*/
void Date::setName(string nameOfPerson)
{
    name = nameOfPerson;
}
/*
    getter to return the name
*/
string Date::getName() const
{
    return name;
}
/*
    getter to return the day
*/
int Date::getD() const
{
    return d;
}
/*
    getter to return the month
*/
int Date::getM() const
{
    return m;
}
/*
    getter to return the year
*/
int Date::getY() const
{
    return y;
}
/*
    constructor with 3 parameters
    if statement checks if the date is valid and if its not then it calls a constructor with no parameter to set it to default
*/
Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
    if(isValid(day,month,year))
    {
        d = day;
        m = month;
        y = year;
        name = "Default";
    }
    else 
        Date();
}
/*
    operator << overloading 
    for example if cout << className is being called it would print the date in a format leading with 0
*/
ostream& operator<<(ostream& o, const Date& d)
{   //if statement is used so 0 can be added if need.
    if(d.d < 10)
        o << "0" << d.d;
    else
        o << d.d;
    o << "/";
    if(d.m < 10)
        o << "0" << d.m;
    else
        o << d.m;
    o << "/" << d.y;
    return o;
}
/*
    converting the dates of the two class to days and returning the difference between them so it can help with converting to years months days 
*/
int Date::toDaysDifference(const Date & d) const
{    
    return (this->d + (this->m * 30) + (this->y * 365)) - (d.d + (d.m * 30) + (d.y * 365));
}
/*
    Operator string overloading
    gives the class the ability to return a string when it's called with string()
*/
Date::operator string() const
{
    const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; // Stores month to convert from int to string
    return ((d < 10) ? "0" + to_string(this->d) : to_string(this->d)) + " "+ months[this->m - 1] /* the month is recieved from the array depending on the month index */ + " " + to_string(this->y);
}
/*
    Operator < overloading
    compares the years, months and date. if the current obj is lesser then it returns true
*/
bool Date::operator<(const Date& other) const
{
    if(this->y < other.y ||
        (this->y == other.y && this->m < other.m) ||
        (this->y == other.y && this->m == other.m && this->d < other.d))
        return true;
    return false;
}
/*
    Operator > overloading
    compares the years, months and date. if the current obj is greater then it returns true
*/
bool Date::operator>(const Date& other) const
{
    if(this->y > other.y ||
        (this->y == other.y && this->m > other.m) ||
        (this->y == other.y && this->m == other.m && this->d > other.d))
        return true;
    return false;
}
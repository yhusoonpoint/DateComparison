//header file
#include "Date.h"
//checks if it's int or not
bool isDigit(const string & value)
{
    for (char const & i : value) 
    {
        if (std::isdigit(i) == 0) 
            return false;
    }
    return true;
}
/*
    converts the days difference gotten from the class and converting it to years months and days
    then it returns it in fomration of who is younger and the difference 
*/
string printComparism(Date * user1, Date * user2)
{
    int days, y, m, d;
    days = user2->toDaysDifference(*user1);
	y = days / 365;
	days = days % 365;
	m = days / 30;
	d = days % 30;
    return user2->getName() + " is " + to_string(y) + ((y <= 1) ? " year" : " years") + ", " + to_string(m) + ((m <= 1) ? " month" : " months") + ", and " + to_string(d) + ((d <= 1) ? " day" : " days") + " younger than " + user1->getName() + ".";
}
/*
    return the detals of the user as string
    function made to avoid duplication of code
*/
string printDetails(const string no, Date * user1)
{
    return "User " + no + ": " + user1->getName() + "\nBirthday: " + string(*user1) + "\n";
}
/*
    Function to display message and ask for string
    makes sure white space or empty string isn't passed, so the default function in Date wont be confused as default being true
    recursion keeps asking for input
*/
string & myGetLine(const string message, string & value, bool intEntry)
{
    char * temp = new char[256];
    cout << message;
    cin.getline(temp,256);
    value = temp;
    delete [] temp;
    if(value == "" || value == " " || (!intEntry && value.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") != string::npos)) // makes sure no special character is written
    {
        cout << "\nError, Please Try Again.\n";
        value = myGetLine( message,value, intEntry);
    }
    return value;
}
/*
    Function to display message and ask for int
    loop makes sure an int is being entered.
*/
int & intGetLine(const string message, int & value)
{ 
    string * tempValue = new string;
    *tempValue = myGetLine(message,*tempValue,true);
    while(!isDigit(*tempValue))
    {
        cout << "\nError, Please Try Again.\n";
        *tempValue =  myGetLine(message,*tempValue,true);
    }
    return value = stoi(*tempValue);    
}
/*
    this validates the date and creates a user if vallid
*/
Date * getUserDetails(string & name, string message, int & dd, int & mm, int & yyyy)
{
    Date * user;
    cout << message;
    name = myGetLine("Type in name: ", name,false);
    dd = intGetLine("Type in dd from dd/mm/yyyy: ", dd);
    mm = intGetLine("Type in mm from dd/mm/yyyy: ", mm);
    yyyy = intGetLine("Type in yyyy from dd/mm/yyyy: ", yyyy);
    if((user = new Date(dd,mm,yyyy))->isDefault()) // checks if the default value is being used so it returns NULL
    {
        cout << "Invalid details recieved!!!\n";
        delete user; // since the default user is create, deleting this will clear it from memory and we can assign it back to NULL
        return NULL;
    }
    else
    {
        user->setName(name); //sets the name if the date is valid
        return user; 
    }
}
/*
    main function
*/
int main()
{
    /*
        local variables
    */
    string * name = new string;
    int * dd = new int;
    int * mm = new int;
    int * yyyy = new int;
    Date * user1 = NULL;
    Date * user2 = NULL;
    // keeps looping until date is valid
    while(user1 == NULL)
        user1 = getUserDetails(*name,"Type in User 1 details.\n",*dd,*mm,*yyyy); 
    while(user2 == NULL)
        user2 = getUserDetails(*name,"Type in User 2 details.\n",*dd,*mm,*yyyy); 
    // prints out the details
    cout << printDetails("1",user1);
    cout << printDetails("2",user2);
    //comparing the two users and printing out the difference
    if(*user1 < *user2)
        cout << printComparism(user1,user2);
    else
        cout << printComparism(user2,user1);
    //deleting the pointers to free memory
    delete user1,  user2, name, dd, mm, yyyy;
    return 0;
}
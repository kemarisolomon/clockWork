/*
Name: Kemari Solomon
Section: 11
Assignment: Programming Assignment 2
Purpose: To ensure students can overload arithmetic, comparison, 
and special operators using both member and friend functions where appropiate
*/



#include "clock.h"
#include <iostream>
using namespace std;


int main()
{
char placeholder;
int days,hours,minutes,seconds;
    cout << "Clock One's Time: ";
    cin >> days>>placeholder>>hours>>placeholder>>minutes>>placeholder>>seconds;
    Clock clock1(days, hours, minutes, seconds);


char choice = 'Y';
int days2, hours2,minutes2,seconds2;
char option;
cout << "Clock Two's Time: "; 
cin >> days2 >>placeholder >>hours2 >>placeholder >>minutes2 >>placeholder>> seconds2;
Clock clock2(days2, hours2,minutes2,seconds2 );
while(choice == 'Y')
{
    cout << "What operation would you like to do? "<<endl;
    cout << "Addition: A" << endl;
    cout << "Subtraction: S "<< endl;
    cout << "Negation: N" << endl;
    cout << "Equal: E" << endl;
    cout << "Less than: L" << endl;
    cout << "Greater than: G"<< endl;
    cout << "Reset: R"<< endl;
    cin >>option;
    switch (option)
    {
    case 'A':
    case 'a':
    {
        Clock finalClock = clock1+clock2;
        cout << finalClock << endl;
        break;
    }
    case 'S':
    case 's':
    {
        Clock finalClock = clock1-clock2;
        cout << finalClock <<endl;
        break;
    }
    case 'N':
    case 'n':
    {
        Clock finalClock= -clock1;
        cout <<finalClock <<endl;
        break;
    }
    case 'E':
    case 'e':
    {
        bool equalTo = (clock1==clock2);
        cout << (equalTo ? "True": "False")<<endl;
        break;
    }
    case 'L':
    case 'l':
    {
        bool lessThan = (clock1 < clock2);
        cout <<(lessThan ? "True": "False")<<endl;
        break;
    }
    case 'G':
    case 'g':
    {
        bool greaterThan = (clock1 >clock2);
        cout <<(greaterThan ? "True": "False")<<endl;
        break;
    }
    case 'R':
    case 'r':
    {
        clock1.Reset();
        cout << clock1;
        break;
    }
    default:
        cout << "Please enter a valid choice."<<endl;
        break;
    }
    cout << "Would you like to continue?"<<endl;
    cin >> choice;
}

return 0;
}

/*
Name: Kemari Solomon
Section: 11
Assignment: Programming Assignment 2
Purpose: To ensure students can overload arithmetic, comparison, 
and special operators using both member and friend functions where appropiate
*/



#include <iostream>
using namespace std;



class Clock
{

    friend Clock operator+(Clock a, Clock b);
    friend Clock operator-(Clock a, Clock b);
    friend Clock operator-(Clock a) ;
    friend bool operator==(Clock a, Clock b);
    friend bool operator<(Clock a, Clock b);
    friend bool operator>(Clock a, Clock b);
    friend ostream& operator<<(ostream& i, Clock a);

    public:
    //default constructor
    Clock();
    //conversion constructor
    Clock(int days);
    //two-parameter constructor
    Clock(int minutes,int seconds);
    //four paramter constructor
    Clock(int seconds,int minutes,int hours,int days);

    //getters
    int getSeconds() const;
    int getMinutes() const;
    int getHours() const;
    int getDays() const;

    //setters
    void setSeconds(int seconds);
    void setMinutes(int minutes);
    void setHours(int hours);
    void setDays(int days);
    void Reset();


    private:
        //private data memebers of type int
        int seconds;
        int minutes;
        int hours;
        int days;
};


/*
Name: Kemari Solomon
Section: 11
Assignment: Programming Assignment 2
Purpose: To ensure students can overload arithmetic, comparison, 
and special operators using both member and friend functions where appropiate
*/



#include "clock.h"
using namespace std;

Clock::Clock()
{
    //sets all data members to 0
    seconds=00;
    minutes=00;
    hours=00;
    days=00;
}

Clock::Clock(int days)
{
    seconds=00;
    minutes=00;
    hours=00;
    this -> days=days;
}

Clock::Clock(int minutes,int seconds)
{
    this -> seconds=seconds;
    this -> minutes=minutes;
    hours=00;
    days=00;
}

Clock::Clock(int seconds, int minutes, int hours, int days)
{
    this -> seconds=seconds;
    this -> minutes=minutes;
    this -> hours=hours;
    this -> days=days;
}

//getter definitions
int Clock::getDays() const
{
    return days;
}
int Clock::getHours() const
{
    return hours;
}
int Clock::getMinutes() const
{
    return minutes;
}
int Clock::getSeconds() const
{
    return seconds;
}

//setter definitions
void Clock::setDays(int days)
{
    this -> days=days;
}
void Clock::setHours(int hours)
{
    this ->hours=hours;
}
void Clock::setMinutes(int minutes)
{
    this ->minutes=minutes;
}
void Clock::setSeconds(int seconds)
{
    this ->seconds=seconds;
}
void Clock::Reset()
{
    seconds=00;
    minutes=00;
    hours=00;
    days=00;
}

//addition operator
Clock operator+(Clock a, Clock b)
{
    Clock final;
    final.seconds = a.getSeconds() + b.getSeconds();
    final.minutes = a.getMinutes() + b.getMinutes();
    final.hours = a.getHours() + b.getHours();
    final.days =a.getDays() + b.getDays();

    if(final.seconds >= 60)
    {
        final.minutes += final.seconds/60;
        final.seconds %= 60;
    }
    if(final.minutes >= 60)
    {
        final.hours += final.minutes /60;
        final.minutes %= 60;
    }
    if(final.hours >= 24)
    {
        final.days +=final.hours/24;
        final.hours%=24;
    }

    return final;
}
//subtraction function
Clock operator-(Clock a, Clock b)
{
    Clock final;
    final.seconds = a.getSeconds() - b.getSeconds();
    final.minutes = a.getMinutes() - b.getMinutes();
    final.hours = a.getHours() - b.getHours();
    final.days =a.getDays() - b.getDays();

    if(final.seconds < 0)
    {
        final.minutes +=(final.seconds-59)/60;
        final.seconds = 60 + (final.seconds%60);
    }
    if(final.minutes < 0)
    {
        final.hours +=(final.minutes-59)/60;
        final.minutes= 60 + (final.minutes%60);
    }
    if(final.hours < 0)
    {
        final.days +=(final.hours-23)/24;
        final.hours = 24 + (final.hours%24);
    }
    return final;
}
//negation function
Clock operator-(Clock a)
{
    Clock final;
    final.seconds = -a.seconds;
    final.minutes = -a.minutes;
    final.hours = -a.hours;
    final.days = -a.days;
    return final;
}
//equality function
bool operator==(Clock a, Clock b)
{
    return(a.days == b.days && a.hours == b.hours && a.minutes == b.minutes && a.seconds == b.seconds);
}

//less than function
bool operator<(Clock a, Clock b)
{
    if(a.days != b.days)
    {
        return a.days < b.days;
    }
    if(a.hours != b.hours)
    {
        return a.hours < b.hours;
    }
    if(a.minutes != b.minutes)
    {
        return a.minutes < b.minutes;
    }
   return a.seconds < b.seconds;

}
//greater than function
bool operator>(Clock a, Clock b)
{
    if(a.days != b.days)
    {
        return a.days > b.days;
    }
    if(a.hours != b.hours)
    {
        return a.hours > b.hours;
    }
    if(a.minutes != b.minutes)
    {
        return a.minutes > b.minutes;
    }
   return a.seconds > b.seconds;

}

 ostream& operator<<(ostream& i, Clock a)
{
i <<"Time: " <<a.days << ":" <<a.hours << ":" <<a.minutes <<":" << a.seconds <<endl;
return i;
}

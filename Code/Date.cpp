#include "main.h"

date::date(int a, int b, int c)
{
    Day = a ;
    Month = b ;
    Year = c ;
}

date date::add_day(int a)
{
    Day += a ;

    switch (Month)
    {
    case(2):
        if(Year %4 == 0 && Day > 29)
        {
            Day -= 29 ;
            Month ++ ;
        }
        if(Year %4 != 0 && Day > 28)
        {
            Day -= 28 ;
            Month ++ ;
        }
    case(1,3,5,7,8,10,12):
        if(Day > 31)
        {
            Day -= 31 ;
            Month ++ ;
        }
    case(4,6,9,11):
        if(Day > 30)
        {
            Day -= 30 ;
            Month ++ ;
        }
    }
    if(Month > 12) 
    {
        Month -= 12 ;
        Year ++ ;
    }

    date ans(Day,Month,Year) ;

    return ans ;
}

bool date::operator> (date a)
{
    if(Year < a.Year) return false ;
    if(Month < a.Month) return false ;
    if(Day < a.Day) return false ;
    return true ;
}

bool date::operator== (date a)
{
    if(Year != a.Year) return false ;
    if(Month != a.Month) return false ;
    if(Day != a.Day) return false ;
    return true ;
}

bool date::operator< (date a)
{
    if(Year > a.Year) return false ;
    if(Month > a.Month) return false ;
    if(Day > a.Day) return false ;
    return true ;
}

date date::print_day()
{
    cout << Day << "/" << Month << "/" << Year ;
}
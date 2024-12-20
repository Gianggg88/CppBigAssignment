#ifndef DATE_H
#define DATE_H

class date
{
    public:
        int Day ;
        int Month ;
        int Year ;
        date() {0,0,0;}
        date(int a, int b, int c);
        date add_day(int a) ;
        date print_day() ;
        bool operator> (date a) ;
        bool operator== (date a) ;
        bool operator< (date a) ;
};

#endif
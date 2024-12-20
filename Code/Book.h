#ifndef BOOK_H
#define BOOK_H

#include "main.h"

class Book
{
    public:
        string title;
        string bookID;
        string author;
        string location;
        string genre;
        double price;
        bool status;
        date avaiable;
    public:
        Book(string a, string b, string c, double d, string e, string f, bool g, date i) ;
        Book() {} ;
        void print_book() ;
};

vector<Book> loadfilebook() ;
void savefilebook(vector<Book> &books) ;

void add_book(vector<Book> &books) ;
void edit_book(vector<Book> &books) ;

void findbookbygenre(vector<Book> &books) ;
Book* findbookbyID(vector<Book> &books, string bookID) ;

void print_borrowed_list(vector<Book> &books, User* user) ;
void delete_book(vector<Book> &books) ;

#endif
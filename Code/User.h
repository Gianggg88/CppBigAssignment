#ifndef USER_H
#define USER_H

#include "main.h"

using namespace std;

class User
{
    //<Username> <Password> <MSSV> <Email> <Phone_Number> <Role> <Borrow_List>
    public:
        string Username ;
        string Password ;
        string MSSV ;
        string Email ;
        string PhoneNumber ;
        string Role ;
        vector<string> Borrowed_List;
    public:
        User(string a, string b, string c, string d, string e, string f, vector<string> g) ;
        User() {} ;
};

User* Login(vector<User> &users);
void Signup(vector<User> &users) ;

vector<User> loadfileuser() ;
void savefileuser(vector<User> &users) ;

void print_user_list(vector<User> &users) ;
User* find_user_by_MSSV(vector<User> &users, string MSSV) ;
void edit_user(User* user) ;
void add_liberian(vector<User> &users) ;
void delete_user(vector<User> &users) ;
void delete_user_by_year(vector<User> &users) ;

#endif
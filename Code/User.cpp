#include "main.h"

User::User(string a, string b, string c, string d, string e, string f, vector<string> g)
{
    //<Username> <Password> <MSSV> <Email> <Phone_Number> <Role> <Borrow_List>
    Username = a ;
    Password = b ;
    MSSV = c ;
    Email = d ;
    PhoneNumber = e ;
    Role = f ;
    Borrowed_List = g ;
}

User* Login(vector<User> &users)
{
    while(true)
    {
        system("cls") ;
        cout << "=====================================Dang Nhap======================================" << endl << endl ;
        string Username ; cout << "Username: " ; cin >> Username ; cout << endl ;
        string Password ; cout << "Password: " ; cin >> Password ; cout << endl ;
        for(int i = 0; i < users.size(); i++) {
            if(users[i].Username == Username && users[i].Password == Password) {
                return &users[i];
            }
        }
        cout << "Sai mat khau / Tai khoan khong ton tai" << endl ;
        _sleep(1000) ;
    }
}

void Signup(vector<User> &users)
{
    cout << "======================================Dang Ki=======================================" << endl << endl ;
    string Username ; cout << "Username: " ; cin >> Username ; cout << endl ;
    for(auto user : users) 
    {
        if(user.Username == Username)
        {
            cout << "Username da ton tai." << endl ;
            _sleep(1000) ;
            Signup(users) ;
        }
    }
    string Password ; cout << "Password: " ; cin >> Password ; cout << endl ;
    string MSSV ; cout << "MSSV: " ; cin >> MSSV ; cout << endl ;
    for(auto user : users) 
    {
        if(user.MSSV == MSSV)
        {
            cout << "MSSV da ton tai." << endl ;
            _sleep(1000) ;
            Signup(users) ;
        }
    }
    string Email ; cout << "Email: " ; cin >> Email ; cout << endl ;
    string Phone_Number ; cout << "So dien thoai: " ; cin >> Phone_Number ; cout << endl ;
    vector<string> tmp ;
    cout << "Dang ki thanh cong !" ;
    User a(Username, Password, MSSV, Email, Phone_Number, "USER", tmp) ;
    users.push_back(a) ;
    _sleep(1000) ;
    system("cls") ;
    return ;
}

vector<User> loadfileuser()
{
    //<Username> <Password> <MSSV> <Email> <Phone_Number> <Role> <Borrow_List>
    vector<User> users ;
    ifstream file("Data/User.txt") ;
    string line ; 
    while(getline(file,line))
    {
        istringstream iss(line);
        //cout << line ;
        //_sleep(10000) ;
        string username, password, MSSV, email, phone_number, role ;
        vector<string> borrow_list ;
        iss >> quoted(username) >> password >> MSSV >> email >> phone_number >> role ;
        string tmp ;
        while (iss >> tmp) borrow_list.push_back(tmp) ;
        User a(username, password, MSSV, email, phone_number, role, borrow_list) ;
        users.push_back(a) ;
    }
    file.close();
    //print_user_list(users) ;
    //_sleep(10000) ;
    return users ;
}

void savefileuser(vector<User> &users)
{
    //<Username> <Password> <MSSV> <Email> <Phone_Number> <Role> <Borrow_List>
    ofstream file("Data/User.txt") ;
    for(auto user : users)
    {
        file << quoted(user.Username) << " " << user.Password << " " << user.MSSV << " " << user.Email << " " << user.PhoneNumber << " " << user.Role << " ";
        for(auto item : user.Borrowed_List) file << item << " " ;
        file << '\n' ;
    }
    cout << '\n' ;
    file.close();
}

void print_user_list(vector<User> &users)
{
    system("cls") ;
    cout << "===============================Danh sach nguoi dung=================================" << endl << endl ;
    for(auto user : users)
    {
        cout << user.MSSV << " " << user.Username << " " << user.Role << endl ;
    }
    cout << endl ;
}

void edit_user(User* user) {
    system("cls") ;
    cout << "===============================Cap nhat thong tin=================================" << endl << endl ;
    cout << "Mat khau (hien tai: " << user->Password << "): "; cin >> user->Password;
    cout << "Email (hien tai: " << user->Email << "): "; cin >> user->Email;
    cout << "So dien thoai (hien tai: " << user->PhoneNumber << "): "; cin >> user->PhoneNumber;
    cout << "Thong tin sinh vien da duoc cap nhat!" << endl;
    _sleep(1000) ;
    return;
}

void add_liberian(vector<User> &users)
{
    cout << "===================================Them Liberian====================================" << endl << endl ;
    string Username ; cout << "Username: " ; cin >> Username ; cout << endl ;
    for(auto user : users) 
    {
        if(user.Username == Username)
        {
            cout << "Username da ton tai." << endl ;
            _sleep(1000) ;
            Signup(users) ;
        }
    }
    string Password ; cout << "Password: " ; cin >> Password ; cout << endl ;
    string MSSV ; cout << "MSSV: " ; cin >> MSSV ; cout << endl ;
    for(auto user : users) 
    {
        if(user.MSSV == MSSV)
        {
            cout << "MSSV da ton tai." << endl ;
            _sleep(1000) ;
            Signup(users) ;
        }
    }
    string Email ; cout << "Email: " ; cin >> Email ; cout << endl ;
    string Phone_Number ; cout << "So dien thoai: " ; cin >> Phone_Number ; cout << endl ;
    vector<string> tmp ;
    cout << "Them thanh cong !" ;
    User a(Username, Password, MSSV, Email, Phone_Number, "LIBERIAN", tmp) ;
    users.push_back(a) ;
    _sleep(1000) ;
    system("cls") ;
    return ;
}

void delete_user(vector<User> &users)
{
    bool userfound = false;
    cout << "======================================Xoa sinh vien======================================" << endl << endl ;
    cout << "Nhap MSSV sinh vien can xoa: "; string MSSV; cin >> MSSV;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].MSSV == MSSV) {
            users.erase(users.begin() + i);
            cout << "Da xoa sinh vien co MSSV: " << MSSV << endl;
            userfound = true;
            break;
        }
    }
    if (!userfound) cout << "Khong tim thay sinh vien voi MSSV: " << MSSV << endl;
    _sleep(1000) ;
    return;
}

void delete_user_by_year(vector<User> &users)
{
    cout << "======================================Xoa sinh vien theo nam======================================" << endl << endl ;
    cout << "Nhap nam sinh vien can xoa: "; string year; cin >> year;
    for (int i = 0; i < users.size(); i++) {
        if (users[i].MSSV.substr(0, 4) == year) {
            users.erase(users.begin() + i);
            i--;
        }
    }
    cout << "Da xoa sinh vien sinh nam " << year << endl;
    _sleep(1000) ;
    return;
}

User* find_user_by_MSSV(vector<User> &users, string MSSV)
{
    for(int i=0;i<users.size();i++)
    {
        if(users[i].MSSV == MSSV) return &users[i] ;
    }
}
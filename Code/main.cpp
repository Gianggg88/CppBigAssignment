#include "main.h"

void use_as_user(vector<Book> &books, User* &user1, const date &today)
{
    while(true)
    {
        system("cls") ;
        cout << "=====================================Trang Chu======================================" << endl << endl ;
        cout << "1.Tim sach" << endl ; //
        cout << "2.Cac sach dang muon" << endl ; //
        cout << "3.Chinh sua thong tin" << endl ; //
        cout << "4.Thoat" << endl ; //
        cout << endl ;
        cout << "Option: " ; int option ; cin >> option ;

        switch (option)
        {
        case 1:
            findbookbygenre(books) ;
            cout << "Press any key to continue ..." ; _getch() ;
            break;

        case 2:
            print_borrowed_list(books,user1) ;
            cout << "Press any key to continue ..." ; _getch() ;
            break;
        
        case 3:
            edit_user(user1) ;
            break;

        case 4:
            return ;
        }
    }
}

void use_as_liberian(vector<Book> &books, vector<User> &users, date today)
{
    while(true)
    {
        system("cls") ;
        cout << "=====================================Trang Chu======================================" << endl << endl ;
        cout << "1. Them sach" << endl ; //
        cout << "2. Xoa sach" << endl ; //
        cout << "3. Sua thong tin sach" << endl ; //
        cout << "4. Dang ki muon sach" << endl ; //
        cout << "5. Tra sach" << endl ; //
        cout << "6. Cac sach den lich tra" << endl ; //
        cout << "7. Thoat" << endl ; //
        cout << endl ;
        cout << "Option: " ; int option ; cin >> option ;

        switch (option)
        {
        case 1:
            add_book(books) ;
            break;

        case 2:
            delete_book(books) ;
            break ;

        case 3:
            edit_book(books) ;
            break;

        case 4:
        {
            system("cls") ;
            cout << "=================================Dang ki muon sach==================================" << endl << endl ;
            cout << "MSSV nguoi muon: " ; string MSSV ; cin >> MSSV ;
            cout << "ID sach muon: " ; string bookID ; cin >> bookID ;
            cout << "Thoi gian muon (ngay): " ; int days ; cin >> days ;

            User* user = find_user_by_MSSV(users,MSSV) ;
            Book* book = findbookbyID(books,bookID) ;
            user->Borrowed_List.push_back(bookID) ;
            book->avaiable = today ;
            book->avaiable.add_day(days) ;
            book->status = 1 ;

            cout << "Dang ki thanh cong" << endl ;
            _sleep(1000) ;
            break ;
        }

        case 5:
        {
            system("cls") ;
            cout << "======================================Tra sach======================================" << endl << endl ;
            cout << "MSSV nguoi muon: " ; string MSSV ; cin >> MSSV ;
            cout << "ID sach muon: " ; string bookID ; cin >> bookID ;

            User* user = find_user_by_MSSV(users,MSSV) ;
            Book* book = findbookbyID(books,bookID) ;
            book->avaiable = today ;
            book->status = 0 ;
            for(int i=0;i<=user->Borrowed_List.size();i++)
            {
                if(user->Borrowed_List.at(i) == bookID) user->Borrowed_List.erase(user->Borrowed_List.begin() + i) ;
                break ;
            }

            cout << "Da cap nhat thong tin" << endl ;
            _sleep(1000) ;
            break ;
        }

        case 6:
        {
            system("cls") ;
            cout << "==================================Sach Den Han Tra==================================" << endl << endl ;
            for(auto user : users)
            { 
                for(string borrow : user.Borrowed_List)
                {
                    Book* book = findbookbyID(books,borrow) ;
                    if(book->status == 1 || book->avaiable < today || book->avaiable == today)
                    {
                        cout << "Sach " << book->title << " cua " << user.Username << " da den han tra" << endl ;
                        cout << "SDT: " << user.PhoneNumber << " ; Email: " << user.Email << endl ;
                        cout << endl ;
                    }
                }
            }
            cout << "Press any key to continue ..." ; _getch() ;
            break ;
        }

        case 7:
            return ;
        }
    }
}

void use_as_admin(vector<Book> &books, vector<User> &users, date today)
{
    while(true)
    {
        system("cls") ;
        cout << "=====================================Trang Chu======================================" << endl << endl ;
        cout << "1. In danh sach nguoi dung" << endl ; //
        cout << "2. Them tai khoan quan li" << endl ; //
        cout << "3. Xoa tai khoan" << endl ; //
        cout << "4. Xoa tai khoan theo nam" << endl ; //
        cout << "5. Thoat" << endl ; //
        cout << endl ;
        cout << "Option: " ; int option ; cin >> option ;

        switch (option)
        {
        case 1:
            print_user_list(users) ;
            cout << "Press any key to continue ..." ; _getch() ;
            break;
        
        case 2:
            add_liberian(users) ;
            break;

        case 3:
            delete_user(users) ;
            break;

        case 4:
            delete_user_by_year(users) ;
            break;

        case 5:
            return ;
        }
    }
}

int main() {

    vector<User> users = loadfileuser() ;
    vector<Book> books = loadfilebook() ;

    system("cls") ;
    cout << "=====================================Dang Nhap======================================" << endl << endl ;
    cout << "1.Dang nhap" << endl ;
    cout << "2.Tao tai khoan moi" << endl ;
    cout << endl ;
    cout << "Option: " ; int Option ; cin >> Option ;

    system("cls") ;
    User* _user_ ;
    if(Option == 1) _user_ = Login(users) ;
    if(Option == 2)
    {
        Signup(users) ;
        _user_ = Login(users) ;
    }
    cout << "Dang nhap thanh cong" << endl ;
    _sleep(1000) ;

    system("cls") ;
    cout << "=====================================Trang Chu======================================" << endl << endl ;
    cout << "Nhap ngay: " << endl ;
    cout << "Ngay: " ; int Day; cin >> Day ;
    cout << "Thang: " ; int Month ; cin >> Month ;
    cout << "Nam: " ; int Year ; cin >> Year ;
    date today(Day,Month,Year) ;

    system("cls") ;
    if(_user_->Role == "USER") use_as_user(books,_user_,today) ;
    if(_user_->Role == "LIBERIAN") use_as_liberian(books,users,today) ;
    if(_user_->Role == "ADMIN")
    {
        cout << "=====================================Log In As======================================" << endl << endl ;
        cout << "1. USER" << endl ;
        cout << "2. LIBERIAN" << endl ;
        cout << "3. ADMIN" << endl ;
        cout << endl ;
        cout << "Option: "; int option; cin >> option ;
        system("cls") ;
        if(option == 1) use_as_user(books,_user_,today) ;
        if(option == 2) use_as_liberian(books,users,today) ;
        if(option == 3) use_as_admin(books,users,today) ;
    }

    savefilebook(books) ;
    savefileuser(users) ;
    system("cls") ;
}
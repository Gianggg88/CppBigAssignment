#include "main.h"

void Book::print_book()
{
    cout << "Ten sach: " << title << endl ;
    cout << "Tac gia: " << author << endl ;
    cout << "The loai: " << genre << endl ;
    cout << "Gia tien: " << price << endl ;
    cout << "Ma sach: " << bookID << endl ;
    cout << "Vi tri: " << location << endl ;
    if(status)
    {
        cout << "Da bi muon" << endl ;
        cout << "Ngay tra sach: " ;
        avaiable.print_day() ;
    }
    else cout << "Con tren ke" << endl ;
    cout << endl ;
}

Book::Book(string a, string b, string c, double d, string e, string f, bool g, date i)
{
    title = a ;
    author = b ;
    genre = c ;
    price = d ;
    bookID = e ;
    location = f ;
    status = g ;
    avaiable = i ;
}

void add_book(vector<Book> &books)
{
    system("cls") ;
    cout << "=====================================Them Sach======================================" << endl << endl ;
    string title, author, genre, bookID, location ;
    double price ;
    cout << "Ten sach: "; cin >> title; cout << endl ;
    cout << "Tac gia: "; cin >> author; cout << endl ;
    cout << "The loai: "; cin >> genre; cout << endl ;
    cout << "Gia tien: "; cin >> price; cout << endl ;
    cout << "Ma sach: "; cin >> bookID; cout << endl ; 
    cout << "Vi tri: "; cin >> location; cout << endl ;
    date b(0,0,0) ;
    Book a(title, author, genre, price, bookID, location, 0, b) ;
    books.push_back(a) ;
    cout << "Them sach thanh cong. " ;
    _sleep(1000) ;
}

vector<Book> loadfilebook()
{
    vector<Book> books ;
    ifstream file("Data/Book.txt") ;
    string line ; 
    while(getline(file,line))
    {
        istringstream iss(line);
        string title, author, genre, bookID, location ;
        double price ;
        bool status ;
        date avaiable(0,0,0) ;
        iss >> quoted(title) >> quoted(author) >> quoted(genre) >> price >> bookID >> location >> status >> avaiable.Day >> avaiable.Month >> avaiable.Year ;
        Book a(title, author, genre, price, bookID, location, status, avaiable) ;
        books.push_back(a) ;
        //a.print_book() ;
    }
    //cout << "Press any key to continue ..." ; _getch() ;
    file.close();
    return books ;
}

void savefilebook(vector<Book> &books)
{
    ofstream file("Data/Book.txt") ;
    for(auto book : books)
    {
        file << quoted(book.title) << " " << quoted(book.author) << " " << quoted(book.genre) << " " << book.price << " " << book.bookID << " " << book.location << " " << book.status << " " << book.avaiable.Day << " " << book.avaiable.Month << " " << book.avaiable.Year << " " << '\n' ;
    }
    file.close();
}

void findbookbygenre(vector<Book> &books)
{
    system("cls") ;
    cout << "=====================================Tim Sach=======================================" << endl << endl ;
    cout << "Chon the loai sach : "; string genre ; cin.ignore() ; getline(cin,genre) ; cout << endl ;
    system("cls") ;
    cout << "=====================================Tim Sach=======================================" << endl << endl ;
    for(auto book : books)
    {
        if(book.genre == genre) book.print_book() ;
    }
    cout << endl ;
}

Book* findbookbyID(vector<Book> &books, string bookID)
{
    for(int i=0;i<books.size();i++)
    {
        if(books[i].bookID == bookID) return &books[i] ;
    }
}

void edit_book(vector<Book> &books) {
    system("cls") ;
    cout << "===============================Sua thong tin sach=================================" << endl << endl ;
    cout << "ID sach can sua: " ; string bookID ; cin >> bookID ; cout << endl ;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].bookID == bookID) {
            cout << "Chinh sua thong tin sach: " << books[i].title << endl;
            cout << "Ten sach (hien tai: " << books[i].title << "): "; cin >> books[i].title;
            cout << "Tac gia (hien tai: " << books[i].author << "): "; cin >> books[i].author;
            cout << "The loai (hien tai: " << books[i].genre << "): "; cin >> books[i].genre;
            cout << "Gia tien (hien tai: " << books[i].price << "): "; cin >> books[i].price;
            cout << "Vi tri (hien tai: " << books[i].location << "): "; cin >> books[i].location;
            cout << "Da bi muon (1: co, 0: khong) (hien tai: " << books[i].status << "): "; cin >> books[i].status;
            cout << "Thong tin sach da duoc cap nhat!" << endl;
            _sleep(1000) ;
            return;
        }
    }
    cout << "Khong tim thay sach voi ID: " << bookID << endl;
    _sleep(1000) ;
}

void print_borrowed_list(vector<Book> &books, User* user)
{
    system("cls") ;
    cout << "==================================Sach Dang Muon====================================" << endl << endl ;
    for(string item : user->Borrowed_List) {
        Book* book = findbookbyID(books,item) ;
        cout << book->title << " " ;
        book->avaiable.print_day() ;
        cout << endl ;
    }
}

void delete_book(vector<Book> &books)
{
    system("cls") ;
    cout << "=====================================Xoa sach=======================================" << endl << endl ;
    bool bookfound = false;
    string bookID ;
    cout << "Nhap ID sach can xoa: " ; cin >> bookID ;
    cout << endl ;

    // Duyệt qua danh sách các cuốn sách
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->bookID == bookID) { // Tìm cuốn sách có ID trùng khớp
            books.erase(it); // Xóa sách khỏi danh sách
            bookfound = true;
            cout << "Xoa sach thanh cong!" << endl;
            break; // Kết thúc sớm vì đã xóa
        }
    }

    // Nếu không tìm thấy sách
    if (!bookfound) {
        cout << "Khong tim thay sach voi ID: " << bookID << endl;
    }

    _sleep(1000) ;
    return ;
}


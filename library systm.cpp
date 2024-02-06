#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int menu()
{
    int choice = 0;
    while (choice == 0)
    {
        cout << "Please enter option from [1 - 10] : ";
        cin >> choice;
        if (choice > 10 || choice < 1)
        {
            choice = 0;
        }
    }
    return choice;
}

struct borrowed_books
{
    string booknamee;
    string usernamee;
};

struct book
{
    int id;
    string name;
    int quantity;
    int borowed;
    // string user_borrow[100];
};

struct user
{
    string us_names;
    int us_id;
    // string book_borrow[100];
};

struct library_system
{
    book books[100];
    user users[100];
    borrowed_books borrowed__books[100];
    int booknum = 0;
    int usernum = 0;
    // int bookborow=0;
    // int userborrow=0;
    int borrowednum = 0;
    /* library_system()
       {
           booknum =0;
           usernum=0;
       }*/
    void add_book()
    {

        cout << "please enter boook's id ,name and quantity : ";
        cin >> books[booknum].id >> books[booknum].name >> books[booknum].quantity;
        booknum += 1;
    }

    void add_user()
    {
        cout << "please enter user's id and name : ";
        cin >> users[usernum].us_id >> users[usernum].us_names;
        usernum += 1;
    }

    void search()
    {
        string bookname;
        cout << "please enter book's name : ";
        cin >> bookname;
        int n = bookname.length();
        int f = 1;
        int i, j;

        cout << "There are => ";
        for (i = 0; i < booknum; ++i)
        {
            string st = (books[i]).name;
            for (j = 0; j < n; ++j)
            {
                if (st[j] != bookname[j])
                {
                    f = 0;
                    break;
                }
            }
            if (f == 1)
                cout << st << "\n";
        }
        cout << "\n";
    }

    void print_library_by_id()
    {
        int i, j;
        cout << "library arranged by ids => \n";
        for (i = 1; i < booknum; ++i)
        {
            for (j = 0; j < (booknum - i); ++j)
            {
                if (books[j].id > books[j + 1].id)
                {
                    swap(books[j].id, books[j + 1].id);
                    swap(books[j].name, books[j + 1].name);
                    swap(books[j].quantity, books[j + 1].quantity);
                }
            }
        }
        for (i = 0; i < booknum; ++i)
        {
            cout << "book'id = " << books[i].id << "  books'name = " << books[i].name << "  books'quantity = " << books[i].quantity << " total borrowed books = " << books[i].borowed << "\n";
        }
    }

    void print_by_name()
    {
        int i, j, c;

        cout << "library arranged by names => \n";
        for (i = 1; i < booknum; ++i)
        {
            for (j = 0; j < (booknum - i); ++j)
            {

                string s1 = books[j].name;
                string s2 = books[j + 1].name;

                c = s1.compare(s2);
                if (c == 1)
                {
                    swap(books[j].id, books[j + 1].id);
                    swap(books[j].name, books[j + 1].name);
                    swap(books[j].quantity, books[j + 1].quantity);
                }
            }
        }
        for (i = 0; i < booknum; ++i)
        {
            cout << "book'id = " << books[i].id << "  books'name = " << books[i].name << "  books'quantity = " << books[i].quantity << " total borrowed books = " << books[i].borowed << "\n";
        }
    }

    void borrow_book()
    {
        string us;
        string bs;
        cout << "please enter username : ";
        cin >> us;
        cout << "please enter book's name : ";
        cin >> bs;
        int i, f = 0;
        for (i = 0; i < booknum; ++i)
        {
            if (bs == books[i].name)
            {
                if (books[i].quantity > 0)
                {
                    f = 1;
                    books[i].borowed += 1;
                    books[i].quantity -= 1;
                }
            }
        }
        if (f == 1)
        {
            for (i = 0; i < usernum; ++i)
            {
                if (us == users[i].us_names)
                {
                    borrowed__books[borrowednum].booknamee = bs;
                    borrowed__books[borrowednum].usernamee = us;
                    borrowednum += 1;
                }
            }
            cout << "book borrowed successfully \n";
        }
        else
            cout << "out of stock \n";
    }

    void return_book()
    {
        string bn, us;
        cout << "username : ";
        cin >> us;
        cout << "enter book name to return : ";
        cin >> bn;
        int i, f = 0;
        ;
        for (i = 0; i < booknum; ++i)
        {
            if (bn == books[i].name)
            {
                books[i].quantity += 1;
                books[i].borowed -= 1;
            }
        }
        for (i = 0; i < borrowednum; ++i)
        {
            if (borrowed__books[i].booknamee == bn && borrowed__books[i].usernamee == us)
            {
                f = i;
            }
        }
        for (i = f; i < borrowednum; ++i)
        {
            swap(borrowed__books[i].booknamee, borrowed__books[i + 1].booknamee);
            swap(borrowed__books[i].usernamee, borrowed__books[i + 1].usernamee);
            borrowednum -= 1;
        }
        cout << "book returned successfuly ";
    }

    void print_users()
    {
        int i, j;
        for (i = 0; i < usernum; ++i)
        {
            cout << "username : " << users[i].us_names << "  user's id : " << users[i].us_id << " borrowed books : ";
            for (j = 0; j < borrowednum; ++j)
            {
                if (borrowed__books[j].usernamee == users[i].us_names)
                    cout << borrowed__books[j].booknamee << " ";
            }
            cout << "\n";
        }
    }
    void who_borrowed()
    {
        string s;
        cout << "enter book's name : ";
        cin >> s;
        int i;
        cout << s << " is borrowed by => \n";
        for (i = 0; i < borrowednum; ++i)
        {
            if (s == borrowed__books[i].booknamee)
            {
                cout << borrowed__books[i].usernamee << "\n";
            }
        }
    }
};

int main()
{

    int t;
    library_system systemm;
    cout << "1) add book\n";
    cout << "2) search books by prefix\n";
    cout << "3) print who boorowed the book by name\n";
    cout << "4) print library by id\n";
    cout << "5) print library by name\n";
    cout << "6) add user\n";
    cout << "7) user borrow book\n";
    cout << "8) user return book\n";
    cout << "9) print users\n";
    cout << "10) exit\n";

    while (true)
    {
        cout << "\n";
        t = menu();

        if (t == 1)
        {
            systemm.add_book();
        }
        else if (t == 2)
        {
            systemm.search();
        }
        else if (t == 3)
        {
            systemm.who_borrowed();
        }
        else if (t == 4)
        {
            systemm.print_library_by_id();
        }
        else if (t == 5)
        {
            systemm.print_by_name();
        }
        else if (t == 6)
        {
            systemm.add_user();
        }
        else if (t == 7)
            systemm.borrow_book();
        else if (t == 8)
        {
            systemm.return_book();
        }
        else if (t == 9)
            systemm.print_users();
        else
            break;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class Date{
    int dd;
    int mm;
    int yy;

    void rectifyDate(){
        if(dd > 30){
            dd -= 30;
            m++;
        }
        if(mm > 12){
            mm -= 12;
            yy++;
        }
    }
public:
    Date(){
        dd = 1;
        mm = 1;
        yy = 2023;
    }

    void setDate(){
        cout<<"\nEnter Date: ";cin>>dd;
        cout<<"\nEnter Month: ";cin>>mm;
        cout<<"\nEnter year: ";cin>>yy;
    }

    void setDate(Date temp){
        dd = temp.dd + 15;
        mm = temp.mm;
        yy = temp.yy;
        rectifyDate();
    }
    
    void showDate(){
        cout<<dd<<" | "<<mm<<" | "<<yy<<endl;
    }
};

class Menu{
public:
    void mainMenu();
    void studentMenu();
    void bookMenu();
    void issueBook();
    void returnBook();
};

void Menu::mainMenu(){
    cout<<"\n\n -----------# Main Menu #----------- \n\n"<<endl;
    cout<<"1. Student Menu\n 2. Book Menu\n 3. Issue Book\n 4. Return Book \n 5. Exit\n";
}

void Menu::studentMenu(){
    cout<<"\n\n -----------# Student Menu #----------- \n\n";
    cout<<"1. New Entry\n 2. Modify Entry\n 3.Search Entry\n 4.Delete Entry\n 5. View Student Details\n 6. Back to Main Menu\n\n";
}

void Menu::bookMenu(){
    cout<<"\n\n -----------# Book Menu #----------- \n\n";
    cout<<"1. New Entry\n 2. Modify Entry\n 3.Search Entry\n 4.Delete Entry\n 5.View All Books\n 6. Back to Main Menu\n\n";
}

class BookData{
public:
    char title[50];
    char author[80];
    char publisher[80];
    int status;
    float price;
    int issuedRollNo;
    Date issueDate;
    Date returnDate;
    BookData(){
        status  = 0;
        issuedRollNo = -9999;
    }
};

class StudentData{
public:
    int rollNo;
    char name[50];
    char address[120];
    char branch[5];
    int status;
    char bookTtile[30];

    StudentData(){
        status = 0;
    }
};

class Book{
public:
    void inputDetails();
    void modifyDetails();
    void searchDetails();
    void deleteDetails();
    void viewAllBookDetail();

    void getData(){
        cout<<"Enter book title: ";cin>>book.title;
        cout<<"Enter author's: ";cin>>book.author;
        cout<<"Enter book publisher: ";cin>>book.publisher;
        cout<<"Enter book price: ";cin>>book.price;
    }
};

void Book::inputDetails(){
    fstream file;
    file.open("BookDetails.dat", ios::out || ios::binary | ios::app);

    if(!file){
        cout<<"Unable to open file"<<endl;
        return;
    }

    BookData book;
    book.getData();
}

void Book::modifyDetails(){
    fstream file;
    file.open("BookDetails.dat", ios::out || ios::binary | ios::app);

    if(!file){
        cout<<"Unable to open file"<<endl;
        return;
    }

    
}

int main(){

}
#include<bits/stdc++.h>
using namespace std;

class Books{
public:
    int id;
    char name[120];
    char author[120];
    bool available;

    void getBooks(){
        available = true;
        cout<<"\nEnter id: "; cin >> id;
        cout<<"\nEnter name: ";
        cin.ignore();
        cin.getline(name, 120);
        cout<<"\nEnter author Name: "; 
        cin.ignore();
        cin.getline(author, 120);
    }

    void display(){
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Author name: "<<author<<endl;
        cout<<"Availability: "<<(available) ? "Available" : "Not Available";cout<<endl;
    }
};

Books book;

void addBook() {
    book.getBooks();
    ofstream file("BookDetails.txt", ios::binary | ios::app);
    if (file) {
        file.write(reinterpret_cast<const char*>(this), sizeof(book));

        cout << "Book successfully added!" << endl;
    } else {
        cout << "File doesn't exist!" << endl;
    }
    file.close();
}

void updateBook(int uid){

}

void searchBook(int sid);
void deleteBook(int did);

void displayAllBook(){
    ifstream file("BookDetails.txt", ios::in|ios::binary);
    if(file){
        file.seekg(0);
        file.read(reinterpret_cast<const char*>(this), sizeof(book));
        book.display();
        cout<<endl;
    }
    else{
        cout<<"Book not found!!"<<endl;
    }
}

void takeBook();
void returnBook();

void MainMenu();

void adminMenu(){
    int choice;
    do{
        cout<<"1. Add Book"<<endl;
        cout<<"2. Update Book"<<endl;
        cout<<"3. Search Book"<<endl;
        cout<<"4. Delete Book"<<endl;
        cout<<"5. Display Books"<<endl;
        cout<<"Enter your choice: ";cin>>choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            int uid;
            cin>>uid;
            updateBook(uid);
            break;
        case 3:
            int sid;
            cin>>sid;
            searchBook(sid);
            break;
        case 4:
            int did;
            cin>>did;
            deleteBook(did);
            break;
        case 5:
            displayAllBook();
            break;
        
        default:
            cout<<"Invalid choice!!"<<endl;
        }
    }while(choice != 3);
}

void studentMenu(){
    int choice;
    do{
        cout<<"1. Take Book"<<endl;
        cout<<"2. Return Book"<<endl;
        cout<<"3. Return to Main menu"<<endl;
        cout<<"Enter your choice: ";cin>>choice;

        switch (choice)
        {
        case 1:
            takeBook();
            break;
        case 2:
            returnBook();
            break;
        case 3:
            MainMenu();
            break;
        
        default:
            cout<<"Invalid choice!!"<<endl;
        }
    }while(choice != 3);
}

void MainMenu(){
    int choice;
    do{
        cout<<"1. Student Menu"<<endl;
        cout<<"2. Admin Menu"<<endl;
        cout<<"Enter your choice: "; cin>>choice;

        switch (choice)
        {
        case 1:
            studentMenu();
            break;
        case 2:
            adminMenu();
            break;
        case 3:
            MainMenu();

        default:
            cout<<"Invalid Choice"<<endl;
        }
    }while(choice != 3);
}



int main(){
    MainMenu();
}
#include <iostream>
#include <vector>
using namespace std;

class Books
{
private:
    static int id;
    string name;
    string author;
    int copies;

public:
    Books(string name, string author, int copies)
    {
        id++;
        this->name = name;
        this->author = author;
        this->copies = copies;
    }

    void setCopies(int copy) { this->copies = copy; }
    void setName(string n) { this->name = n; }
    void setAuthor(string a) { this->author = a; }

    int getId() { return id; }
    int getCopies() { return copies; }
    string getName() { return name; }
    string getAuthor() { return author; }

    void borrowBook()
    {
        if (copies > 0)
            copies--;
    }

    void returnB()
    {
        copies++;
    }
};

int Books::id = 0;

class Student
{
private:
    static int id;
    string name;
    int roll;
    string department;
    vector<Books *> borrowedBooks;

public:
    Student(string name, int roll, string dept)
    {
        id++;
        this->name = name;
        this->roll = roll;
        this->department = dept;
    }

    int getId() { return id; }
    string getName() { return name; }
    int getRoll() { return roll; }
    string getDept() { return department; }

    void getBook(int bookid)
    {
        Books *book;
        cout << endl
             << "Enter the Book id you want to take -> ";
        if (book->getCopies() > 0 && book->getId() == bookid)
        {
            borrowedBooks.push_back(book);
            book->borrowBook();
            cout << book->getName() << " has been added ✅" << endl;
        }
        else
        {
            cout << "Invalid ID or There are no copies left 🙁" << endl;
        }
    }

    void returnBook(int bookId)
    {
        for (auto i = 0; i < borrowedBooks.size(); i++)
        {
            if (borrowedBooks[i]->getId() == bookId)
            {
                borrowedBooks[i]->returnB();
                cout << borrowedBooks[i]->getName() << " had been returned ✅" << endl;
                borrowedBooks.erase(borrowedBooks.begin() + i);
                return;
            }
        }
        cout << "Book not found in borrowed list." << endl;
    }

    void viewAllBooks()
    {
        if (borrowedBooks.empty())
        {
            cout << "You have no borrowed books." << endl;
            return;
        }
        cout << "Here are all the books you have taken -> " << endl;
        for (Books *it : borrowedBooks)
        {
            cout << "Id: " << it->getId() << endl;
            cout << "Name: " << it->getName() << endl;
            cout << endl;
        }
    }
};

int Student::id = 0;

class Admin
{
private:
    static int id;
    string name;
    vector<Student *> studentList;
    vector<Books *> allBooks;

public:
    Admin(string name)
    {
        id++;
        this->name = name;
    }

    void addStudent()
    {
        string name, dept;
        int roll;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter Dept: ";
        cin >> dept;
        cout << "Enter Roll: ";
        cin >> roll;

        Student *student = new Student(name, roll, dept);
        studentList.push_back(student);
        cout << "Student " << name << " has been added ✅" << endl;
    }

    void removeStudent(int stuid)
    {
        for (auto i = 0; i < studentList.size(); i++)
        {
            if (studentList[i]->getId() == stuid)
            {
                cout << studentList[i]->getName() << " has been removed ✅" << endl;
                studentList.erase(studentList.begin() + i);
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void addBook()
    {
        string name, author;
        int copies;
        cout << "Enter Book name: ";
        cin >> name;
        cout << "Enter Book author: ";
        cin >> author;
        cout << "Enter amount of copies: ";
        cin >> copies;

        Books *book = new Books(name, author, copies);
        allBooks.push_back(book);
        cout << "Book " << name << " has been added ✅" << endl;
    }

    void updateBook(int id)
    {
        for (Books *book : allBooks)
        {
            if (book->getId() == id)
            {
                string name, author;
                int copies;
                cout << "Enter Book name: ";
                cin >> name;
                cout << "Enter Book author: ";
                cin >> author;
                cout << "Enter amount of copies: ";
                cin >> copies;
                book->setName(name);
                book->setAuthor(author);
                book->setCopies(copies);
                cout << "Book updated successfully ✅" << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void removeBook(int id)
    {
        for (auto i = 0; i < allBooks.size(); i++)
        {
            if (allBooks[i]->getId() == id)
            {
                cout << allBooks[i]->getName() << " has been removed ✅" << endl;
                allBooks.erase(allBooks.begin() + i);
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void showStudents()
    {
        if (studentList.empty())
        {
            cout << "No students in the list." << endl;
            return;
        }
        for (Student *stu : studentList)
        {
            cout << "Name: " << stu->getName() << endl;
            cout << "Roll: " << stu->getRoll() << endl;
            cout << "Department: " << stu->getDept() << endl;
            cout << endl;
        }
    }

    vector<Books *> &getAllBooks() { return allBooks; }
};

int Admin::id = 0;

void studentMenu(Student &stu, vector<Books *> &allBooks)
{
    cout << "☘️ Welcome to Student Section ☘️" << endl;
    int choice;
    do
    {
        cout << "1. Get Book" << endl;
        cout << "2. Return Book" << endl;
        cout << "3. View Borrowed Books" << endl;
        cout << "4. Go back to Login" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            cout << "Enter Book Id: ";
            cin >> id;
            stu.getBook(id);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter Book Id: ";
            cin >> id;
            stu.returnBook(id);
            break;
        }
        case 3:
            stu.viewAllBooks();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice, Please try again!" << endl;
        }
    } while (choice != 4);
}

void adminMenu(Admin &ad)
{
    cout << "☘️ Welcome to Admin Section ☘️" << endl;
    int choice;
    do
    {
        cout << "1. Add Book" << endl;
        cout << "2. Update Book" << endl;
        cout << "3. Remove Book" << endl;
        cout << "4. Add Student" << endl;
        cout << "5. Remove Student" << endl;
        cout << "6. Show all Students" << endl;
        cout << "7. Go back to Login" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ad.addBook();
            break;
        case 2:
        {
            int id;
            cout << "Enter Book Id to update: ";
            cin >> id;
            ad.updateBook(id);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter Book Id to remove: ";
            cin >> id;
            ad.removeBook(id);
            break;
        }
        case 4:
            ad.addStudent();
            break;
        case 5:
        {
            int id;
            cout << "Enter Student Id to remove: ";
            cin >> id;
            ad.removeStudent(id);
            break;
        }
        case 6:
            ad.showStudents();
            break;
        case 7:
            return;
        default:
            cout << "Invalid choice, Please try again!" << endl;
        }
    } while (choice != 7);
}

void MainMenu()
{
    cout << "📚 Welcome to my library management system 📚" << endl;
    Admin ad("Admin");
    Student stu("Default", 0, "None");
    vector<Books *> allBooks;
    int choice;
    do
    {
        cout << "🔑 Login Section 🔑" << endl;
        cout << "1. Student Section 👨‍💻" << endl;
        cout << "2. Admin Section 👨‍💼" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentMenu(stu, ad.getAllBooks());
            break;
        case 2:
            adminMenu(ad);
            break;
        case 3:
            cout << "Exiting Good Bye.... 👋" << endl;
            return;
        default:
            cout << "Invalid Choice, Try again!!" << endl;
        }
    } while (choice != 3);
}

int main()
{
    MainMenu();
    return 0;
}
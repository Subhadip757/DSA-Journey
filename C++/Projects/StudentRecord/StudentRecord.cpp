#include<iostream>
#include<fstream>
#include<string>    

using namespace std;

class student{
public:
    int rollNo;
    string name;
    int marks;

    void getData(){
        cout<<"\nEnter roll no. : ";cin>>rollNo;
        cin.ignore();
        cout<<"\nEnter name: ";getline(cin, name);
        cout<<"\nEnter marks: ";cin>>marks;
    }

    void display(){
        cout<<"\nRoll  :--> "<<rollNo<<endl;
        cout<<"Name  :--> "<<name<<endl;
        cout<<"Marks :--> "<<marks<<endl<<endl;
    }
};

void addRecord(){
    ofstream file("StudentRecord.txt", ios::app);
    student stu;

    stu.getData();
    file << stu.rollNo << endl << stu.name << endl << stu.marks <<endl<<endl;  // Writing with newlines
    cout<<"\n\nRecord updated successfully\n\n";
    file.close();
}

void displayRecord() {
    ifstream file("StudentRecord.txt");  // Open the file for reading
    student stu;

    while (file >> stu.rollNo >> stu.name >> stu.marks) {  // Read the roll number
        file.ignore();  // Ignore the newline after marks

        stu.display();  // Display the student data
    }

    file.close();  // Close the file
}


void updateRecord(int roll){
    ifstream file("StudentRecord.txt");
    ofstream temp("temp.txt");

    student stu;
    bool found = false;

    while(file >> stu.rollNo){
        file.ignore();
        getline(file, stu.name);
        file >> stu.marks;
        file.ignore();

        if(stu.rollNo == roll){
            found = true;
            cout<<"Updating Record for roll no: "<<roll<<endl;
            stu.getData();
        }
        temp << stu.rollNo << endl << stu.name << endl << stu.marks << endl << endl;  // Writing with newlines
    }
    file.close();
    temp.close();

    remove("StudentRecord.txt");
    rename("temp.txt", "StudentRecord.txt");

    cout<<"\n\n # Record updated successfully #\n\n";

    if(!found){
        cout<<"Record not found\n";
    }
}

bool searchRecord(int roll) {
    ifstream file("StudentRecord.txt");  // Open the file for reading
    student stu;
    bool found = false;

    while (file >> stu.rollNo) {  // Read roll number
        file.ignore();  // Ignore the newline
        getline(file, stu.name);  // Read name
        file >> stu.marks;  // Read marks
        file.ignore();  // Ignore the newline

        if (stu.rollNo == roll) {  // If roll number matches
            cout << "\nRecord found:\n";
            stu.display();  // Display the student record
            found = true;
            break;
        }
    }

    file.close();  // Close the file

    if (!found) {
        cout << "\n\nRecord not found!!\n\n";
    }

    return found;
}


int main(){
    int choice, roll;
    while(true){
        cout<<"\nStudent Record\n 1.Add Record\n 2.Update Record\n 3.Display Record \n 4.Search Record \n 5. Exit \nEnter Your Choice :--> ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            cout<<"Enter roll number to update: ";cin>>roll;
            updateRecord(roll);
            break;
        case 3:
            displayRecord();
            break;
        case 4:
            cout<<"Enter roll number to search: ";cin>>roll;
            searchRecord(roll);
            break;
        case 5:
            exit(0);

        default:
            cout<<"Invalid choice!\n";
        }
    }
}

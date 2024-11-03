
#include<bits/stdc++.h>
using namespace std;

class Student {
private:
    int rollNo;
    char name[30];
    float marks;

public:
    // Constructor
    Student(int r = 0, const char* n = "Unnamed", float m = 0.0) {
        rollNo = r;
        strncpy(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0';
        marks = m;
    }

    // Function to display student details
    void display() const {
        cout << "Roll No: " << rollNo << "\nName: " << name << "\nMarks: " << marks << endl;
    }

    // Writing an object to a binary file
    void writeToFile(const char* filename) {
        ofstream outFile(filename, ios::binary | ios::app); // Open file in binary append mode
        if (outFile) {
            outFile.write(reinterpret_cast<const char*>(this), sizeof(Student));
            cout << "Object written to file successfully.\n";
        } else {
            cout << "Error opening file for writing.\n";
        }
        outFile.close();
    }

    // Reading an object from a binary file
    bool readFromFile(const char* filename, int pos) {
        ifstream inFile(filename, ios::binary); // Open file in binary read mode
        if (inFile) {
            // Move to the correct position for reading the object
            inFile.seekg(pos * sizeof(Student), ios::beg);
            inFile.read(reinterpret_cast<char*>(this), sizeof(Student));
            if (inFile.gcount() == sizeof(Student)) {
                return true; // Successful read
            } else {
                cout << "Error: Could not read object from file.\n";
            }
        } else {
            cout << "Error opening file for reading.\n";
        }
        inFile.close();
        return false;
    }
};

int main() {
    const char* filename = "students.dat";

    // Create a Student object and write it to file
    Student s1(1, "John Doe", 85.5);
    s1.writeToFile(filename);

    // Create another Student object and write it to file
    Student s2(2, "Jane Smith", 92.0);
    s2.writeToFile(filename);

    // Reading Student objects from the file
    Student s;
    cout << "\nReading first object from file:\n";
    if (s.readFromFile(filename, 0)) {
        s.display();
    }

    cout << "\nReading second object from file:\n";
    if (s.readFromFile(filename, 1)) {
        s.display();
    }

    return 0;
}

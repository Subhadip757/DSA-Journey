#include <iostream>
#include <cstring>

using namespace std;

class Students{
    private:
        string studentName;
        int studentRoll;
        int studentAge;

    public:
        string getStudentName(){
            return studentName;
        }
        void setStudentName(string studentName){
            this-> studentName = studentName;
        }

        int getStudentRoll(){
            return studentRoll;
        }

        void setStudentRoll(int studentRoll){
            this->studentRoll = studentRoll;
        }

        int getStudentAge(){
            return studentAge;
        }

        void setStudentAge(int studentAge){
            this->studentAge = studentAge;
        }

};

int main(){
    Students obj;

    obj.setStudentName("Subhadip");
    obj.setStudentRoll(71);
    obj.setStudentAge(21);

    cout<<"Name: "<<obj.getStudentName()<<", ";
    cout<<"Roll: "<<obj.getStudentRoll()<<", ";
    cout<<"Age: "<<obj.getStudentAge()<<endl;
}
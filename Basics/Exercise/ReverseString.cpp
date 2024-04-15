#include <iostream>

using namespace std;

void reverse(char name[], int n){
    int s = 0;
    int e = n - 1;
    while(s < e){
        swap(name[s], name[e]); // Corrected swapping operation
        s++; // Increment start index
        e--; // Decrement end index
    }
}

int getLength(char name[]){
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(){
    char name[20];
    cout << "Enter your name: ";
    cin >> name; // Read input into the name array
    int len = getLength(name);
    reverse(name, len); // Reverse the name
    cout << "Reversed Name -> " << name << endl; // Print the reversed name
    return 0;
}

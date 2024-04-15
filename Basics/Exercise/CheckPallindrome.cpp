#include <iostream>

using namespace std;

int toLowerCase(char ch){
    if(ch >= 'a' && ch <= 'z')
        return ch;
    else{
        char temp = ch - 'A'+'a';
        return temp;
    }
}

int checkPallindrome(char a[], int n){
    int s=0;
    int e = n-1;
    while(s<=e){
        if(toLowerCase(a[s]) != toLowerCase(a[e])){
            return 0;
        }else{
            s++;
            e--;
        }
    }
    return 1;
}

int getLength(char name[]){
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}

int main(){
    char a[20];
    cout<<"Enter a string: ";
    cin>>a;
    cout<<endl;
    int len = getLength(a);
    cout<<"Pallindrome or Not: "<<checkPallindrome(a,len)<<endl;

    cout<<"Character is: "<<toLowerCase('b')<<endl;
    cout<<"Character is: "<<toLowerCase('C')<<endl;
}
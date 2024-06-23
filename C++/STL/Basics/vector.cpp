#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;

    vector<int> a(5,1);
    for(int i:a){
        cout<<i<<" ";
    }

    cout<<endl<<"Size: "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Size: "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Size: "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;

    cout<<"Element at 2nd Index: "<<v.at(2)<<endl;

    cout<<"front: "<<v.front()<<endl;
    cout<<"back: "<<v.back()<<endl;

    cout<<"Before pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;

    v.pop_back();

    cout<<"After pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }

    cout<<endl<<"Before clear size: "<<v.size()<<endl;

    v.clear();
    cout<<"After clear size: "<<v.size()<<endl;
}
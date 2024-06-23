#include <iostream>
using namespace std;

int binarySearch(int n){
        long start = 0;
        long end = n;
        long mid = start +(end - start)/2;
        long ans = -1;

        while(start <= end){
            long square = mid*mid;
            if(square == n){
                return mid;
            }
            if(square < n){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
            mid = start +(end - start)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++){
        factor = factor / 10;

        for(double j=0; j*j<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    int tempSol = binarySearch(n);
    cout<< "Answer is: "<< morePrecision(n,3,tempSol)<<endl;

    return 0;
}
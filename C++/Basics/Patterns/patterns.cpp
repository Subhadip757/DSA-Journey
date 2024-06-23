#include<iostream>
using namespace std;

int main(){

    // Answer:
    // 1234
    // 1234
    // 1234

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j <= n){
            cout<<n-j+1;
            j++;
        }
        cout<<endl;
        i++;
    }*/

// --------------------------------------------------------------------//

    // Answer: 
    // 123
    // 456
    // 789

    /*int n;
    cin>>n;

    int i = 1;
    int count = 1;
    while(i<=n){
        int j = 1;
        while(j <= n){
            cout<<count<< " ";
            count = count + 1;
            j++;
        }
        cout<<endl;
        i++;
    }*/

//--------------------------------------------------------------------//

    // Answer:
    // *
    // **
    // ***
    // ****

   /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j <= i){
            cout<<'*';
            j++;
        }
        cout<<endl;
        i++;
    }*/

//----------------------------------------------------------------------------//

    // Answer:
    // 1
    // 22
    // 333
    // 4444

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }*/

//--------------------------------------------------------------------//

    // Answer:
    // 1
    // 23
    // 456
    // 78910

    /*int n;
    cin>>n;
    int i = 1;
    int count = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<count<<" ";
            count = count + 1;
            j++;
        }
        cout<<endl;
        i++;
    }*/

//-------------------------------------------------------------------//

    // Answer:
    // 1
    // 23
    // 345
    // 4567

    /*int n;
    cout<<"Enter the number of lines: ";
    cin>>n;
    int row = 1;
    while(row<=n){
        int col = 1;
        while(col <= row){
            cout<<row + col - 1;
            col++;
        }
        cout<<endl;
        row++;
    };*/
    

    // Answer:
    // 1
    // 21
    // 321
    // 4321

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j <= i){
            cout<<i-j+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // AAA
    // BBB
    // CCC

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            char ch = 'A'+i-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // ABC
    // ABC
    // ABC

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=n){
            char ch = 'A'+j-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // ABC
    // DEF
    // GHI

    /*int n;
    cin>>n;
    int i = 1;
    char alp = 'A';
    while(i<=n){
        int j = 1;
        while(j<=n){
            cout<<alp;
            alp++;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // ABC
    // BCD
    // CDE

    /*int n;
    cin>>n;
    int i = 1;
    while (i <= n) {
        int j = 1;
        while (j <= n) {
            char alp = 'A' + i + j -2;
            cout << alp;
            j++;
        }
        cout << endl;
        i++;
    }*/


    // Answer:
    // A
    // BB
    // CCC

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            char ch = ('A' + i - 1);
            cout<<ch;
            j++;
        } 
        cout<<endl;
        i++;
    }*/

    // Answer:
    // A
    // BC
    // DEF
    // GHIJ

    /*int n;
    cin>>n;
    char ch = 'A';
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            cout<<ch;
            ch++;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // A
    // BC
    // CDE
    // DEFG

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int j = 1;
        while(j<=i){
            char ch = 'A'+i+j-2;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // D
    // CD
    // BCD
    // ABCD

    /*int n;
    cin>>n;
    int i =1;
    while(i<=n){
        int j =1;
        char ch = 'A'+n -i;
        while(j<=i){
            cout<<ch;
            ch++;
            j++;
        }
        cout<<endl;
        i++;
    }*/


    // Answer:
    //    *
    //   **
    //  ***
    // ****

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int space = n - i;
        while(space){
            cout<<" ";
            space--;
        }
        int j = 1;
        while(j<=i){
            cout<<'*';
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // ****
    // ***
    // **
    // *

    /*int n;
    cin>>n;
    int i = 0;
    while(i<n){
        int star = n - i;
        while(star>0){
            cout<<'*';
            star--;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // 1111
    //  222
    //   33
    //    4

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int space = i-1;
        while(space>0){
            cout<<" ";
            space--;
        }
        int j = 1;
        while(j<=n-i+1){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    //    1
    //   22
    //  333
    // 4444

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int space = n-i;
        while(space){
            cout<<" ";
            space--;
        }
        int j = 1;
        while(j<=i){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // 1234
    //  234
    //   34
    //    4

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int space = i - 1;
        while(space){
            cout<<" ";
            space--;
        }
        int j = i;
        while(j<=n){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }*/


    // Answer:
    //    1
    //   121
    //  12321
    // 1234321

    /*int n;
    cin>>n;
    int i = 1;
    while(i<=n){
        int space = n- i;
        while(space){
            cout<<" ";
            space--;
        }
        int j = 1;
        while(j<=i){
            cout<<j;
            j++;
        }
        int start = i-1;
        while(start){
            cout<<start;
            start--;
        }
        cout<<endl;
        i++;
    }*/

    // Answer:
    // 1234554321
    // 1234**4321
    // 123****321
    // 12******21
    // 1********1

    int n = 5;
    int i = n;
    while(i>=1){
        int j = 1;
        while(j<=i){
            cout<<j;
            j++;
        }
        int star = n-i;
        while(star){
            cout<<'*';
            star--;
        }
        int star2 = i - n;
        while(star2){
            cout<<'*';
            star2++;
        }
        int newNum = j-1;
        while(newNum){
            cout<<newNum;
            newNum--;
        }
        cout<<endl;
        i--;
    }
}
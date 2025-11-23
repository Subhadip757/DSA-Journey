#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isValid(int row, int col, vector<string> &board, int n){
    for(int i = col; i >= 0; i--){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    for(int i = row, j = col; i < 8 && j >= 0; i++, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    return true;
}

int ways(int col, vector<string> &board){
    if(col == 8) return 1;
    int total = 0;

    for(int row = 0; row < 8; row++){
        if(board[row][col] == '*') continue;
        
        if(isValid(row, col, board, 8)){
            board[row][col] = 'Q';
            total += ways(col + 1, board);
            board[row][col] = '.';
        }
    }

    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(8);
    for(int i = 0; i < 8; i++){
        cin>>board[i];
    }

    cout<<ways(0, board)<<"\n";

    return 0;
}
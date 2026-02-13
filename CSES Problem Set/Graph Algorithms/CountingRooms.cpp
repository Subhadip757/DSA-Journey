#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j, int n, int m){
    return i < n && i >= 0 && j < m && j >= 0;
}

void bfs(int i, int j, int n, int m, vector<vector<char>> &arr, vector<vector<bool>> &vis){
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(isValid(nx, ny, n, m) && !vis[nx][ny] && arr[nx][ny] == '.'){
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int countRooms(int n, int m, vector<vector<char>> &arr){
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '.' && !vis[i][j]){
                bfs(i, j, n, m, arr, vis);
                count++;
            }
        }
    }

    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m, '.'));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<countRooms(n, m, arr)<<"\n";

    return 0;
}
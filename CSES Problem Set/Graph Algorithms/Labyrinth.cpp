#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isValid(int i, int j, int n, int m){
    return i < n && i >= 0 && j < m && j >= 0;
}

pair<int, string> labyrinth(int n, int m, pair<int, int> start, pair<int, int> end, vector<vector<char>> &arr){
    queue<pair<int, pair<string, pair<int, int>>>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    q.push({0, {"",{start.first, start.second}}});
    vis[start.first][start.second] = true;

    while(!q.empty()){
        int cost = q.front().first;
        string path = q.front().second.first;
        int x = q.front().second.second.first;
        int y = q.front().second.second.second;
        q.pop();

        if(x == end.first && y == end.second) return {cost, path};

        for(int k = 0; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(isValid(nx, ny, n, m) && !vis[nx][ny] && (arr[nx][ny] == '.' || arr[nx][ny] == 'B')){
                vis[nx][ny] = true;
                char tempPath = ' ';
                if(dx[k] == -1 && dy[k] == 0)tempPath = 'U';
                else if(dx[k] == 0 && dy[k] == 1) tempPath = 'R';
                else if(dx[k] == 1 && dy[k] == 0) tempPath = 'D';
                else if(dx[k] == 0 && dy[k] == -1) tempPath = 'L';
                q.push({cost + 1, {path + tempPath, {nx, ny}}});
            }
        }
    }

    return {-1, ""};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n, vector<char>(m, '.'));
    pair<int, int> start, end;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'A') start = {i, j};
            if(arr[i][j] == 'B') end = {i, j};
        }
    }

    pair<int, string> output = labyrinth(n, m, start, end, arr);
    if(output.first != -1){
        cout<<"YES\n"<<output.first<<"\n"<<output.second;
    }
    else{
        cout<<"NO";
    }
    return 0;
}
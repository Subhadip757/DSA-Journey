#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[8] = {2, 2, 1, -1, -2, -2, 1, -1};
int dy[8] = {-1, 1, -2, -2, 1, -1, 2, 2};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(n, -1));

    dist[0][0] = 0;
    q.push({0, 0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < n && ny < n && nx >= 0 && ny >= 0 && dist[nx][ny] == -1){
                dist[nx][ny] = 1 + dist[x][y];
                q.push({nx, ny});
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
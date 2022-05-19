#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

struct state{
    int x;
    int y;
    int orange;
    int sliding;
    int dist;
};

int grid[1001][1001];
int visited[1001][1001][2][5];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int> (m, 0));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> grid[i][j];

    queue<state> q;
    struct state cur = {0, 0, 0, 4, 0};
    q.push(cur);
    visited[0][0][0][4] = 1;
    while (!q.empty()){
        cur = q.front(); q.pop();
        if (grid[cur.x][cur.y] == 4 and cur.sliding < 4){
            int new_x = cur.x + dx[cur.sliding];
            int new_y = cur.y + dy[cur.sliding];
            if (new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and grid[new_x][new_y] != 0 and grid[new_x][new_y] != 3){
                if (visited[new_x][new_y][0][cur.sliding] > 0) continue;
                if (new_x == n - 1 and new_y == m - 1){
                    cout << cur.dist + 1;
                    return 0;
                }
                int new_sliding = grid[new_x][new_y] == 4 ? cur.sliding : 4;
                q.push({new_x, new_y, 0, new_sliding, cur.dist + 1});
                visited[new_x][new_y][0][new_sliding] = 1;
                continue;
            }
        }
        
        for (int i=0; i<4; i++){
            int new_x = cur.x + dx[i], new_y = cur.y + dy[i], new_orange = cur.orange, new_sliding = 4, new_dist = cur.dist + 1;
            if (new_x < 0 || new_y < 0 || new_x >= n || new_y >= m) continue;
            int color = grid[new_x][new_y];
            if (color == 0 or (color == 3 and cur.orange == 0)) continue;
            else if (color == 2) new_orange = 1;
            else if (color == 4){
                new_sliding = i;
                new_orange = 0;
            }
            if (new_x == n - 1 and new_y == m - 1){
                cout << new_dist;
                return 0;
            }
            if (visited[new_x][new_y][new_orange][new_sliding] > 0) continue;
            q.push({new_x, new_y, new_orange, new_sliding, new_dist});
            visited[new_x][new_y][new_orange][new_sliding] = 1;
        }
    }
    cout << -1;
    return 0;
}
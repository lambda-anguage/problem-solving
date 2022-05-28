#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll v, e;
    cin >> v >> e;
    map<int, map<int, int>> graph;
    int s, a, b, c;
    cin >> s;
    s -= 1;
    for (int i=0; i<e; i++){
        cin >> a >> b >> c;
        if (!graph[a - 1].count(b - 1))
            graph[a - 1][b - 1] = c;
        else
            graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(v, -1), visited(v, 0);
    dist[s] = 0;
    visited[s] = 1;
    q.push({0, s});
    while (!q.empty()){
        pair<int, int> cur = q.top();
        q.pop();
        visited[cur.second] = 1;
        for (auto i: graph[cur.second]){
            if (visited[i.first]) continue;
            int x = i.first, y = cur.first + i.second;
            if (dist[x] > y || dist[x] < 0){
                dist[x] = y;
                q.push({y, x});
            }
        }
    }
    for (auto i: dist){
        if (i == -1) cout << "INF\n";
        else cout << i << '\n';
    }
}

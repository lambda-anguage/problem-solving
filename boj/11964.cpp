#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int t, a, b, ret;
void dfs(vector<bool>& v, int cur, int& ret, bool can_drink){
    if (cur > t or v[cur])
        return;
    if (cur> ret)
        ret = cur;
    v[cur] = true;
    dfs(v, cur + a, ret, can_drink);
    dfs(v, cur + b, ret, can_drink);
    if (can_drink)
        dfs(v, cur / 2, ret, false);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t >> a >> b;
    vector<bool> visited(t + 2, false);
    dfs(visited, 0, ret, true);

    cout << ret;
}
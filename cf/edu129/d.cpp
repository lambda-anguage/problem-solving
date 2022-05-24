#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    ll x;
    queue<ll> q;
    map<ll, int> dp;
    cin >> n >> x;

    q.push(x);
    dp[x] = 0;
    while (!q.empty()){
        ll cur = q.front();
        q.pop();
        string s = to_string(cur);
        if (s.size() == n){
            cout << dp[cur];
            return 0;
        }

        for (auto c: s){
            ll tmp = cur * int(c - '0');
            if (c == '0' || dp.count(tmp)) continue;
            dp[tmp] = dp[cur] + 1;
            q.push(tmp);
        }
    }
    cout << -1;
    return 0;
}
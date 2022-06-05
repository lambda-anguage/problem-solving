#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<pair<ll, ll>> y(m);
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<m; i++) cin >> y[i].second >> y[i].first;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int a = 0, b = m - 1;
    while (x[a] < y[b].first and a < n and b >= 0){
        if (!y[b].second){
            b--;
            continue;
        }
        x[a] = y[b].first;
        a++;
        y[b].second--;
    }
    ll ret = 0;
    for (int i=0; i<n; i++) ret += x[i];
    cout << ret;
    return 0;
}

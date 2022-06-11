#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    vector<ll> s(n-1), x(m);
    for (int i=0; i<n-1; i++) cin >> s[i];
    for (int i=0; i<m; i++) cin >> x[i];
    vector<ll> a(n, 0);
    for (int i=0; i<n-1; i++){
        a[i + 1] = s[i] - a[i];
    }
    map<ll, ll> ret;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (i % 2 == 0){
                ret[x[j] - a[i]]++;
            }else{
                ret[a[i] - x[j]]++;
            }
        }
    }
    ll rret = 0;
    for (auto i: ret){
        rret = max(rret, i.second);
    }
    cout << rret;
    return 0;
}

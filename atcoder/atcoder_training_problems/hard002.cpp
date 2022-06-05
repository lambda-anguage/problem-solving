#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, k, s1=0, s2=0, ret=0;
    cin >> n >> k;
    ll t1 = (k * (k + 1) / 2) % mod;
    ll t2 = (k * (k - 1) / 2) % mod;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (x[i] <= x[j]) continue;
            if (i > j) s2++;
            else s1++;
        }
    }
    ret = (s1 * t1) % mod;
    ret = (ret + s2 * t2) % mod;
    cout << ret;
    
    return 0;
}

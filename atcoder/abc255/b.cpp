#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll f(ll x){
    return x * x;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    vector<pair<ll, ll>> x(n);
    for (int i=0; i<k; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> x[i].first >> x[i].second;
    ll ret = 0;
    for (int j=0; j<n; j++){
        ll tmp1 = LLONG_MAX;
        for (int i=0; i<k; i++){
            int l = a[i] - 1;
            tmp1 = min(tmp1, f(x[l].first -x[j].first) + f(x[l].second -x[j].second));
        }
        ret = max(ret, tmp1);
    }
    cout << sqrt(ret);
    return 0;
}

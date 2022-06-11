#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<ll> psum(1, 0), ssum(1, 0);
    ll subsum = 0;
    for (int i=0; i<n; i++){
        subsum += a[i];
        psum.push_back(subsum);
    }
    subsum = 0;
    for (int i=n-1; i>=0; i--){
        subsum += a[i];
        ssum.push_back(subsum);
    }
    for (int i=0; i<q; i++){
        ll tmp;
        cin >> tmp;
        int p_idx = upper_bound(a.begin(), a.end(), tmp) - a.begin();
        int s_idx = n - p_idx;
        cout << ssum[s_idx] - psum[p_idx] + tmp * (p_idx - s_idx) << '\n';
    }
    return 0;
}

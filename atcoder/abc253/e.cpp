#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
    if (k == 0ll){
        ll ret = 1;
        while (n--) ret = (ret * m) % mod;
        cout << ret;
        return 0;
    }
    vector<vector<ll>> dp(n, vector<ll> (m + 1, 0));
    for (ll i=0; i<m + 1; i++) dp[0][i] = i;

    for (ll i=1; i<n; i++){
        for (ll j=1; j<=m; j++){
            dp[i][j] = (dp[i][j - 1] + dp[i-1][m]) % mod;
            ll tmp = (dp[i-1][min(j + k - 1, m)] - dp[i-1][max(j - k, 0ll)]) % mod;
            dp[i][j] = (dp[i][j] - tmp + mod) % mod; 
        }
    }
    cout << dp[n - 1][m];
    return 0;
}

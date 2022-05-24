#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t=1;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n;
        vector<int> x(n);
        for (int i=0; i<n; i++){
            cin >> x[i];
        }
        cin >> m;
        int count = 0, tmp;
        for (int i=0; i<m; i++){
            cin >> tmp;
            count = (count + tmp) % n;
        }
        cout << x[count] << '\n';
    }
    return 0;
}
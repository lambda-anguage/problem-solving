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
        int n, m, x = 0, y = 0, tmp;
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> tmp;
            x = max(x, tmp);
        }
        cin >> m;
        for (int i=0; i<m; i++){
            cin >> tmp;
            y = max(y, tmp);
        }
        if (x > y) cout << "Alice\nAlice\n";
        else if (x < y) cout << "Bob\nBob\n";
        else cout << "Alice\nBob\n";
    }
    return 0;
}

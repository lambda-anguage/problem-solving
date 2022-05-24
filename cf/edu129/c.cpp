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
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];

        bool isvalid = true;
        for (int i=0; i<n-1; i++){
            for (int j=i + 1; j<n; j++){
                if (a[i] == a[j] || b[i] == b[j]) continue;
                isvalid = isvalid && ((a[i] < a[j]) == (b[i] < b[j]));
            }
        }
        if (!isvalid){
            cout << -1 << '\n';
            continue;
        }

        vector<pair<int, int>> ret;
        for (int i=0; i<n-1; i++){
            if (a[i] <= a[i + 1] && b[i] <= b[i + 1]) continue;
            int j = i;
            int tmp;
            while (j >= 0 && (a[j] > a[j + 1] || b[j] > b[j + 1])){
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                tmp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp;
                ret.push_back({j + 1, j + 2});
                j--;
            }
        }
        cout << ret.size() << '\n';
        for (int i=0; i<ret.size(); i++)
            cout << ret[i].first << ' ' << ret[i].second << '\n';
    }
    return 0;
}
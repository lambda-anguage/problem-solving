#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n=1;
    cin >> n;
    map<int, int> x;
    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        x[-tmp] = i;
    }
    vector<int> y;
    int ret = 0;
    for (auto i: x){
        int l = upper_bound(y.begin(), y.end(), i.second) - y.begin();
        int r = y.size() - l;
        y.insert(y.begin() + l, i.second);
        if (l > r * 2 || r > l * 2) ret++;
    }
    cout << ret;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> get_subset(vector<int>& x, int y){
    vector<int> ret;
    int idx = 0;
    while(y){
        if (y % 2 == 1) ret.push_back(x[idx]);
        idx++;
        y /= 2;
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin >> n;
    ll ret = n * (n - 1) / 2;
    map<vector<int>, int> d;
    for (int i=0; i<n; i++){
        vector<int> flavors(5);
        for (int j=0; j<5; j++) cin >> flavors[j];
        for (int j=1; j<32; j++){
            vector<int> subset = get_subset(flavors, j);
            if (!d.count(subset)) d[subset] = 0;
            ret -= d[subset] * (subset.size() % 2 == 1 ? 1 : -1);
            d[subset]++;
        }
    }
    cout << ret;
}

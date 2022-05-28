#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin >> n;
    ll ret = n * (n - 1) / 2;
    int tmp;
    bitset<50000> c;
    map<int, bitset<50000>> d;
    for (int i=0; i<n; i++){
        c.reset();
        for (int j=0; j<5; j++){
            cin >> tmp;
            c |= d[tmp];
            d[tmp].flip(i);
        }
        ret -= c.count();
    }
    cout << ret;
}

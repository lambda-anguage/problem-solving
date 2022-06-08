#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll a, b, x;
    cin >> a >> b >> x;
    cout << (b / x - a / x + (a % x == 0));
    return 0;
}

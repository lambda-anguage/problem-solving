#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    if (a>=b and b>=c) cout << "Yes";
    else if (a<=b and b<=c) cout << "Yes";
    else cout << "No";
}

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, a, b, c, d, l, e;
    cin >> n >> a >> b;
    c = n / a;
    d = n / b;
    ll tmp1 = a, tmp2 = b, tmp3;
    while (tmp1 != tmp2){
        if (tmp2 > tmp1){
            tmp3 = tmp1;
            tmp1 = tmp2;
            tmp2 = tmp3;
        }
        tmp1 -= tmp2;
    }
    l = a * b / tmp1;
    e = n / l;


    ll ret = n * (n + 1) / 2;
    ret -= a * c * (c + 1) / 2;
    ret -= b * d * (d + 1) / 2;
    ret += l * e * (e + 1) / 2;
    cout << ret;
}

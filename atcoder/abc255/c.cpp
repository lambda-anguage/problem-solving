#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    if (d == 0){
        cout << abs(x - a);
        return 0;
    }else if (d < 0){
        d = -d;
        a = a - d * (n - 1);
    }
    if (x < a){
        cout << a - x;
    }else if(x > a + d * (n - 1)){
        cout << x - a - d * (n - 1);
    }else{
        while (x - a < 0) x += d;
        cout << min((d - (x - a) % d), (x - a) % d);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n, m;
    cin >> n >> m;
    priority_queue<ll> x;
    for (int i=0; i<n; i++){
        ll tmp;
        cin >> tmp;
        x.push(tmp);
    }
    while (m-- and x.top() > 0){
        ll tmp = x.top(); x.pop();
        x.push(tmp / 2);
    }
    ll ret = 0;
    for (int i=0; i<n; i++){
        ret += x.top();
        x.pop();
    }
    cout << ret;
    return 0;
}

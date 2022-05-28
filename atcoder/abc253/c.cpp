#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n=1;
    cin >> n;
    map<int, int> s;
    int a, b, c;
    for (int i=0; i<n; i++){
        cin >> a;
        if (a == 3){
            int tmp1, tmp2;

            cout << s.rbegin()->first - s.begin()->first << '\n';
        }
        else if (a == 2){
            cin >> b >> c;
            while(c-- and s[b]){
                s[b] -= 1;
            }
            if (s[b] == 0) s.erase(b);
        }else if (a == 1){
            cin >> b;
            s[b] += 1;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s;
    cin >> s;
    int n = s.size(), prev_rl, count = 0;
    vector<int> ret(n, 0);
    char c, d;
    for (int i=1; i<=n; i++){
        c = s[i - 1];
        d = i == n ? 'R' : s[i];
        count++;
        if (c == 'R' and d == 'L'){
            prev_rl = i - 1;
        }else if (c == 'L' and d == 'R'){
            if ((i - 1 - prev_rl) % 2 == 0){
                ret[prev_rl] = count / 2 + (count % 2);
                ret[prev_rl + 1] = count / 2;
            }else{
                ret[prev_rl + 1] = count / 2 + (count % 2);
                ret[prev_rl] = count / 2;
            }
            count = 0;
        }
    }
    for (auto k: ret) cout << k << ' ';
    return 0;
}

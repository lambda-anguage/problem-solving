#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool mtch(string s, string t, int start, int n, int m){
    for (int i=0; i<m; i++){
        if (i + start >= n or (s[i + start] != t[i] and s[i + start] != '?')) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    string s, t, ret;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i=n-1; i>=0; i--){
        if (mtch(s, t, i, n, m)){
            for (int j=0; j<n; j++){
                if (s[j] == '?'){
                    if (j >= i and j < i + m) cout << t[j - i];
                    else cout << 'a';
                } else cout << s[j];
            }
            return 0;
        }
    }
    cout << "UNRESTORABLE";
    return 0;
}

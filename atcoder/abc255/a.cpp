#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int r, c;
    vector<vector<int>> x(2, vector<int> (2, 0));
    cin >> r >> c;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            cin >> x[i][j];
        }
    }
    cout << x[r - 1][c - 1];
    return 0;
}

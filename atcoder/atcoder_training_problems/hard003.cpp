#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int h, w;
    cin >> h >> w;
    vector<vector<int>> grid(h, vector<int> (w, 0));
    char c;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin >> c;
            grid[i][j] = c == '.' ? 1 : 0;
        }
    }
    vector<vector<int>> dp(h, vector<int> (w, INT32_MAX));
    dp[0][0] = 1 - grid[0][0];
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (grid[i][j] == 0 and grid[i - 1][j] == 1 ? 1 : 0));
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (grid[i][j] == 0 and grid[i][j - 1] == 1 ? 1 : 0));
        }
    }
    cout << dp[h - 1][w - 1];
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int h, w;
    cin >> h >> w;
    vector<pair<int, int>> x;
    char c;
    int tmp = 0;
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin >> c;
            if (c == 'o'){
                x.push_back({i, j});
            }
        }
    }
    int ret = abs(x[0].first - x[1].first) + abs(x[0].second - x[1].second);
    cout << ret;
}

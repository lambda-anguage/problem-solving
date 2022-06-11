#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int search(vector<pair<int, int>>& tree, vector<int>& x, vector<int>& y, map<int, int>& ymap, int xl, int xr, int yl, int yr){
    int root = x[xl];
    int rootidx_y = ymap[root];
    if (rootidx_y < yl or rootidx_y > yr) return -1;
    int tmp;
    if (rootidx_y > yl){
        int tmp = search(tree, x, y, ymap, xl + 1, xl + rootidx_y - yl, yl, rootidx_y - 1);
        if (tmp > 0){
            tree[root - 1].first = tmp;
        }
        else return -1;
    }
    if (rootidx_y < yr){
        tmp = search(tree, x, y, ymap, xl + rootidx_y  - yl + 1, xr, rootidx_y + 1, yr);
        if (tmp > 0){
            tree[root - 1].second = tmp;
        }
        else return -1;
    }
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<pair<int, int>> ret(n);
    for (int i=0; i<n; i++) cin >> x[i];
    for (int i=0; i<n; i++) cin >> y[i];
    map<int, int> ymap;
    for (int i=0; i<n; i++){
        ymap[y[i]] = i;
    }
    int r = search(ret, x, y, ymap, 0, n - 1, 0, n - 1);
    if (r != 1){
        cout << -1;
        return 0;
    }
    for (auto i: ret){
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}
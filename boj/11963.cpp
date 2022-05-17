// https://www.acmicpc.net/problem/11963
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> e_large(n/2), e_small(n/2), b_large, b_small;
    vector<bool> used(2*n + 10, false);
    for (int i=0; i<n; i++){
        if (i < n/2){
            cin >> e_large[i];
            used[e_large[i]] = true;
        }else {
            cin >> e_small[i - n/2];
            used[e_small[i - n/2]] = true;
        }
    }
    sort(e_large.begin(), e_large.end());
    sort(e_small.begin(), e_small.end());

    for (int i=1; i<=2*n;i++){
        if (!used[i]){
            if (b_small.size() < n/2)
                b_small.push_back(i);
            else
                b_large.push_back(i);
        }
    }

    int ret = 0;
    int i = 0, j = 0;
    while (i < n/2 and j < n/2){
        if (e_large[i] < b_large[j]){
            i++; ret++;
        }
        j++;
    }
    i = n/2 -  1; j = n/2 - 1;
    while (i>=0 and j>=0){
        if (e_small[i] > b_small[j]){
            i--; ret++;
        }
        j--;
    }
    cout << ret;
}
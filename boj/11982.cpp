#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n;
    cin >> n;
    vector<int> x(n);

    for (int i=0; i<n; i++){
        cin >> x[i];
        x[i] *= 2;
    }

    cout << fixed;
    cout.precision(1);

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    n = x.size();
    vector<int> l(n, 1), r(n, 1); // minimum radius required to explode all {left, right} hay bales for the {i}-th hay bale.

    for (int i=1; i<n; i++){
        // what we want to do is : l[i] = min(max(l[j], x[i] - x[j]) for j in range(i))
        int start = 0, end = i - 1;
        while (end > start + 1){
            int mid = (start + end) / 2;
            if (x[i] - x[mid] - l[mid] >= 0)
                start = mid;
            else
                end = mid;
        }
        l[i] = min(max(x[i] - x[end] + 2, l[end] + 2), max(x[i] - x[start] + 2, l[start] + 2));
    }

    for (int i=n-2; i>=0; i--){
        int start = i + 1, end = n - 1;
        while (end > start + 1){
            int mid = (start + end) / 2;
            if (x[mid] - x[i] - r[mid] >= 0)
                end = mid;
            else
                start = mid;
        }
        r[i] = min(max(x[end] - x[i] + 2, r[end] + 2), max(x[start] - x[i] + 2, r[start] + 2));
    }

    // finally what we want is min(max(l[i], r[j], (x[j] - x[i]) / 2) for i<=j)
    int start = 0, end = n - 1;
    int ret = INT_MAX;
    while (end > start){
        int tmp = 0;
        tmp = max(tmp, l[start]);
        tmp = max(tmp, r[end]);
        tmp = max(tmp, (x[end] - x[start]) / 2);

        ret = min(ret, tmp);

        if (r[end - 1] >= l[start + 1])
            start++;
        else
            end--;
    }
    double dret = ret / 2.;
    cout << dret;
}
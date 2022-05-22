#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int dist(pair<int, int> x, pair<int, int> y){
	return pow(x.first - y.first, 2) + pow(x.second - y.second, 2);
}

pair<int, int> step(pair<int, int> x, char dir){
	if (dir == 'N')
		return {x.first, x.second + 1};
	if (dir == 'S')
		return {x.first, x.second - 1};
	if (dir == 'E')
		return {x.first + 1, x.second};
	if (dir == 'W')
		return {x.first - 1, x.second};
    return {0, 0};
}

int main(){
	int n, m, a, b, x, y;
	cin >> n >> m;
	cin >> a >> b;
	cin >> x >> y;
	vector<pair<int, int>> u(n + 1), v(m + 1);
	u[0] = {a, b};
	v[0] = {x, y};
	char c;
	for (int i=0; i<n; i++){
		cin >> c;
		u[i + 1] = step(u[i], c);
	}
	for (int j=0; j<m; j++){
		cin >> c;
		v[j + 1] = step(v[j], c);
	}

	for (int i=0; i<=n; i++){
		for (int j=0; j<=m; j++){
			if (i == 0 && j == 0){
				dp[i][j] = 0; continue;
			}
			int tmp = INT_MAX;
			if (i > 0) tmp = min(tmp, dp[i - 1][j]);
			if (j > 0) tmp = min(tmp, dp[i][j - 1]);
			if (i > 0 && j > 0) tmp = min(tmp, dp[i - 1][j - 1]);
			dp[i][j] = tmp + dist(u[i], v[j]);
		}
	}
	cout << dp[n][m];
}
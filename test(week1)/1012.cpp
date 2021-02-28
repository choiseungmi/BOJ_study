#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int n, m;
bool g[52][52] = { 0, };
bool visit[52][52] = { 0, };
int v1[4] = { 1,0,-1,0 }, v2[4] = { 0,1,0,-1 };

void dfs(int a, int b) {
	visit[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		if (g[a + v1[i]][b + v2[i]] && !visit[a + v1[i]][b + v2[i]]) {
			dfs(a + v1[i], b + v2[i]);
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int num;
		cin >> n >> m >> num;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				g[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for (int i = 1; i <= num; i++) {
			int temp1, temp2;
			cin >> temp1 >> temp2;
			g[temp1 + 1][temp2 + 1] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] && !visit[i][j]) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}

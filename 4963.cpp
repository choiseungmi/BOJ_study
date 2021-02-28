#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int n, m;
int g[50][50] = { 0, };
bool visit[50][50] = { 0, };
int v1[8] = { -1,-1,-1,0,0,1,1,1 }, v2[8] = { -1,0,1,-1,1,-1,0,1 };

void dfs(int i, int j) {
	int i2, j2;
	for (int a = 0; a<8; a++) {
		i2 = i + v1[a];
		j2 = j + v2[a];
		if (0 <= i2 && i2<50 && 0 <= j2 && j2<50) {
			if (!visit[i2][j2] && g[i2][j2]) {
				visit[i2][j2] = 1;
				dfs(i2, j2);
			}
		}
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int w, h;
	cin >> w >> h;
	while (w != 0) {
		for (int i = 0; i<50; i++) {
			for (int j = 0; j<50; j++) {
				g[i][j] = 0;
				visit[i][j] = 0;
			}
		}
		for (int i = 0; i<h; i++) {
			for (int j = 0; j<w; j++) {
				cin >> g[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i<h; i++) {
			for (int j = 0; j<w; j++) {
				if (!visit[i][j] && g[i][j] == 1) {
					ans++;
					visit[i][j] = 1;
					dfs(i, j);
				}
			}
		}
		cout << ans << '\n';
		cin >> w >> h;
	}
	return 0;
}

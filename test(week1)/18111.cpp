#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m, b;
	cin >> n >> m >> b;
	vector<int> v(n*m, 0);
	int minv = 256, maxv = 0;
	int bb = 0;
	for (int i = 0; i<n*m; i++) {
		cin >> v[i];
		bb += v[i];
		if (minv>v[i]) minv = v[i];
		if (maxv<v[i]) maxv = v[i];
	}
	if (((bb + b) / (m*n))<maxv)
		maxv = (bb + b) / (m*n);

	long long time = 0;
	for (int j = 0; j<n*m; j++) {
		if (v[j]>minv) {
			time += (2 * (v[j] - minv));
		}
		if (v[j]<minv) {
			time += (minv - v[j]);
		}
	}
	int ans = minv;
	for (int i = minv + 1; i <= maxv; i++) {
		long long temp = 0;
		for (int j = 0; j<n*m; j++) {
			if (v[j]>i) {
				temp += (2 * (v[j] - i));
			}
			if (v[j]<i) {
				temp += (i - v[j]);
			}
		}
		if (temp <= time) {
			ans = i;
			time = temp;
		}
	}
	cout << time << ' ' << ans << '\n';

	return 0;
}
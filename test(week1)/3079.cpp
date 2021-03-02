#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	long long m, maxv = 1;
	cin >> n >> m;
	vector<long long> v(n, 0);
	for (int i = 0; i<n; i++) {
		cin >> v[i];
		maxv = max(maxv, v[i]);
	}
	long long mint = 1;
	long long maxt = m*maxv;
	long long time;
	long long ans=maxt;
	long long temp;
	while (mint <= maxt) {
		temp = 0;
		time = (mint + maxt) / 2;
		for (int i = 0; i < n; i++) {
			temp += (time / v[i]);
		}
		if (temp < m) {
			mint = time+1;
		}
		else if (temp >= m){
			if (ans > time)
			{
				ans = time;
			}
			maxt = time-1;
		}
	}
	cout << ans;
	return 0;
}
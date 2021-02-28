#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n, ans = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	ans = v[0];
	for (int i = 2; i <= n; i++) {
		ans = max(ans, v[i - 1] * i);
	}
	cout << ans;
	return 0;
}
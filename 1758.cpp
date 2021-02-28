#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i<n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	long long ans = 0;
	for (int i = 0; i<n; i++) {
		if (i >= v[i]) break;
		ans += (v[i] - i);
	}
	cout << ans;

	return 0;
}

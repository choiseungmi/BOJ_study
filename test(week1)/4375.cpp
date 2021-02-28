#include<iostream>
using namespace std;

int answer(int n) {
	int ans = 1, a = 1;
	if (n == 1) return 1;
	while (a != 0) {
		a = (a * 10 + 1) % n;
		ans++;
	}
	return ans;
}

int main() {
	int n, ans = 1, a = 1;
	while (cin >> n) {
		cout << answer(n) << endl;
	}
	return 0;
}
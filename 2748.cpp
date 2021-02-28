#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long p1 = 1, p2 = 1;
	for (int i = 3; i <= n; i++) {
		long long temp = p2;
		p2 += p1;
		p1 = temp;
	}
	cout << p2 << endl;
	return 0;
}
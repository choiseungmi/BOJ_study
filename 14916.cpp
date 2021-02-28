#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	int answer = n / 5;
	int temp = n % 5;
	if (temp % 2 == 0)
		cout << answer + (temp / 2) << '\n';
	else if (answer<1)
		cout << -1 << '\n';
	else if (temp == 1)
		cout << answer + 2 << '\n';
	else
		cout << answer + 3 << '\n';


	return 0;
}

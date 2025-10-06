#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> w(n + 1);
	for (int i = 1; i <= n; i ++ )
		cin >> w[i];
	vector<i64> f(n + 1, __LONG_LONG_MAX__);
	f[0] = 0, f[1] = w[1];
	for (int i = 2; i <= n; i ++) {
		f[i] = min(f[i - 1] + w[i] - 1, f[i - 2] + w[i - 1] + max(0, w[i] - (i - 1)));
	}
	cout << f[n] << "\n";
}

int main(void) {
	int T = 1; cin >> T;
	while (T -- ) solve();
	return 0;
}


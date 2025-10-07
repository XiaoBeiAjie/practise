#include <bits/stdc++.h>
using i64 = long long;

void solve() {
	i64 h, d; std::cin >> h >> d;
	int lo = 0, hi = d;
	std::function<bool(int)> check = [&] (int mid) {
		i64 a = d / (mid + 1);
		i64 need = a * (a + 1) / 2 * (mid + 1) + (a + 1) * (d % (mid + 1));
		return need < h + mid;
	};
	while (lo < hi) {
		int mid = lo + hi >> 1;
		if (check(mid)) hi = mid;
		else lo = mid + 1;
	}
	std::cout << lo + d << "\n";
}

int main (void) {
	int T = 1; std::cin >> T;
	while (T -- ) solve();
	return 0;
}

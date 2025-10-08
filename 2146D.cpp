#include <bits/stdc++.h>
using i64 = long long;

void solve() {
	i64 l, r; std::cin >> l >> r;
	int n = r - l + 1;
	std::vector<int> w(n);
	iota(w.begin(), w.end(), l);
	std::function<void(int, int, int)> dfs = [&] (int lo, int hi, int msk) {
		if (!~msk) return ;
		if (lo > hi) return ;
		if (lo == hi) return ;
		if ((w[lo] & (1 << msk)) == (w[hi] & (1 << msk))) return dfs(lo, hi, msk - 1), void();
		int x = 1 << msk;
		int cl = x - lo - l;
		int cr = hi + l - x + 1;
		if (cl <= cr) {
			int m = lo + 2 * cl;
			std::reverse(w.begin() + lo, w.begin() + m);
			lo = m + 1;
		} else {
			int m = hi - 2 * cr + 1;
			std::cerr << m << "!!" << hi << "\n";
			std::reverse(w.begin() + m, w.begin() + hi);
			hi = m - 1;
		}
		std::cerr << cl << " " << cr << "\n";
		std::cerr << x << "!!\n";
		for (int i = 0; i < n; i ++ ) 
			std::cerr << w[i] << " \n"[i == n - 1];
		dfs(lo, hi, msk - 1);
	};
	dfs(0, n - 1, 29);
	i64 ans = 0;
	for (int i = 0; i < n; i ++ ) 
		ans += w[i] | (l + i);
	std::cerr << ans << "\n";
	for (int i = 0; i < n; i ++ ) 
		std::cerr << w[i] << " \n"[i == n - 1];
}

int main (void) {
	std::ios::sync_with_stdio(0);
	std::cout.tie(0);
	int T = 1; std::cin >> T;
	while (T -- ) solve();
	return 0;
}

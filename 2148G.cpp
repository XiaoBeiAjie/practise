#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5;
vector<vector<int>> fac(N + 1, vector<int>());
void init() {
	for (int i = 2; i <= N; i ++ ) 
		for (int j = i; j <= N; j += i) 
			fac[j].push_back(i);
}

void solve() {
	int n; std::cin >> n;
	std::vector<int> w(n + 1);
	for (int i = 1; i <= n; i ++ ) 
		std::cin >> w[i];
	vector<int> cnt(n + 1);
	vector<int> st(n + 1);
	vector<int> f;
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		int x = w[i];
		vector<int> g;
		for (auto num : fac[x]) {
			cnt[num] ++;
			if (cnt[num] != i) ans = max(ans, cnt[num]);
			else if (!st[num]) g.push_back(num), st[num] = 1;
		}
		for (auto num : f) {
			if (cnt[num] != i) ans = max(ans, cnt[num]), st[i] = 0;
			else g.push_back(num);
		}
		swap(f, g);
		cout << ans << " \n"[i == n];
	}
}

int main (void) {
	int T = 1; cin >> T;
	init();
	while (T -- ) solve();
	return 0;
}

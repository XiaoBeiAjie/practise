#include <bits/stdc++.h>

void solve() {
    int n, k; std::cin >> n >> k;
    std::vector<int> p(n + 1);
    std::vector<int> dep(n + 1);
    dep[1] = 1;
    std::vector<int> leaf(n + 1, 1);
    std::vector<int> cnt(n + 1);
    for (int i = 2; i <= n; i ++ )  {
        std::cin >> p[i];
        dep[i] = dep[p[i]] + 1;
        leaf[p[i]] = 0; 
        cnt[dep[i]] ++;
    }
    int nm = n;
    for (int i = 1; i <= n; i ++ ) 
        if (leaf[i]) nm = std::min(nm, dep[i]);
    int sum = 0;
    for (int i = 1; i <= nm; i ++ ) 
        sum += cnt[i];
    constexpr int N = 200010;
    std::bitset<N> bs;
    bs[0] = 1;
    for (int i = 1; i <= nm; i ++ ) 
        bs |= bs << cnt[i];
    for (int i = 0; i <= n; i ++ ) 
        if (bs[i] && i <= k && sum - i <= n - k) 
            return std::cout << nm << "\n", void();
    std::cout << nm - 1 << "\n";

}

int main (void) {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);
    int T = 1; std::cin >> T;
    while (T -- ) solve();
    return 0;
}
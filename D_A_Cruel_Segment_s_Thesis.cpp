#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    std::vector<std::pair<i64, i64>> w(n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n; i ++ ) {
        std::cin >> w[i].first >> w[i].second;
        ans += 2 * w[i].second - w[i].first;
        w[i].first += w[i].second;
    }
    sort(w.begin() + 1, w.end());
    if (n & 1) {
        i64 t = 0, tans = ans;
        ans = 0;
        for (int i = 1; i <= n / 2 + 1; i ++ ) 
            t += w[i].first;
        for (int i = 1; i <= n / 2 + 1; i ++ ) 
            ans = std::max(tans - t + w[i].first - w[i].second, ans);
        t -= w[n / 2 + 1].first;
        for (int i = n / 2 + 1; i <= n; i ++ ) 
            ans = std::max(tans - t - w[i].second, ans);
    } else 
        for (int i = 1; i <= n / 2; i ++ ) 
            ans -= w[i].first;
    std::cout << ans << "\n";
}

int main (void) {
    int T = 1; std::cin >> T;
    while (T -- ) solve();
    return 0;
}
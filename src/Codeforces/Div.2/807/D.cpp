/**
 * @author: XiaFan
 * @date: 07-21 21:49
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string a, b;
    std::cin >> a >> b;
    
    if (a.front() != b.front() || a.back() != b.back()) {
        std::cout << "-1\n";
        return;
    }

    std::vector<i64> pa, pb;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) pa.push_back(i);
        if (b[i] != b[i + 1]) pb.push_back(i);
    }
    if (pa.size() != pb.size()) {
        std::cout << "-1\n";
        return;
    }

    i64 ans = 0;
    for (int i = 0; i < (int)pa.size(); i++) {
        ans += abs(pa[i] - pb[i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
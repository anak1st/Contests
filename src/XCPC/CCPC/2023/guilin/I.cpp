/**
 * @author: XiaFan
 * @date: 2023-11-16 18:37
 */
#include <bits/stdc++.h>

using i64 = long long;
const int N = 5e5 + 10;
const int B = 600;
std::vector<int> cnt;
void init() {
    cnt.assign(N, 0);
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<int, int> last;
    std::vector<std::tuple<int, int, int>> Q;
    for (int i = 0; i < n; i++) {
        if (!last.count(a[i])) {
            last[a[i]] = -1;
        }
        if (last[a[i]] + 1 <= i - 1) {
            Q.emplace_back(last[a[i]] + 1, i - 1, a[i]);
        }
        last[a[i]] = i;
    }
    for (auto [k, v] : last) {
        if (v + 1 <= n - 1) {
            Q.emplace_back(v + 1, n - 1, k);
        }
    }
    std::sort(Q.begin(), Q.end(), [&](const auto &a, const auto &b) -> bool {
        auto [al, ar, am] = a;
        auto [bl, br, bm] = b;
        if (al / B != bl / B) return al < bl;
        if (al / B & 1) return ar < br;
        return ar > br;
    });

    int mex = 1;
    while (last.count(mex)) mex++;
    // std::cerr << "debug: " << mex << " " << Q.size() << "\n";

    int dif = 0;
    auto add = [&](int i) -> void {
        if (cnt[a[i]] == 0) {
            dif++;
        }
        cnt[a[i]]++;
    };
    auto del = [&](int i) -> void {
        cnt[a[i]]--;
        if (cnt[a[i]] == 0) {
            dif--;
        }
    };

    int ans = std::max(-1, (int)last.size() - mex);

    int l = 0, r = -1;
    for (const auto &[ql, qr, now_mex] : Q) {
        while (l > ql) add(--l);
        while (r < qr) add(++r);
        while (l < ql) del(l++);
        while (r > qr) del(r--);
        // std::cerr << l << " " << r << " " << dif << " " << now_mex << "\n";
        ans = std::max(ans, dif - now_mex);
    }

    for (int i = 0; i < n; i++) {
        cnt[a[i]] = 0;
    }

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();
    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
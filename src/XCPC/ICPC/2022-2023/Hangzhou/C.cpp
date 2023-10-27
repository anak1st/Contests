/**
 * @author: XiaFan
 * @date: 2023-10-25 13:05
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 INF = 1e18;

template <typename T>
void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n + 1);
    std::vector<std::vector<i64>> w(n + 1);
    std::vector<i64> fw(n + 1);
    int sump = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> p[i];
        sump += p[i];
        w[i].resize(p[i] + 1);
        for (int j = 1; j <= p[i]; j++) {
            std::cin >> w[i][j];
        }
        fw[i] = w[i][p[i]];
    }
    
    std::vector dp_pref(n + 2, std::vector<i64>(k + 1, -INF));
    std::vector dp_suff(n + 2, std::vector<i64>(k + 1, -INF));
    dp_pref[0][0] = 0;
    dp_suff[n + 1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp_pref[i][j] = dp_pref[i - 1][j];
            if (j >= p[i] && dp_pref[i - 1][j - p[i]] != -INF) {
                chmax(dp_pref[i][j], dp_pref[i - 1][j - p[i]] + fw[i]);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 0; j <= k; j++) {
            dp_suff[i][j] = dp_suff[i + 1][j];
            if (j >= p[i] && dp_suff[i + 1][j - p[i]] != -INF) {
                chmax(dp_suff[i][j], dp_suff[i + 1][j - p[i]] + fw[i]);
            }
        }
    }

    i64 ans = 0;
    if (k >= sump) {
        ans = dp_pref[n][sump];
        std::cout << ans << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        auto get = [&](int x) -> i64 {
            i64 res = -INF;
            for (int j = 0; j <= x; j++) {
                auto res1 = dp_pref[i - 1][j];
                auto res2 = dp_suff[i + 1][x - j];
                chmax(res, res1 + res2);
            }
            return res;
        };
        
        for (int j = 0; j <= p[i]; j++) {
            i64 tmp = get(k - j);
            tmp += w[i][j];
            chmax(ans, tmp);
        }
    }

    std::cout << ans << "\n";

    return 0;
}
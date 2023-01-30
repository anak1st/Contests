/**
 * @author: XiaFan
 * @date: 2023-01-30 14:07
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;
    std::vector<i64> w(N + 1), v(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> w[i] >> v[i];
    }

    std::vector<std::vector<i64>> pref(N + 2, std::vector<i64>(M + 1));
    std::vector<std::vector<i64>> suff(N + 2, std::vector<i64>(M + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            pref[i][j] = pref[i - 1][j];
            if (j >= w[i]) {
                pref[i][j] = std::max(pref[i][j], pref[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    for (int i = N; i >= 1; i--) {
        for (int j = 1; j <= M; j++) {
            suff[i][j] = suff[i + 1][j];
            if (j >= w[i]) {
                suff[i][j] = std::max(suff[i][j], suff[i + 1][j - w[i]] + v[i]);
            }
        }
    }

    auto get = [&](int x, int V) -> i64 {
        i64 res = 0;
        for (int i = 0; i <= V; i++) {
            res = std::max(res, pref[x - 1][i] + suff[x + 1][V - i]);
        }
        return res;
    };
    i64 max = pref[N][M];
    for (int i = 1; i <= N; i++) {
        if (get(i, M) < max) {
            std::cout << 0 << "\n";
        } else {
            std::cout << max - (get(i, M - w[i]) + v[i]) + 1 << "\n";
        }
    }

    return 0;
}
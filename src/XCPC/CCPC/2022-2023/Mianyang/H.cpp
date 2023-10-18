/**
 * @author: XiaFan
 * @date: 2023-10-18 14:11
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 300;

std::vector<std::vector<int>> next(const std::vector<std::vector<int>> &now) {
    std::vector<std::vector<int>> nxt = now;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int cnt = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    if (i + dx < 0 || i + dx >= N || j + dy < 0 || j + dy >= N) {
                        continue;
                    }
                    cnt += now[i + dx][j + dy];
                }
            }
            if (cnt >= 4 || cnt <= 1) {
                nxt[i][j] = 0;
            } else if (cnt == 3) {
                nxt[i][j] = 1;
            }
        }
    }
    return nxt;
}

int count(const std::vector<std::vector<int>> &now) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt += now[i][j];
        }
    }
    return cnt;
}

struct Gen {
    unsigned int seed;
    std::mt19937 engine;
    Gen() : seed{std::random_device{}()}, engine(seed) {}
};
template <typename T>
struct Randomer {
    Gen G;
    std::uniform_int_distribution<T> distribution;
    Randomer(T min, T max) : distribution(min, max) {}
    T operator()() { return distribution(G.engine); }
};

void solve() {
    int n;
    std::cin >> n;

    //std::vector<std::vector<int>> now(N, std::vector<int>(N));
    std::cout << n * 2 << '\n';
    for (int i = 0; i < n * 2; i++) {
        //now[i][i] = 1;
        std::cout << i + 1 << ' ' << i + 1 << '\n';
    }

    // for (int i = 0; i < n; i++) {
    //     now = next(now);
    //     std::cout << count(now) << '\n';
    // }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
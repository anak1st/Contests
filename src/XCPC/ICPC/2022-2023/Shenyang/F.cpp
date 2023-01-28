/**
 * @author: XiaFan
 * @date: 2023-01-28 14:18
 **/
#include <bits/stdc++.h>
#include <debug/vector>
using i64 = long long;

int subsolve(int n, int m, bool change) {
    i64 N;
    if (change) {
        N = m;
    } else {
        N = n;
    }
    i64 X = N * (N + 1) / 2;
    if (X % 2 != 0) {
        // std::cout << "-- No start\n";
        return 1;
    }
    i64 d = X / 2 - N;
    std::vector<i64> a;
    while (d) {
        i64 left = 1, right = N, ans = 0;
        while (left <= right) {
            i64 mid = (left + right) / 2;
            if (mid * (mid + 1) / 2 <= d) {
                left = mid + 1;
                ans = mid;
            } else {
                right = mid - 1;
            }
        }
        a.push_back(ans);
        d -= ans * (ans + 1) / 2;
    }
    // for (int i = 0; i < (int)a.size(); i++) {
    //     std::cerr << a[i] << " \n"[i ==  (int)a.size() - 1];
    // }
    i64 cnt = 0;
    std::vector<int> flag(N, 1);
    flag[0] = 1;
    for (int i = 0; i < (int)a.size(); i++) {
        if (cnt >= N) {
            return 1;
        }
        flag[cnt] = a[i] + 1;
        cnt += a[i] + 1;
    }
    
    for (int i = 1; i < N; i++) {
        if (flag[i - 1] > 1) {
            flag[i] = flag[i - 1] - 1;
        }
    }
    // for (int i = 0; i < N; i++) {
    //     std::cerr << flag[i] << " \n"[i == N - 1];
    // }
    if (flag.back() > 1) {
        return 1;
    }

    std::cout << "Yes\n";
    if (!change) {
        int tmp = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << tmp << " \n"[j == m - 1];
            }
            if (flag[i] == 1) {
                tmp ^= 1;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            int tmp = 1;
            for (int j = 0; j < m; j++) {
                std::cout << tmp << " \n"[j == m - 1];
                if (flag[j] == 1) {
                    tmp ^= 1;
                }
            }
        }
    }

    return 0;
}

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    i64 x = n * (n + 1) / 2;
    i64 y = m * (m + 1) / 2;
    if ((x * y) % 2 != 0) {
        std::cout << "No\n";
        return;
    }
    if (!subsolve(n, m, false)) {
        return;
    }
    if (!subsolve(n, m, true)) {
        return;
    }
    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
/**
 * @author: XiaFan
 * @date: 2023-01-28 13:30
 **/
#include <bits/stdc++.h>
using i64 = long long;

struct node {
    double a, b, c;
    node() : a(0), b(0), c(0) {}
    node(double a, double b, double c) : a(a), b(b), c(c) {}
    node& operator*=(double rhs) {
        a *= rhs;
        b *= rhs;
        c *= rhs;
        return *this;
    }
    node &operator+=(const node& rhs) {
        a += rhs.a;
        b += rhs.b;
        c += rhs.c;
        return *this;
    }
    friend node operator+(const node& lhs, const node& rhs) {
        node res = lhs;
        res += rhs;
        return res;
    }
    friend node operator*(const node& lhs, double rhs) {
        node res = lhs;
        res *= rhs;
        return res;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> H1(n);
    std::vector<int> H2(m);
    for (int i = 0; i < n; i++) {
        std::cin >> H1[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> H2[i];
    }
    auto A1 = H1;
    auto A2 = H2;
    std::vector<int> cnt1(n), cnt2(m);

    auto dfs = [&](auto&& dfs, bool first) -> node {
        int c1 = std::count_if(H1.begin(), H1.end(), [](int x) { return x > 0; });
        int c2 = std::count_if(H2.begin(), H2.end(), [](int x) { return x > 0; });
        if (c1 == c2 && c1 == 0) {
            return {0, 0, 1};
        }
        if (c1 == 0) {
            return {0, 1, 0};
        }
        if (c2 == 0) {
            return {1, 0, 0};
        }

        node res;
        if (first) {
            int i = -1;
            for (int j = 0; j < n; j++) {
                if (H1[j] > 0 && (i == -1 || cnt1[i] > cnt1[j])) {
                    i = j;
                }
            }
            cnt1[i]++;
            for (int j = 0; j < m; j++) {
                if (H2[j] > 0) {
                    int backH1 = H1[i];
                    int backH2 = H2[j];

                    H1[i] -= A2[j];
                    H2[j] -= A1[i];
                    res += dfs(dfs, !first) * (1.0 / c2);

                    H1[i] = backH1;
                    H2[j] = backH2;
                }
            }
            cnt1[i]--;
        } else {
            int i = -1;
            for (int j = 0; j < m; j++) {
                if (H2[j] > 0 && (i == -1 || cnt2[i] > cnt2[j])) {
                    i = j;
                }
            }
            cnt2[i]++;
            for (int j = 0; j < n; j++) {
                if (H1[j] > 0) {
                    int backH1 = H1[j];
                    int backH2 = H2[i];

                    H1[j] -= A2[i];
                    H2[i] -= A1[j];
                    res += dfs(dfs, !first) * (1.0 / c1);

                    H1[j] = backH1;
                    H2[i] = backH2;
                }
            }
            cnt2[i]--;
        }
        return res;
    };

    node res;
    if (n > m) {
        res = dfs(dfs, true);
    } else if (n < m) {
        res = dfs(dfs, false);
    } else {
        res = (dfs(dfs, true) + dfs(dfs, false)) * 0.5;
    }
    std::cout << std::fixed << std::setprecision(15);
    std::cout << res.a << "\n" << res.b << "\n" << res.c << "\n";

    return 0;
}
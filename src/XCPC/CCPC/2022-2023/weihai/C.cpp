#include <bits/stdc++.h>

using i64 = long long;

std::pair<int, int> pgcd(int x, int y) {
    int g = abs(std::gcd(x, y));
    return {x / g, y / g};
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        auto& [xi, yi] = p[i];
        std::cin >> xi >> yi;
    }

    {
        if (n < 5) {
            std::cout << "NO\n";
            return;
        }
        std::set<std::pair<int, int>> S;
        for (int i = 1; i < n; i++) {
            auto [x0, y0] = p[0];
            auto [xi, yi] = p[i];
            auto dx = xi - x0, dy = yi - y0;
            if (dx < 0) dx = -dx, dy = -dy;
            S.insert(pgcd(dx, dy));
        }
        if (S.size() == 1) {
            std::cout << "NO\n";
            return;
        }
    }

    std::vector<int> v = {0, 1, 2, 3};

    for (int i = 4; i < n; i++) {
        std::set<std::pair<int, int>> S;
        for (int j = 0; j < 4; j++) {
            auto [xi, yi] = p[i];
            auto [xj, yj] = p[j];
            auto dx = xj - xi, dy = yj - yi;
            if (dx < 0) dx = -dx, dy = -dy;
            S.insert(pgcd(dx, dy));
        }
        if (S.size() > 1) {
            v.push_back(i);
            break;
        }
    }

    for (int i = 0; i < 5; i++) {
        std::set<std::pair<int, int>> st;
        auto [xi, yi] = p[v[i]];
        for (int j = 0; j < 5; j++) {
            if (v[i] == v[j]) {
                continue;
            }
            auto [xj, yj] = p[v[j]];
            auto dx = xj - xi, dy = yj - yi;
            st.insert(pgcd(dx, dy));
        }
        if (st.size() == 4) {
            std::cout << "YES\n";
            std::cout << xi << " " << yi << "\n";
            for (int j = 0; j < 5; j++) {
                if (v[i] == v[j]) {
                    continue;
                }
                auto [xj, yj] = p[v[j]];
                std::cout << xj << " " << yj << "\n";
            }
            break;
        }
    }
}

int main() {
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

std::pair<int, int> pgcd(int x, int y) {
    int g = abs(gcd(x, y));
    return {x / g, y / g};
}

const int N = 25010;
std::vector<std::pair<int, int>> p(N);
int n;

bool valid_permutation(vector<int>& v) {
    set<pair<int, int>> S;
    for (int i = 1; i < 5; i++) {
        auto [x0, y0] = p[v[0]];
        auto [xi, yi] = p[v[i]];
        auto dx = xi - x0, dy = yi - y0;
        S.insert(pgcd(dx, dy));
    }
    if (S.size() == 4) return true;
    return false;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        auto& [xi, yi] = p[i];
        cin >> xi >> yi;
    }

    {
        if (n < 5) {
            cout << "NO\n";
            return;
        }
        set<pair<int, int>> S;
        for (int i = 1; i < n; i++) {
            auto [x0, y0] = p[0];
            auto [xi, yi] = p[i];
            auto dx = xi - x0, dy = yi - y0;
            if (dx < 0) dx = -dx, dy = -dy;
            S.insert(pgcd(dx, dy));
        }
        if (S.size() == 1) {
            cout << "NO\n";
            return;
        }
    }
    
    vector<int> v = {0, 1, 2, 3};
    
    for (int i = 4; i < n; i++) {
        set<pair<int, int>> S;
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
    
    while (next_permutation(v.begin(), v.end())) {
        if (valid_permutation(v)) {
            cout << "YES\n";
            for (auto i : v) {
                auto [xi, yi] = p[i];
                cout << xi << ' ' << yi << '\n';
            }
            return;
        }
    }
}

signed main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
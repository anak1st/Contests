#include <bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n), c(m);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    for(int i = 0; i < m; i++) {
        std::cin >> c[i];
    }

    std::map<int, std::queue<int>> f;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            f[b[i]].push(i);
        }
    }

    // for(auto [x, y] : f) {
    //     std::cerr << x << ' ' << y.size() << '\n';
    // }
    std::vector<int> ans(m);
    bool flag = true;
    if(f[c[m - 1]].size() > 0) {
        ans[m - 1] = f[c[m - 1]].front();
        f[c[m - 1]].pop();
        flag = false;
    } else {
        for(int i = 0; i < n; i++) {
            if(c[m - 1] == b[i]) {
                ans[m - 1] = i;
                flag = false;
                break;
            }
        }
    }
    if(flag) {
        std::cout << "NO\n";
        return;
    }

    for(int i = m - 2; i >= 0; i--) {
        if(!f[c[i]].empty()) {
            ans[i] = f[c[i]].front();
            f[c[i]].pop();
        } else {
            ans[i] = ans[i + 1];
        }
    }
    for(auto [x, y] : f) {
        if(!y.empty()) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
    for(int i = 0; i < m; i++) {
        std::cout << ans[i] + 1 << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
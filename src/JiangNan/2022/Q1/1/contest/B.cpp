#include <bits/stdc++.h>

int find(int x, std::vector<int> &f) {
    if(f[x] != x) {
        f[x] = find(f[x], f);
    }
    return f[x];
}

void unity(int x, int y, std::vector<int> &f) {
    int fx = find(x, f);
    int fy = find(y, f);
    f[fx] = fy;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> c(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> c[i];
    }

    std::vector<int> f(n + 1);
    for(int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int l, r;
        std::cin >> l >> r;
        unity(l, r, f);
    }
    std::map<int, std::map<int, int>> s;
    for(int i = 1; i <= n; i++) {
        s[find(i, f)][c[i]]++;
    }

    int ans = n;
    for(auto i : s) {
        int mx = 0;
        for(auto j : i.second) {
            mx = std::max(mx, j.second);
        }
        ans -= mx;
    }

    std::cout << ans << '\n';
    return 0;
}
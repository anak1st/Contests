/**
 * @author: XiaFan
 * @date: 2023-01-18 10:10
 **/
#include <bits/stdc++.h>
#include <debug/vector>
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n + 1, std::vector<int>(n + 1, 0));
    bool ok = true;
    int nx = 0, ny = 0;
    __gnu_debug::vector<bool> vis(n * n + 1, false);
    while (m--) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y, z;
            std::cin >> x >> y >> z;
            a[x][y] = z;
            vis[z] = true;
        } else {
            if (nx != 0) {
                ok = false;
            }
            std::cin >> nx >> ny;
        }
    }

    if (ok && nx != 0) {
        int z = 1, w = 0;
        for (int i = 1; i <= n; i++) {
            if (i == ny) {
                continue;
            }
            while (z < n * n && vis[z]) z++;
            if (a[nx][i] == 0 && z <= n * n) {
                vis[z] = true;
                a[nx][i] = z;
            }
            w = std::max(w, a[nx][i]);
        }
        if (a[nx][ny] == 0) {
            int z = w + 1;
            while (z < n * n && vis[z]) z++;
            if (z <= n * n) {
                vis[z] = true;
                a[nx][ny] = z;
            }
        }
    }

    if (ok && ny != 0) {
        int z = a[nx][ny] + 1;
        for (int i = 1; i <= n; i++) {
            if (i == nx) {
                continue;
            }
            while (z < n * n && vis[z]) z++;
            if (a[i][ny] == 0 && z <= n * n) {
                vis[z] = true;
                a[i][ny] = z;
            }
        }
    }

    int z = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            while (z < n * n && vis[z]) z++;
            if (a[i][j] == 0) {
                vis[z] = true;
                a[i][j] = z;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[nx][i] > a[nx][ny]) {
            ok = false;
        }
        if (a[i][ny] < a[nx][ny]) {
            ok = false;
        }
    }
    int allcount = std::count(vis.begin() + 1, vis.end(), true);
    if (!ok || allcount != n * n) {
        a = std::vector(n + 1, std::vector<int>(n + 1, 0));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << a[i][j] << " \n"[j == n];
        }
    }
    // std::cout << "\n";
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
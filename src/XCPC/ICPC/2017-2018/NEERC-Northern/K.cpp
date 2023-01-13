/**
 * @author: XiaFan
 * @date: 2023-01-09 20:16
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    freopen("kotlin.in", "r", stdin);
    freopen("kotlin.out", "w", stdout);

    int h, w, n;
    std::cin >> h >> w >> n;
    std::vector a(h, std::vector<char>(w, '.'));

    int x = -1, y = -1;
    for (int i = 0; i <= (h - 1) / 2; i++) {
        for (int j = 0; j <= (w - 1) / 2; j++) {
            if ((i + 1) * (j + 1) == n) {
                x = i;
                y = j;
                break;
            }
        }
    }
    if (x == -1) {
        std::cout << "Impossible";
        return 0;
    }

    for (int i = 0; i < h; i++) {
        if (i % 2 == 0 || x <= 0) continue;
        x--;
        for (int j = 0; j < w; j++) {
            a[i][j] = '#';
        }
    }
    for (int j = 0; j < w; j++) {
        if (j % 2 == 0 || y <= 0) continue;
        y--;
        for (int i = 0; i < h; i++) {
            a[i][j] = '#';
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cout << a[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
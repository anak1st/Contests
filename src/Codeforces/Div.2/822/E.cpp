/**
 * @author: XiaFan
 * @date: 09-26 20:27
 **/
#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> b[i];
    }
    std::vector<int> d(n + 1);
    std::iota(d.begin(), d.end(), 0);
    std::random_shuffle(d.begin() + 1, d.end());
    std::vector a(n + 1, std::vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = b[i] + (i - j + n) % n * d[i];
            a[i][j] %= n;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << "\n";
    }  
    
    return 0;
}
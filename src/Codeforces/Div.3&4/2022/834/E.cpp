/**
 * @author: XiaFan
 * @date: 11-19 09:32
 **/
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    for (auto it : v) {
        os << it << " ";
    }
    return os;
}

template<typename T>
void print(const T& val) {
    std::cerr << val << "\n";
}

template<typename T, typename... Args>
void print(const T& val, const Args&... args) {
    std::cerr << val << " ";
    print(args...);
}

// 2 = 2
// 3 = 3
// 4 = 2 * 2
// 6 = 2 * 3
// 12 = 2 * 2 * 3

void solve() {
    int n, h;
    std::cin >> n >> h;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    int ans = 0;

    std::function<void (int, i64, int, int)> 
    dfs = [&](int i, i64 sum, int green, int blue) {
        ans = std::max(ans, i);
        // print(i, sum, green, blue);
        if (i == n) {
            return;
        }

        if (sum > a[i]) {
            dfs(i + 1, sum + a[i] / 2, green, blue);
            return;
        }

        if ((green == 0 && blue == 0) || sum * 12 <= a[i]) {
            return;
        }

        if (sum * 12 > a[i] && sum * 6 <= a[i]) {
            if (green >= 2 && blue >= 1) {
                dfs(i + 1, sum * 12 + a[i] / 2, green - 2, blue - 1);
            }
            return;
        }
        
        if (sum * 6 > a[i] && sum * 4 <= a[i]) {
            if (green >= 1 && blue >= 1) {
                dfs(i + 1, sum * 6 + a[i] / 2, green - 1, blue - 1);
            }
            return;
        }

        // 6 ? 4
        if (sum * 4 > a[i] && sum * 3 <= a[i]) {
            if (green >= 2) {
                dfs(i + 1, sum * 4 + a[i] / 2, green - 2, blue);
            }
            if (blue >= 1 && green >= 1) {
                dfs(i + 1, sum * 6 + a[i] / 2, green - 1, blue - 1);
            }
        }

        // 4 ? 3
        if (sum * 3 > a[i] && sum * 2 <= a[i]) {
            if (blue >= 1) {
                dfs(i + 1, sum * 3 + a[i] / 2, green, blue - 1);
            }
            if (green >= 2) {
                dfs(i + 1, sum * 4 + a[i] / 2, green - 2, blue);
            }
        }

        // 2 ? 3
        if (sum * 2 > a[i]) {
            if (green >= 1) {
                dfs(i + 1, sum * 2 + a[i] / 2, green - 1, blue);
            }
            if (blue >= 1) {
                dfs(i + 1, sum * 3 + a[i] / 2, green, blue - 1);
            }
        }
    };

    dfs(0, h, 2, 1);

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}
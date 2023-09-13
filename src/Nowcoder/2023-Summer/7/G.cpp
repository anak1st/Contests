/**
 * @author: XiaFan
 * @date: 2023-08-07 15:41
 */
#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 N = 1e12;

std::vector<i64> work(i64 x, std::vector<i64> a) {
    int n = a.size();
    std::vector<i64> b(n);
    b[0] = x;
    for (int i = 1; i < n; i++) {\
        a[i - 1] -= b[i - 1];
        a[i] -= b[i - 1];
        b[i] = a[i];
    }
    
    // std::cerr << "bb ";
    // for (int i = 0; i < n; i++) {
    //     std::cerr << b[i] << " \n"[i == n - 1];
    // }
    return b;
}


std::vector<i64> make(std::vector<i64> a, std::vector<i64> b) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i] -= (b[(n + i - 1) % n] + b[i]);
    }
    
    // std::cerr << "ta ";
    // for (int i = 0; i < n; i++) {
    //     std::cerr << a[i] << " \n"[i == n - 1];
    // }
    return a;
}


bool check(std::vector<i64> a) {
    int n = a.size();
    // for (int i = 0; i < n; i++) {
    //     std::cerr << a[i] << " \n"[i == n - 1];
    // }

    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    if (sum % 2) {
        return false;
    }

    std::vector<i64> b, ta;

    if (n % 2 == 0) {
        b = work(0, a);
        i64 min = N;
        for (int i = 0; i < n; i += 2) {
            min = std::min(min, b[i]);
        }
        if (min < 0) {
            b = work(-min, a);
        }
        ta = make(a, b);
    } else {
        i64 l = 0, r = N;
        while (l <= r) {
            i64 mid = (l + r) / 2;
            b = work(mid, a);
            ta = make(a, b);
            if (ta[0] == 0) {
                break;
            } else if (ta[0] > 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    bool j1 = std::count(ta.begin(), ta.end(), 0) == n;
    bool j2 = (*std::min_element(b.begin(), b.end())) >= 0;
    
    if (j1 && j2) {
        return true;
    } else {
        return false;
    }
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    if (k > n / 2) {
        if (std::count(a.begin(), a.end(), 0) == n) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
        return;
    }

    std::vector<bool> vis(n);
    std::vector<std::vector<i64>> A;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        std::vector<i64> tmp;
        int j = i;
        while (!vis[j]) {
            vis[j] = true;
            tmp.push_back(a[j]);
            j = (j + k) % n;
        }
        
        if (!tmp.empty())
            A.push_back(tmp);
    }

    for (auto &v : A) {
        if (!check(v)) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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
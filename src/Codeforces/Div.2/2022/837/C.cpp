/**
 * @author: XiaFan
 * @date: 12-12 00:07
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve(std::vector<int> &primes) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (auto d : primes) {
            if (d * d > x) {
                break;
            }
            if (x % d == 0) {
                mp[d]++;
                if (mp[d] >= 2) {
                    std::cout << "YES\n";
                    return;
                }
                while (x % d == 0) {
                    x /= d;
                }
            }
        }
        if (x > 1) {
            mp[x]++;
            if (mp[x] >= 2) {
                std::cout << "YES\n";
                return;
            }
        }
    }

    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int PRE = 1e5;
    std::vector<int> primes;
    primes.push_back(2);

    for (int x = 3; x < PRE; x += 2) {
        bool flag = true;
        int s = std::sqrt(x);
        for (int i = 0; i < (int)primes.size() && primes[i] <= s; i++) {
            if (x % primes[i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            primes.push_back(x);
        }
    }

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve(primes);
    }

    return 0;
}
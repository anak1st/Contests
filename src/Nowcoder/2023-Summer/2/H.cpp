/**
 * @author: XiaFan
 * @date: 2023-07-21 16:10
 */
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}

template <typename T>
T power(T a, i64 b, i64 mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) res = (res * a) % mod;
    }
    return res;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;

    std::vector<int> k(n + 1), b(n + 1);
    k[0] = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            k[i + 1] = -k[i];
            b[i + 1] = -b[i] - 1;
        } else {
            k[i + 1] = k[i];
            b[i + 1] = b[i] + 1;
        }
    }

    i64 ans = 0;

    while (q--) {
        int l, r;
        std::string X;
        std::cin >> l >> r >> X;
        
        int siz = X.length();
        i64 bit = 1LL << siz;
        i64 x = std::bitset<64>(X).to_ullong();
        
        l = (l ^ ans) % n + 1;
        r = (r ^ ans) % n + 1;
        if (l > r) {
            std::swap(l, r);
        }

        l--;
        
        x -= b[l];
        x *= k[l];
        x *= k[r];
        x += b[r];
        x &= bit - 1;
        
        ans = x;
        std::cout << std::bitset<64>(ans)
                        .to_string()
                        .substr(64 - siz) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
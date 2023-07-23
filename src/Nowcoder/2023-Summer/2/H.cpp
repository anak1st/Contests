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

    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] + (s[i] == 'A');
        b[i + 1] = b[i] + (s[i] == 'B');
    }

    int ans = 0;

    while (q--) {
        int l, r;
        std::string X;
        std::cin >> l >> r >> X;
        int siz = X.length();
        i64 bit = 1 << siz;
        i64 x = std::bitset<64>(X).to_ullong();
        
        l = std::min((ans ^ l) % n + 1, (ans ^ r) % n + 1);
        r = std::max((ans ^ l) % n + 1, (ans ^ r) % n + 1);
        std::cerr << l << ' ' << r << ' ';
        i64 A = a[r] - a[l - 1];
        i64 B = b[r] - b[l - 1];
        std::cerr << A << ' ' << B << '\n';

        x -= A;
        x = (x % bit + bit) % bit;
        x *= A % 2 ? -1 : 1;
        x = (x % bit + bit) % bit;
        x += B;
        x = (x % bit + bit) % bit;
        ans = x;
        std::cout << std::bitset<64>(ans).to_string().substr(64 - siz) << '\n';
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
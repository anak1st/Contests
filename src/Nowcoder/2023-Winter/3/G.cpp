/**
 * @author: XiaFan
 * @date: 2023-01-20 15:19
 **/
#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;

template <typename T> T power(T a, i128 b, T mod) {
    T res = 1;
    a %= mod;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res * a) % mod;
        }
    }
    return res;
}

i128 fun(i128 x, i128 t, char c) {
    if (c == '+') {
        return x + t;
    } else if (c == '-') {
        return x - t;
    } else if (c == '#') {
        return power<i128>(x, x, t);
    } else {
        return t;
    }
}

std::string ops = "+-#";

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int cnt = 0;

    std::function<void (int, i128, i128, char)> 
    dfs = [&](int i, i128 t, i128 x, char op) {
        if (i == (int)s.size()) {
            cnt++;
            // std::cerr << "judge " << s << " " << x << "\n";
            if (x == t) {
                std::cout << s << "\n";
                exit(0);
            }
            return;
        }
        if (isdigit(s[i])) {
            dfs(i + 1, t * 10 + s[i] - '0', x, op);
        } else if (s[i] == '=') {
            if (op == '#' && (x <= 0 || t <= 0)) {
                // std::cerr << "error " << s << "\n";
                return;
            }
            dfs(i + 1, 0, fun(x, t, op), s[i]);
        } else if (s[i] == '?') {
            if (op == '#' && (x <= 0 || t <= 0)) {
                // std::cerr << "error " << s << "\n";
                return;
            }
            for (char c : ops) {
            s[i] = c;
            dfs(i + 1, 0, fun(x, t, op), s[i]);
            s[i] = '?';
            }
        } else {
            if (op == '#' && (x <= 0 || t <= 0)) {
                // std::cerr << "error " << s << "\n";
                return;
            }
            dfs(i + 1, 0, fun(x, t, op), s[i]);
        }
    };

    dfs(0, 0, 0, '+');
    // std::cerr << "cnt " << cnt << "\n";
    std::cout << "-1";

    return 0;
}
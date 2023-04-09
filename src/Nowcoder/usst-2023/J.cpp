/**
 * @author: XiaFan
 * @date: 2023-03-11 21:01
 **/
#include <bits/stdc++.h>
using i64 = long long;

int fun(std::string s) {
    int n = s.length();
    if (n == 1) {
        return 1;
    }
    int res = fun(s.substr(0, n - 1)) + 1;
    for (int i = 0; i < n / 2; i++) {
        int len = i + 1;
        std::string pref = s.substr(0, len);
        std::string suff = s.substr(n - len, len);
        if (pref == suff) {
            // std::cerr << s << " " << pref << " " << s.substr(0, n - len) << "\n";
            res = std::min(res, fun(s.substr(0, n - len)) + 1);
        }
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::cout << fun(s) << "\n";
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
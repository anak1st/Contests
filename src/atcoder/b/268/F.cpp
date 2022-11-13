/**
 * @author: XiaFan
 * @date: 09-13 18:49
 **/
#include <bits/stdc++.h>
using i64 = long long;

i64 fun(std::string s) {
    i64 x = std::count(s.begin(), s.end(), 'X');
    i64 res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == 'X') {
            x--;
        } else {
            res += x * (s[i] - '0');
        }
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (auto &si : s) {
        std::cin >> si;
    }

    std::sort(s.begin(), s.end(), [](std::string a, std::string b) -> bool {
        return fun(a + b) > fun(b + a);
    });

    std::string t = "";
    for (int i = 0; i < n; i++) {
        t += s[i];
    }
    std::cout << fun(t) << "\n";
    
    return 0;
}
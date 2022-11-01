/**
 * @author: XiaFan
 * @date: 10-31 19:15
 **/
#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128_t;

std::istream &operator>>(std::istream &is, i128 &x) {
    std::string s;
    is >> s;

    bool flag = false;
    if (s.front() == '-') {
        s = s.substr(1);
        flag = true;
    }
    x = 0;
    for (auto c : s) {
        x = 10 * x + (c - '0');
    }
    if (flag) {
        x = -x;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, i128 x) {
    if (x == 0) {
        os << '0';
    } else {
        std::string s;
        while (x) {
            s.push_back('0' + x % 10);
            x /= 10;
        }
        std::reverse(s.begin(), s.end());
        os << s;
    }
    return os;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i128 n;
    std::cin >> n;
    std::cout << n;
    
    return 0;
}
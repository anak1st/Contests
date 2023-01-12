#pragma once
#include "XCPC.h"

using i128 = __int128;
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
        if (x < 0) {
            os << '-';
            x = -x;
        }
        std::string s;
        for (; x; x /= 10) {
            s.push_back('0' + x % 10);
        }
        std::reverse(s.begin(), s.end());
        os << s;
    }
    return os;
}
i128 i128_gcd(i128 a, i128 b) {
    if (b == 0) {
        return a;
    } else {
        return i128_gcd(b, a % b);
    }
}
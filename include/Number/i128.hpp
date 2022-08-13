#pragma once

#include <algorithm>
#include <iostream>

using i128 = __int128;

std::istream &operator>>(std::istream &is, i128 &x) {
    x = 0;
    std::string s;
    is >> s;
    for (auto c : s) {
        x = 10 * x + (c - '0');
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

i128 i128_gcd(i128 a, i128 b) {
    return b ? i128_gcd(b, a % b) : a;
}

/**
 * @author: XiaFan
 * @date: 2023-08-04 13:14
 */
#include <bits/stdc++.h>

// using i64 = long long;
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

i128 trailing_zeros(i128 n) {
    // write your code here
    i128 count = 0;
    i128 temp = n / 5;
    while (temp) {
        count += temp;
        temp /= 5;
    }
    return count;
}

// return sum_{i = 0}^{n - 1} (a0 + i * d) // div
i128 seq_div_sum(i128 a0, i128 d, i128 n, i128 div) {
    if (n <= 0) return 0;
    if (n == 1) return (a0 / div);
    i128 tmp = 0;
    tmp += (d / div) * (n - 1) * n / 2;
    tmp += (a0 / div) * n;
    d = d % div;
    a0 = a0 % div;
    if (d == 0) {
        return tmp;
    } else {
        return tmp + seq_div_sum((d * n + a0) % div, div, (d * n + a0) / div, d);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i128 n;
    std::cin >> n;
    
    i128 x = 0, tmp = 5;
    while (tmp <= n) {
        x += seq_div_sum(2, 2, n / 2, tmp);
        // std::cerr << tmp << " " << get(1, 1, tmp, n / 2) << '\n';
        tmp *= 5;
    }

    i128 y = 0;
    if (n % 2) {
        i128 temp = n / 5;
        while (temp) {
            y += (temp + 1) / 2;
            temp /= 5;
        }
    }
    x += y;

    std::cout << x << '\n';

    return 0;
}
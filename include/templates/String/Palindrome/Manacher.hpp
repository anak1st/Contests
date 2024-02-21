#pragma once
#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> __Manacher(const std::string &s) {
    int n = s.length();
    std::vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    return d1;
}

std::vector<int> Manacher(const std::string &s) {
    int n = s.length();
    std::string ss = "#";
    for (int i = 0; i < n; i++) {
        ss += s[i];
        ss += '#';
    }

    std::vector<int> d1 = __Manacher(ss);
    std::vector<int> d;
    for (int i = 0; i < n; i++) {
        d.push_back(d1[i * 2 + 1] - 1);
    }

    return d1;
}
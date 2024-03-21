#pragma once
#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> get_next(std::string &s) {
    int n = s.size();
    std::vector<int> next(n + 1, 0);
    next[0] = -1;
    for (int i = 0, j = -1; i < n;) {
        if (j == -1 || s[i] == s[j]) {
            i++, j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    return next; // size (n+1)
}
// Knuth-Morris-Pratt
int KMP(std::string s, std::string t) {
    int ns = s.length();
    int nt = t.length();
    auto next = get_next(t);
    for (int i = 0, j = 0; i < ns; i++) {
        while (j > 0 && s[i] != t[j]) {
            j = next[j];
        }
        if (s[i] == t[j]) {
            j++;
        }
        if (j == nt) {
            // success !!!
            // return i;
            j = next[j];
        }
    }
    return -1;
}
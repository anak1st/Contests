#pragma once
#include "XCPC.h"

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
    for (int i = 0, j = 0; j < ns; j++) {
        while (i > 0 && s[j] != t[i]) {
            i = next[i];
        }
        if (s[j] == t[i]) {
            i++;
        }
        if (i == nt) {
            // success !!!
            // return i;
            i = next[i];
        }
    }
    return -1;
}
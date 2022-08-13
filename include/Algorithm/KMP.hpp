#pragma once

#include <iostream>
#include <string>
#include <vector>

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
    return next;  // size (n+1)
}

void KMP() {
    std::string a, b;
    std::cin >> a >> b;
    int na = a.length();
    int nb = b.length();
    auto next = get_next(a);
    for (int i = 0, j = 0; j < nb; j++) {
        while (i > 0 && b[j] != a[i]) {
            i = next[i];
        }
        if (b[j] == a[i]) {
            i++;
        }
        if (i == na) {
            // success !!!
            i = next[i];
        }
    }
    return;
}

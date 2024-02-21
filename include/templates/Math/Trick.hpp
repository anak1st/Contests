#pragma once
#include <bits/stdc++.h>

using i64 = long long;


void subset(int x) {
    for (int i = x; ; i = (i - 1) & x) {
        // do something
        if (!i) break;
    }
}


// return sum_{i = 0}^{n - 1} (a0 + i * d) // div
template <typename T> 
T seq_div_sum(T a0, T d, T n, T div) {
    if (n <= 0) return 0;
    if (n == 1) return (a0 / div);
    T tmp = 0;
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

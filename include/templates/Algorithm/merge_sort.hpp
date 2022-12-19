#pragma once

#include <vector>

using i64 = long long;

namespace detail {
template <typename T>
i64 merge(std::vector<T> &a, std::vector<T> &b, int l, int r) {
    int m = (l + r) / 2;
    int i = l, j = m + 1, k = l;
    i64 res = 0;
    while (i <= m && j <= r) {
        res++;
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            // res += (j - k);
            b[k++] = a[j++];
        }
    }
    while (i <= m) {
        b[k++] = a[i++];
    }
    while (j <= r) {
        b[k++] = a[j++];
    }
    std::copy(b.begin() + l, b.begin() + r + 1, a.begin() + l);
    for (int i = l; i <= r; i++) {
        a[i] = b[i];
    }
    return res;
}

template <typename T>
i64 merge_sort(std::vector<T> &a, std::vector<T> &b, int l, int r) {
    i64 res = 0;
    if (l < r) {
        int m = (l + r) / 2;
        res += merge_sort<T>(a, b, l, m);
        res += merge_sort<T>(a, b, m + 1, r);
        res += merge<T>(a, b, l, r);
    }
    return res;
}
}  // namespace detail
template <typename T>
i64 merge_sort(std::vector<T> &a) {
    std::vector<T> b(a);
    return detail::merge_sort<T>(a, b, 0, (int)a.size() - 1);
}
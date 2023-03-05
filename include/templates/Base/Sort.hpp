#pragma once
#include "XCPC.h"

// ===== Quick Sort =====
template <typename T> void quick_sort(std::vector<T> &a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r;
    T x = a[l];
    while (i < j) {
        while (i < j && a[j] >= x) {
            j--;
        }
        a[i] = a[j];
        while (i < j && a[i] <= x) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = x;
    quick_sort(a, l, i - 1);
    quick_sort(a, i + 1, r);
}
template <typename T> void quick_sort(std::vector<T> &a) {
    quick_sort(a, 0, (int)a.size() - 1);
}

// ===== Merge Sort =====
// if modified, test it in Luogu P1908
// https://www.luogu.com.cn/problem/P1908
template <typename T> i64 merge(std::vector<T> &a, std::vector<T> &b, int l, int r) {
    int m = (l + r) / 2;
    int i = l, j = m + 1, k = l;
    i64 res = 0;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            res += (j - k);
            b[k++] = a[j++];
        }
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    std::copy(b.begin() + l, b.begin() + r + 1, a.begin() + l);
    return res;
}
template <typename T> i64 merge_sort(std::vector<T> &a, std::vector<T> &b, int l, int r) {
    i64 res = 0;
    if (l < r) {
        int m = (l + r) / 2;
        res += merge_sort<T>(a, b, l, m);
        res += merge_sort<T>(a, b, m + 1, r);
        res += merge<T>(a, b, l, r);
    }
    return res;
}
template <typename T> i64 merge_sort(std::vector<T> &a) {
    std::vector<T> b(a);
    return merge_sort<T>(a, b, 0, (int)a.size() - 1);
}

#pragma once
#include <bits/stdc++.h>

using i64 = long long;
#include "templates/Math/Number/Mint.hpp"

constexpr i64 P = 1e9 + 7;
using Mint = MintBase<P>;
struct Comb {
    int n;
    std::vector<Mint> facs, invfacs, invs;
    Comb(int n = 1000) : n{0}, facs{1}, invfacs{1}, invs{0} { init(n); }
    void init(int m) {
        if (m <= n) return;
        facs.resize(m + 1);
        invfacs.resize(m + 1);
        invs.resize(m + 1);

        for (int i = n + 1; i <= m; i++) {
            facs[i] = facs[i - 1] * i;
        }
        invfacs[m] = facs[m].inv();
        for (int i = m; i > n; i--) {
            invfacs[i - 1] = invfacs[i] * i;
            invs[i] = invfacs[i] * facs[i - 1];
        }
        n = m;
    }
    Mint fac(int m) {
        if (m > n) init(2 * m);
        return facs[m];
    }
    Mint invfac(int m) {
        if (m > n) init(2 * m);
        return invfacs[m];
    }
    Mint inv(int m) {
        if (m > n) init(2 * m);
        return invs[m];
    }
    Mint A(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(n - m);
    }
    Mint C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }

    // Lucas 定理，当 a, b > P 时候使用
    Mint lucas(int a, int b) {
        if (a < P && b < P) {
            return C(a, b);
        }
        return C(a % P, b % P) * lucas(a / P, b / P);
    }

    // 第二类斯特林数 S(n, k) 表示将 n 个不同元素构成k个非空子集的方法数
    Mint stirling2(int n, int k) {
        Mint ret = 0;
        for (int i = 0; i <= k; i++) {
            Mint tmp = C(k, i) * power(Mint(i), n);
            ret += ((k - i) & 1) ? -tmp : tmp;
        }
        return ret * invfac(k);
    }
    
    // 贝尔数是基数为 n 的集合的划分方法的数目
    Mint bell(int n, int k) {
        if (n == 0)
            return 1;
        k = std::min(k, n);
        std::vector<Mint> pref(k + 1);
        pref[0] = 1;
        for (int i = 1; i <= k; i++) {
            if (i & 1)
                pref[i] = pref[i - 1] - invfac(i);
            else
                pref[i] = pref[i - 1] + invfac(i);
        }
        Mint ret = 0;
        for (int i = 1; i <= k; i++)
            ret += power(Mint(i), n) * invfac(i) * pref[k - i];
        return ret;
    }

    
};
Comb comb;

#include "templates/DataStructure/Fenwick.hpp"

// 康托展开可以用来求一个 1 ~ n 的任意排列的排名。
// 把 1 ~ n 的所有排列按字典序排序，这个排列的位次就是它的排名。
Mint cantor(const std::vector<int> &P, int n) {
    Mint ans = 0;
    std::vector<int> A(n);
    Fenwick<int> F(n);
    for (int i = n - 1; i >= 0; i--)
    {
        A[i] = F.sum(P[i]);
        F.add(P[i], 1);
    }
    for (int i = 0; i < n; i++)
        ans += A[i] * comb.fac(n - i - 1);
    return ans;
}

std::pair<Mint, Mint> fib(int n) {
    if (n == 0) return {0, 1};
    auto p = fib(n / 2);
    Mint c = p.first * (2 * p.second - p.first);
    Mint d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
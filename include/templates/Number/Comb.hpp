#pragma once
#include "XCPC.h"
#include "templates/Number/Mint.hpp"

constexpr i64 P = 1e9 + 7;
using Mint = MintBase<P>;
struct Comb {
    int n;
    std::vector<Mint> facs, invfacs, invs; 
    Comb(int n = 1000) : n{0}, facs{1}, invfacs{1}, invs{0} {
        init(n);
    }
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
        return fac(n) * invfac(m);
    }
    Mint C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;
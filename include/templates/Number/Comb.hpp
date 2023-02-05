#pragma once
#include "XCPC.h"
#include "templates/Number/Mint.hpp"

using Mint = MintBase<0>;
struct Comb {
    int n;
    std::vector<Mint> _fac, _invfac, _inv; 
    Comb(int n = 1000) : n{0}, _fac{1}, _invfac{1}, _inv{0} {
        init(n);
    }
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    Mint fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Mint invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Mint inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Mint A(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m);
    }
    Mint C(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
};
Comb comb;
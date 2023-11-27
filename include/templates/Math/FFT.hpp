#pragma once
#include "XCPC.h"

constexpr double Pi = std::numbers::pi;
using Complex = std::complex<double>;

std::vector<Complex> fft(std::vector<Complex> &a, int f) {
    int n = a.size();
    if (n == 1) return std::vector<Complex>(1, a[0]);

    std::vector<Complex> w(n);
    for (int i = 0; i < n; i++) {
        double alpha = -2 * f * Pi * i / n;
        w[i] = Complex(cos(alpha), sin(alpha));
    }

    std::vector<Complex> A0(n / 2), A1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        A0[i] = a[i * 2];
        A1[i] = a[i * 2 + 1];
    }
    std::vector<Complex> y0 = fft(A0, f);
    std::vector<Complex> y1 = fft(A1, f);

    std::vector<Complex> y(n);
    for (int k = 0; k < n / 2; k++) {
        y[k] = y0[k] + w[k] * y1[k];
        y[k + n / 2] = y0[k] - w[k] * y1[k];
    }
    return y;
}

struct Poly {
    std::vector<int> p;
    
    Poly(int x = 0) {
        while (x) {
            p.push_back(x % 10);
            x /= 10;
        }
    }

    Poly(std::string &s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            p.push_back(s[i] - '0');
        }
    }

    std::string to_string() {
        std::string res;
        for (int i = p.size() - 1; i >= 0; i--) {
            res.push_back(p[i] + '0');
        }
        return res;
    }

    int size() const {
        return p.size();
    }

    void resize(int n) {
        p.resize(n);
    }

    friend Poly operator+(const Poly &lhs, const Poly &rhs) {
        Poly res;
        int n = std::max(lhs.size(), rhs.size());
        res.resize(n);
        int carry = 0;
        for (int i = 0; i < n; i++) {
            res.p[i] = carry;
            if (i < lhs.size()) res.p[i] += lhs.p[i];
            if (i < rhs.size()) res.p[i] += rhs.p[i];
            carry = res.p[i] / 10;
            res.p[i] %= 10;
        }
        if (carry) res.p.push_back(carry);

        return res;
    }

    friend Poly operator*(const Poly &lhs, const Poly &rhs) {
        int n = lhs.size() + rhs.size();
        int m = 1;
        while (m < n) m *= 2;
        std::vector<Complex> a(m), b(m);
        for (int i = 0; i < lhs.size(); i++) {
            a[i] = lhs.p[i];
        }
        for (int i = 0; i < rhs.size(); i++) {
            b[i] = rhs.p[i];
        }
        std::vector<Complex> A = fft(a, 1);
        std::vector<Complex> B = fft(b, 1);
        std::vector<Complex> C(m);
        for (int i = 0; i < m; i++) {
            C[i] = A[i] * B[i];
        }
        std::vector<Complex> c = fft(C, -1);
        for (int i = 0; i < m; i++) {
            c[i] /= m;
        }
        Poly res;
        res.resize(m);
        for (int i = 0; i < m; i++) {
            res.p[i] = round(c[i].real());
        }
        for (int i = 0; i < m - 1; i++) {
            res.p[i + 1] += res.p[i] / 10;
            res.p[i] %= 10;
        }
        while (res.size() > 1 && res.p.back() == 0) {
            res.p.pop_back();
        }

        return res;
    }
};
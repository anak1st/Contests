#pragma once

#include <cassert>
#include <vector>

template <typename T>
class Matrix {
private:
    const int H, W;
    std::vector<std::vector<T>> mat;

public:
    using i64 = long long;

    Matrix(const int h, const int w) : H(h), W(w), mat(h, std::vector<T>(w)) {}
    
    Matrix(const int h, const int w, const T val)
        : H(h), W(w), mat(h, std::vector<T>(w)) {
        for (int i = 0; i < std::min(H, W); i++) {
            at(i, i) = val;
        }
    }

    Matrix(const Matrix &M) : H(M.h()), W(M.w()), mat(M.mat) {}

    T get(const int i, const int j) const {
        return mat[i][j];
    }
    T &at(const int i, const int j) {
        return mat[i][j];
    }

    constexpr int h() const {
        return H;
    }
    constexpr int w() const {
        return W;
    }

    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
        Matrix res(lhs);
        assert(lhs.H == rhs.H && lhs.W == rhs.W);
        for (int i = 0; i < lhs.H; i++) {
            for (int j = 0; j < rhs.W; j++) {
                res.at(i, j) += rhs.get(i, j);
            }
        }
        return res;
    }

    friend Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
        Matrix res(lhs.H, rhs.W);
        assert(lhs.W == rhs.H);
        for (int i = 0; i < lhs.H; i++) {
            for (int j = 0; j < rhs.W; j++) {
                for (int k = 0; k < lhs.W; k++) {
                    res.at(i, j) += lhs.get(i, k) * rhs.get(k, j);
                }
            }
        }
        return res;
    }

    Matrix &operator+=(const Matrix &rhs) {
        Matrix lhs = *this;
        *this = lhs + rhs;
        return *this;
    }
    Matrix &operator*=(const Matrix &rhs) {
        Matrix lhs = *this;
        *this = lhs * rhs;
        return *this;
    }

    Matrix mat_power(Matrix<T> a, i64 b) {
        Matrix res(a.h(), a.w(), 1);
        for (; b; b /= 2, a *= a) {
            if (b % 2) {
                res *= a;
            }
        }
        return res;
    }
};

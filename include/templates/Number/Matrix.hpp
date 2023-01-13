#pragma once
#include "XCPC.h"

template <typename T> struct Matrix {
    int H, W;
    std::vector<std::vector<T>> mat;
    Matrix(int h, int w) : H(h), W(w), mat(h, std::vector<T>(w)) {}
    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
        Matrix res(lhs.H, rhs.W);
        assert(lhs.H == rhs.H && lhs.W == rhs.W);
        for (int i = 0; i < lhs.H; i++) {
            for (int j = 0; j < rhs.W; j++) {
                res.mat[i][i] = lhs.mat[i][j] + rhs.mat[i][j];
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
                    res.mat[i][i] += lhs.mat[i][k] * rhs.mat[k][j];
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
    friend std::ostream &operator<<(std::ostream &os, const Matrix &M) {
        for (int i = 0; i < M.H; i++) {
            for (int j = 0; j < M.W; j++) {
                os << M.mat[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }
};

template <typename T> Matrix<T> mat_power(Matrix<T> a, i64 b) {
    assert(a.H == a.W);
    Matrix<T> res(a.H, a.W);
    for (int i = 0; i < a.H; i++) {
        res.mat[i][i] = 1;
    }
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

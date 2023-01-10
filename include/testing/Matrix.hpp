#pragma once
#include "XCPC.h"

template <typename T> struct Matrix {
    const int H, W;
    std::vector<std::vector<T>> mat;
    Matrix(int h, int w) : H(h), W(w), mat(h, std::vector<T>(w)) {}
    Matrix(int h, int w, T val) : H(h), W(w), mat(h, std::vector<T>(w)) {
        for (int i = 0; i < std::min(H, W); i++) {
            mat[i][i] = val;
        }
    }
    Matrix(const Matrix &M) : H(M.H), W(M.W), mat(M.mat) {}
    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
        Matrix res(lhs);
        assert(lhs.H == rhs.H && lhs.W == rhs.W);
        for (int i = 0; i < lhs.H; i++) {
            for (int j = 0; j < rhs.W; j++) {
                res.mat[i][i] += rhs.mat[i][i];
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
                    res.mat[i][i] += lhs.mat[i][k] * rhs.mat[k][i];
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

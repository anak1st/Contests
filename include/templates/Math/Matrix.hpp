#pragma once
#include <bits/stdc++.h>

using i64 = long long;

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

int error = 0;

template <typename T>
std::vector<T> gauss_elimination(std::vector<std::vector<T>> A, std::vector<T> b) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (std::abs(A[j][i]) > std::abs(A[pivot][i])) {
                pivot = j;
            }
        }
        std::swap(A[i], A[pivot]);
        std::swap(b[i], b[pivot]);
        if (std::abs(A[i][i]) < 1e-9) {
            error = 1;
            return {};
        }
        for (int j = i + 1; j < n; j++) {
            T c = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= A[i][k] * c;
            }
            b[j] -= b[i] * c;
        }
    }
    std::vector<T> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    return x;
}

#include <vector>
#include <cassert>

using i64 = long long;

template <typename T>
class Matrix {
private:
    int H, W;
    std::vector<std::vector<T>> mat;

public:
    Matrix(const int h, const int w)
    : H(h), W(w), mat(h, std::vector<T>(w)) 
    {}

    Matrix(const int h, const int w, const T val)
    : H(h), W(w), mat(h, std::vector<T>(w)) 
    {
        for (int i = 0; i < std::min(H, W); i++) {
            mat[i][i] = val;
        }
    }

    T &at(const int i, const int j) {
        return mat[i][j];
    }

    int h() const { return H; }
    int w() const { return W; }

    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
        Matrix res(lhs);
        assert(lhs.H == rhs.H && lhs.W == rhs.W);
        for (int i = 0; i < lhs.H; i++) {
            for (int j = 0; j < rhs.W; j++) {
                res.mat[i][j] = lhs.mat[i][j] + rhs.mat[i][j];
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
                    res.mat[i][j] += lhs.mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        return res;
    }

    Matrix &operator+=(const Matrix &rhs) {
        *this = *this + rhs;
        return *this;
    }
    Matrix &operator*=(const Matrix &rhs) {
        Matrix lhs = *this;
        *this = lhs * rhs;
        return *this;
    }
};

template <typename T>
Matrix<T> mat_power(Matrix<T> a, i64 b) {
    Matrix<T> res(a.h(), a.w(), 1);
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
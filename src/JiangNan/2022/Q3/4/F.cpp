/**
 * @author: XiaFan
 * @date: 10-09 21:43
 **/
#include <bits/stdc++.h>
using i64 = long long;

int P = 1e9 + 7;

int modulo(i64 x) {
    return (x % P + P) % P;
}

template <class T> T fpow(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
private:
    int x;

public:
    Mint() : x(0) {}
    Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 temp;
        a.x = modulo(temp);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.x;
        return os;
    }

    int val() const {
        return x;
    }

    Mint operator-() const {
        return Mint(modulo(-x));
    }

    Mint inv() const {
        assert(x != 0);
        return fpow(*this, P - 2);
    }

    Mint &operator*=(const Mint &rhs) {
        x = modulo(1LL * x * rhs.x);
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        x = modulo(x + rhs.x);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        x = modulo(x - rhs.x);
        return *this;
    }
    Mint &operator/=(const Mint &rhs) {
        *this *= rhs.inv();
        return *this;
    }

    friend Mint operator*(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend Mint operator+(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend Mint operator-(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend Mint operator/(const Mint &lhs, const Mint &rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
};

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

constexpr int init_size = 10000;
int good[init_size];

void init() {
    Matrix<Mint> begin(2, 2, 1);
    Matrix<Mint> mat(2, 2);
    mat.at(0, 1) = 1;
    mat.at(1, 0) = 1;
    mat.at(1, 1) = 1;
    for (int i = 0; i < init_size; i++) {
        good[i] = begin.at(1, 1).val();
        begin *= mat;
    }
}

Mint fun(int x) {
    if (x < 0) {
        return 0;
    }
    if (x < init_size) {
        return good[x];
    }

    Matrix<Mint> mat(2, 2);
    mat.at(0, 1) = 1;
    mat.at(1, 0) = 1;
    mat.at(1, 1) = 1;

    mat = mat_power(mat, x);
    return mat.at(1, 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m + 2);
    std::vector<int> b(m + 2);
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i];
    }
    
    a[0] = -1;
    a[m + 1] = n + 1;
    std::sort(a.begin(), a.end());

    init();

    for (int i = 1; i <= m + 1; i++) {
        b[i] = a[i] - a[i - 1] - 1;
    }

    Mint ans = 1;
    for (int i = 1; i <= m + 1; i++) {
        ans *= fun(b[i] - 1);
        // std::cerr << fun(b[i] - 1) << " \n"[i == m + 1];
    }
    std::cout << ans;

    return 0;
}
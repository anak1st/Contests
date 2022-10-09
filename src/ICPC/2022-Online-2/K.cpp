/**
 * @author: XiaFan
 * @date: 09-26 19:02
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr int P = 998244353;

int modulo(int x) {
    return (x % P + P) % P;
}

template<class T> T fpower(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Mint {
    int x;
    
    Mint() : x(0) {}
    Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    friend std::istream &operator>>(std::istream &is, Mint &a){
        i64 temp;
        a.x = modulo(temp);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a){
        os << a.x;
        return os;
    }
    
    Mint operator-() const {
        return Mint(modulo(-x));
    }
    
    Mint inv() const {
        assert(x != 0);
        return fpower(*this, P - 2);
    }
    
    Mint &operator*=(const Mint &rhs) {
        x = i64(x) * rhs.x % P;
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
        return *this *= rhs.inv();
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    const int N = 105;
    std::vector<std::vector<int>> a(2 * N, std::vector<int>(2 * N, 0));

    // 空白 0
    // 方块 15

    //  3 1 5
    //  2   4
    // 10 8 12

    auto fun = [&](int x, int y, int z) {
        a[x + N][y + N] |= z;
    };

    while (n--) {
        int p, x, y;
        std::cin >> p >> x >> y;
        
        if (p == 1) {
            fun(x, y, 15);
            fun(x, y + 1, 15);
            fun(x + 1, y, 15);
            fun(x + 1, y + 1, 15);
        } else {
            fun(x, y, 5);
            fun(x, y + 1, 12);
            fun(x + 1, y, 3);
            fun(x + 1, y + 1, 10);
        }
    }

    Mint A, B;

    for (int i = N - 102; i <= N + 102; i++) {
        for (int j = N - 102; j <= N + 102; j++) {
            if (a[i][j] == 15) {
                int temp = 4;
                // std::cout << "--- " << i - N << " " << j - N << "\n";
                // std::cout << "r " << (a[i + 1][j] & 2) << "\n";
                // std::cout << "l " << (a[i - 1][j] & 4) << "\n";
                // std::cout << "d " << (a[i][j - 1] & 8) << "\n";
                // std::cout << "t " << (a[i][j + 1] & 1) << "\n";

                if (a[i + 1][j] & 2) {
                    temp -= 1;
                }
                if (a[i - 1][j] & 4) {
                    temp -= 1;
                }
                if (a[i][j - 1] & 1) {
                    temp -= 1;
                }
                if (a[i][j + 1] & 8) {
                    temp -= 1;
                }
                A += temp;
            }

            int count = std::bitset<8>(a[i][j]).count();
            if (count == 2) {
                B += 3;
            } else if (count == 3) {
                B += 2;
            }
        }
    }

    B /= 6;
    std::cout << A << " " << B;
    
    return 0;
}
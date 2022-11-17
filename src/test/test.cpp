/**
 * @author: XiaFan
 * @date: 11-17 18:30
 **/
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> v) {
    for (auto it : v) {
        os << it << " ";
    }
    return os;
}

template<typename T>
void print(const T& val) {
    std::cerr << val << "\n";
}

template<typename T, typename... Args>
void print(const T& val, const Args&... args) {
    std::cerr << val << " ";
    print(args...);
}

template <int P>
struct Mint {
private:
    int v;

public:
    Mint() : v(0) {}
    Mint(int x) : v(modulo(x)) {}
    Mint(i64 x) : v(modulo(x)) {}
    
    int modulo(i64 x) const { 
        return (x % P + P) % P; 
    }

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 x;
        is >> x;
        a.v = a.modulo(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
        os << a.val();
        return os;
    }

    constexpr int val() const { return v; }

    Mint operator-() const { return Mint(modulo(-v)); }

    Mint inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }

    Mint &operator++() { return *this += 1; }
    Mint &operator--() { return *this -= 1; }

    Mint &operator*=(const Mint &rhs) {
        v = modulo(1LL * v * rhs.v);
        return *this;
    }
    Mint &operator+=(const Mint &rhs) {
        v = modulo(v + rhs.v);
        return *this;
    }
    Mint &operator-=(const Mint &rhs) {
        v = modulo(v - rhs.v);
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

using mint = Mint<998244353>;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template <typename T>
T A(int n, int m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans *= a;
    }
    return ans;
}

template <typename T>
T C(int n, int m) {
    if (m > n) return 0;
    T ans = 1;
    for (int i = 1; i <= m; i++) {
        T a = n + i - m;
        ans = ans * a / i;
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<int> a;
    for (int i = 1; i <= n - 1; i++) {
        if (n % i != 0 || i == 1) {
            a.push_back(i);
        }
    }
    std::cout << a.size() << "\n";
    for (int i = 0; i < (int)a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    
    return 0;
}
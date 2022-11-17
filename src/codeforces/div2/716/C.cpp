/**
 * @author: XiaFan
 * @date: 11-17 21:47
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

// constexpr int P = 1e9 + 7;
int P;

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    using mint = Mint<n>;
    for (int i = 1; i <= n; i++) {
        if (std::gcd(i, n)) {

        }
    }
    
    return 0;
}
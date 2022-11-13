#include <bits/stdc++.h>
using i64 = long long;

using namespace std;

int P;

int modulo(i64 x) {
    return (x % P + P) % P;
}

template <class T> T fpower(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

class Mint {
private:
    int x;

public:
    Mint() : x(0) {}
    //Mint(int x_) : x(modulo(x_)) {}
    Mint(i64 x_) : x(modulo(x_)) {}

    int val() {
        return x;
    }

    friend std::istream &operator>>(std::istream &is, Mint &a) {
        i64 temp;
        a.x = modulo(temp);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
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

struct node {
    Mint v, t;
    node() : v(1), t(0) {}
    node(Mint v_, Mint t_) : v(v_), t(t_) {}

    friend node operator*(const node &lhs, const node &rhs) {
        node res = lhs;
        res *= rhs;
        return res;
    }
    node &operator*=(const node &rhs) {
        Mint nv = v * rhs.v;
        Mint nt = t * rhs.v + rhs.t;
        v = nv, t = nt;
        return *this;
    }
};

node node_power(node a, i64 b) {
    node res(1, 0);
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

void solve() {
    int A, B, S, G;
    cin >> P >> A >> B >> S >> G;
    if (S == G) {
        cout << 0 << '\n';
        return;
    }
    if (A == 0) {
        if (B == G) {
            cout << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }

    const int BLK = 7e4;
    std::vector<Mint> f(BLK + 1);
    std::unordered_map<int, int> mp;
    f[0] = S;
    for (int i = 1; i <= BLK; i++) {
        f[i] = f[i - 1] * A + B;
    }
    for (int i = 0; i <= BLK; i++) {
        if(!mp.count(f[i].val())) {
            mp[f[i].val()] = i;
        }	
    }

    node T(A, B);
    node o = node_power(T, BLK);
    node cur(1, 0);
    for (int i = 0; i <= P / BLK; i++) {
        Mint w = (G + P - cur.t) / cur.v;
        if (mp.count(w.val())) {
            cout << i * BLK + mp[w.val()] << '\n';
            return;
        }
        cur = cur * o;
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
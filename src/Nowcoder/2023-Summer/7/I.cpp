/**
 * @author: XiaFan
 * @date: 2023-08-07 14:41
 */
#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) res *= a;
    }
    return res;
}
template <i64 P>
struct MintBase {
    i64 v;
    i64 norm(i64 x) const {
        x %= P;
        if (x < 0) x += P;
        return x;
    }
    MintBase() : v{0} {}
    MintBase(i64 x) : v{norm(x)} {}
    i64 val() const { return v; }
    MintBase operator-() const { return MintBase(norm(P - v)); }
    MintBase inv() const {
        assert(v != 0);
        return power(*this, P - 2);
    }
    MintBase &operator+=(const MintBase &rhs) {
        v = norm(v + rhs.v);
        return *this;
    }
    MintBase &operator-=(const MintBase &rhs) {
        v = norm(v - rhs.v);
        return *this;
    }
    MintBase &operator*=(const MintBase &rhs) {
        v = norm(v * rhs.v);
        return *this;
    }
    MintBase &operator/=(const MintBase &rhs) { return *this *= rhs.inv(); }
    friend MintBase operator+(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res += rhs;
        return res;
    }
    friend MintBase operator-(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res -= rhs;
        return res;
    }
    friend MintBase operator*(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res *= rhs;
        return res;
    }
    friend MintBase operator/(const MintBase &lhs, const MintBase &rhs) {
        MintBase res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MintBase &a) {
        i64 x;
        is >> x;
        a = MintBase(x);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MintBase &a) {
        return os << a.val();
    }
    friend bool operator==(const MintBase &lhs, const MintBase &rhs) {
        return lhs.val() == rhs.val();
    }
};
constexpr i64 P = 998244353;
using Mint = MintBase<P>;


Mint calc1(std::vector<std::string> s) {
    std::set<std::string> st;
    
    auto dfs = [&](auto &&dfs, int i, int j) -> void {
        if (j == s[i].length()) {
            st.insert(s[i]);
            return;
        }

        if (s[i][j] == '?') {
            for (int k = 0; k <= 1; k++) {
                s[i][j] = '0' + k;
                dfs(dfs, i, j + 1);
            }
            s[i][j] = '?';
        } else {
            dfs(dfs, i, j + 1);
        }
    };

    for (int i = 0; i < s.size(); i++) {
        dfs(dfs, i, 0);
    }

    // for (auto &str : st) {
    //     std::cerr << str << '\n';
    // }

    return st.size();
}


Mint calc2(std::vector<std::string> s) {
    int n = s.size();
    int N = 1 << n;
    Mint ans = 0;
    for (int bit = 1; bit < N; bit++) {
        int max_len = 0;
        int min_len = 1e9;
        for (int i = 0; i < n; i++) {
            if ((bit >> i) & 1) {
                max_len = std::max(max_len, (int)s[i].length());
                min_len = std::min(min_len, (int)s[i].length());
            }
        }

        if (max_len != min_len) {
            continue;
        }

        int len = max_len, cnt = 0;
        int add = 1;
        for (int j = 0; j < len; j++) {
            std::map<char, int> mp;
            for (int i = 0; i < n; i++) {
                if ((bit >> i) & 1) {
                    mp[s[i][j]]++;
                }
            }
            if (mp['0'] > 0 && mp['1'] > 0) {
                add = 0;
                break;
            }
            if (mp['0'] > 0 || mp['1'] > 0) {
                continue;
            }
            cnt++;
        }


        int flag = __builtin_popcount(bit) % 2 ? 1 : -1;
        // std::cout << std::bitset<6>(bit).to_string() << " " << flag << " " << (1LL << cnt) << '\n';
        ans += add * flag * power(Mint(2), cnt);
    }

    return ans;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> a, b;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        if (s.length() <= 20) {
            a.push_back(s);
        } else {
            b.push_back(s);
        }
    }

    // std::cerr << calc1(a) << " " << calc2(a) << '\n';

    std::cout << calc1(a) + calc2(b) << '\n';


    return 0;
}
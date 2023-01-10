/**
 * @author: XiaFan
 * @date: 10-26 18:09
 **/
#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

i64 str2i64(std::string s) {
    i64 x = 0;
    for (size_t i = 0; i < s.length(); i++) {
        x = x * 10 + s[i] - '0';
    }
    return x;
}

std::vector<int> fun(std::string s) {
    std::vector<int> v(10);
    for (size_t i = 0; i < s.length(); i++) {
        v[s[i] - '0']++;
    }
    return v;
}

bool subseq(std::string sa, std::string sb) {
    for (size_t i = 0, j = 0; i < sa.length(); i++) {
        if (sa[i] == sb[j]) {
            j++;
        }
        if (j == sb.length()) {
            return true;
        }
    }
    return false;
}

void solve() {
    i64 a, b;
    std::cin >> a >> b;

    std::string sa = std::to_string(a);
    std::string sb = std::to_string(b);

    const int Na = sa.length();
    // const int Nb = sb.length();

    auto va = fun(sa);
    auto vb = fun(sb);

    auto judge = [&](std::string ssa, std::string ssb) {
        auto vta = fun(ssa);
        auto vtb = fun(ssb);
        for (int i = 0; i < 10; i++) {
            int x = va[i] - vta[i];
            int y = vb[i] - vtb[i];
            if (x < 0 || y < 0 || x != y) {
                return false;
            }
        }
        return true;
    };

    i64 ansa = a;
    i64 g = std::gcd(a, b);
    a /= g, b /= g;
    for (i64 i = 1; i <= (1LL << Na) - 1; i++) {
        std::bitset<32> bit(i);
        std::string ssa;
        for (int j = 0; j < Na; j++) {
            if (bit[j]) {
                ssa.push_back(sa[j]);
            }
        }
        i64 ta = str2i64(ssa);
        if (ta == 0) {
            continue;
        }

        i128 k = i128(b) * ta;
        if (k % a != 0) {
            continue;
        }
        i64 tb = k / a;
        std::string ssb = std::to_string(tb);
        int dif = (int)sb.length() - (int)ssb.length() -
                 ((int)sa.length() - (int)ssa.length());
        for (int i = 0; i < dif; i++) {
            ssb = '0' + ssb;
        }

        if (subseq(sb, ssb) && judge(ssa, ssb)) {
            ansa = std::min(ansa, ta);
        }
    }

    std::cout << ansa << " " << i64(i128(b) * ansa / a) << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
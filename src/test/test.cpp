/**
 * @author: XiaFan
 * @date: 01-12 20:20
 **/
#include <bits/stdc++.h>
#include "templates/Number/Mint.hpp"
using i64 = long long;

int cnt = 0;

constexpr int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
struct Hash {
    MintBase<Mod1> m1;
    MintBase<Mod2> m2;
    Hash() : m1(0), m2(0) {
        cnt++;
    }
    Hash(int x, int y) : m1(x), m2(y) {
        cnt++;
    }
    Hash(MintBase<Mod1> x, MintBase<Mod2> y) : m1(x), m2(y) {
        cnt++;
    }
    std::pair<int, int> val() const {
        return {m1.val(), m2.val()};
    }
    friend Hash operator+(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.m1 + rhs.m1, lhs.m2 + rhs.m2);
    }
    friend Hash operator-(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.m1 - rhs.m1, lhs.m2 - rhs.m2);
    }
    friend Hash operator*(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.m1 * rhs.m1, lhs.m2 * rhs.m2);
    }
    friend bool operator==(const Hash &lhs, const Hash &rhs) {
        return lhs.m1 == rhs.m1 && lhs.m2 == rhs.m2;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Hash a(13331, 23333);
    Hash b(13331, 23333);
    Hash c = a + b;
    std::cout << cnt;

    return 0;
}
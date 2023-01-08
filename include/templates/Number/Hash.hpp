#pragma once
#include "templates/XCPC.h"
#include "templates/Number/Mint.hpp"

constexpr int Mod1 = 1e9 + 7, Mod2 = 1e9 + 9;
struct Hash {
    MintBase<Mod1> x;
    MintBase<Mod2> y;
    Hash() : x(0), y(0) {}
    Hash(int _x, int _y) : x(_x), y(_y) {}
    Hash(MintBase<Mod1> _x, MintBase<Mod2> _y) : x(_x), y(_y) {}
    friend Hash operator+(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Hash operator-(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Hash operator*(const Hash &lhs, const Hash &rhs) {
        return Hash(lhs.x * rhs.x, lhs.y * rhs.y);
    }
    friend bool operator==(const Hash &lhs, const Hash &rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }
};
Hash base(13331, 23333);

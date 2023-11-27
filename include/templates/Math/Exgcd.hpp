#pragma once
#include "XCPC.h"


std::array<i64, 3> exgcd(i64 a, i64 b) {
    if (b == 0) {
        return {a, 1, 0};
    }
    auto [g, x, y] = exgcd(b, a % b);
    return {g, y, x - a / b * y};
}
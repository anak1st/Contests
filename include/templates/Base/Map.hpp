#pragma once
#include "XCPC.h"

struct MapHash {
    static u64 splitmix64(u64 x) {
        x ^= x << 13;
        x ^= x >> 7;
        x ^= x << 17;
        return x;
    }
    u64 operator()(u64 x) const {
        static const u64 FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
using Map = std::unordered_map<i64, i64, MapHash>;

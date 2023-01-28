/**
 * @author: XiaFan
 * @date: 2023-01-28 16:29
 **/
#include <bits/stdc++.h>
#include "Debug.h"
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 5;
    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);
    println(a);
    std::adjacent_difference(a.begin(), a.end(), a.begin());
    println(a);
    std::partial_sum(a.begin(), a.end(), a.begin());
    println(a);

    return 0;
}
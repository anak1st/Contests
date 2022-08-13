#include <bits/stdc++.h>

typedef long long i64;

i64 solve(i64 a, i64 b, i64 l, i64 r, i64 n) {
    if(a > b || l > r) {
        return 0;
    } else {
        i64 res = 0;
        i64 mid = (a + b) / 2;
        if(r < mid) {
            res += solve(a, mid - 1, l, r, n / 2);
        } else if(mid < l) {
            res += solve(mid + 1, b, l, r, n / 2);
        } else {
            res += n % 2;
            res += solve(a, mid - 1, l, mid - 1, n / 2);
            res += solve(mid + 1, b, mid + 1, r, n / 2);
        }
        return res;
    }
}

i64 count(i64 n) {
    if(n <= 1) {
        return 1;
    } else {
        return 1 + 2 * count(n / 2);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n, l, r;
    std::cin >> n >> l >> r;

    i64 a = 1, b = count(n);
    std::cout << solve(a, b, l, r, n);

    return 0;
}
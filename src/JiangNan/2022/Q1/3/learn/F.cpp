#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

bool fun(int n, int k, i64 x, std::vector<i64> &a) {
    // a + b = x
    // a + bk >= a[i]
    // b >= (a[i] - x) / (k - 1)
    i64 cur = 0;
    for(int i = 0; i < n; i++) {
        if(x >= a[i]) {
            continue;
        }
        cur += (i64)ceil((double)(a[i] - x) / (k - 1));
    }
    // std::cerr << cur << ':' << x << '\n';
    return cur <= x;
}

int main() {
    int n;
    scanf("%d", &n);
    std::vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    std::sort(a.begin(), a.end());
    int k;
    scanf("%d", &k);

    i64 left = 0, right = a[n - 1];
    if(k == 1) {
        std::cout << right << '\n';
        return 0;
    }
    i64 ans = 0;
    while(left <= right) {
        i64 mid = (left + right) / 2;
        if(fun(n, k, mid, a)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
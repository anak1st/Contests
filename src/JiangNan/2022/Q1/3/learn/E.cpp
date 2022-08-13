#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;

int fun(int n, int mid, std::vector<i64> &a) {
    int cur = 1;
    i64 sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > mid) {
            return n + 1;
        }
        if(sum + a[i] > mid) {
            sum = a[i];
            cur++;
        } else {
            sum += a[i];
        }
    }
    return cur;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    i64 mn = 10000, mx = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        mn = std::min(mn, a[i]);
        mx += a[i];
    }

    i64 left = mn, right = mx;
    i64 ans = 1;
    while(left <= right) {
        i64 mid = (left + right) / 2;
        int cur = fun(n, mid, a);
        // std::cerr << cur << ':' << mid << '\n';
        if(cur <= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
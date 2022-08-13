#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

typedef long long i64;

bool judge(int n, i64 time, std::vector<i64> &a) {
    i64 c = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] < time) {
            c += (time - a[i]);
        }
    }
    // std::cerr << c << ':' << time << '\n';
    return c <= time;
}

int solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

    i64 left = 0, right = 1e11, ans = 0;

    while(left <= right) {
        i64 mid = (left + right) / 2;
        if(judge(n, mid, a)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for(int i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ": " << solve() + 1 << '\n';
    }

    return 0;
}
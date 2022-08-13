#include <algorithm>
#include <iostream>
#include <vector>

typedef long long i64;

bool judge(int n, int m, int mid, std::vector<i64> &x) {
    int cur = 0;  // removed rocks
    for(int i = 0, j = 1; j <= n + 1; j++) {
        if(x[j] - x[i] >= mid) {
            i = j;
        } else {
            cur++;
        }
        if(cur > m) {
            // remove > ans
            // distance--
            // std::cerr << cur << ':' << mid << '\n';
            return true;
        }
    }
    // std::cerr << cur << ':' << mid << '\n';
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    i64 L;
    int n, m;
    std::cin >> L >> n >> m;
    std::vector<i64> x(n + 2);
    for(int i = 1; i <= n; i++) {
        std::cin >> x[i];
    }
    x[n + 1] = L;
    std::sort(x.begin() + 1, x.end() - 1);

    i64 left = 1;
    i64 right = L;
    i64 ans = 1;
    while(left <= right) {
        i64 mid = (left + right) / 2;
        if(judge(n, m, mid, x)) {
            right = mid - 1;
        } else {
            ans = mid;
            left = mid + 1;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
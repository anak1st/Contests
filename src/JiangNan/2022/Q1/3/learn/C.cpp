#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

bool judge(int n, int c, int mid, std::vector<i64> &x) {
    int cur = 0;
    for(int i = 0, j = 1; j < n; j++) {
        if(x[j] - x[i] >= mid) {
            i = j;
            cur++;
        }
        if(cur >= c) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, c;
    std::cin >> n >> c;
    c--;
    std::vector<i64> x(n);
    for(int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    std::sort(x.begin(), x.end());

    i64 left = 1;
    i64 right = x[n - 1] - x[0];
    i64 ans = 1;
    while(left <= right) {
        i64 mid = (left + right) / 2;
        if(judge(n, c, mid, x)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    std::cout << ans << '\n';

    return 0;
}
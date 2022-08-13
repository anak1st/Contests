#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

void solve(std::vector<int> &a) {
    int n;
    std::cin >> n;

    int ans = 0;
    while(n >= 2) {
        int left = 0, right = 25820;
        int b = 0;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(n >= a[mid]) {
                b = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        ans++;
        n -= a[b];
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    int n = 25820;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + 3 * i - 1;
    }

    while(t--) {
        solve(a);
    }

    return 0;
}
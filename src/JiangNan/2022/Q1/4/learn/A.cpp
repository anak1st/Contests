#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    std::vector<double> a(n);
    std::vector<int> dp1(n, 1), dp2(n, 1);

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[j] < a[i]) {
                dp1[i] = std::max(dp1[i], dp1[j] + 1);
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(a[j] < a[i]) {
                dp2[i] = std::max(dp2[i], dp2[j] + 1);
            }
        }
    }

    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            mx = std::max(mx, dp1[i] + dp2[j]);
        }
    }

    std::cout << n - mx;

    return 0;
}
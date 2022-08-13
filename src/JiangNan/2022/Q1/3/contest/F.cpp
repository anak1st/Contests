#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long i64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string hb;
    std::cin >> hb;
    std::vector<int> a(3), b(3), c(3);
    for(int i = 0; i < (int)hb.length(); i++) {
        if(hb[i] == 'B') {
            a[0]++;
        } else if(hb[i] == 'S') {
            a[1]++;
        } else {
            a[2]++;
        }
    }

    for(int i = 0; i < 3; i++) {
        std::cin >> b[i];
    }
    for(int i = 0; i < 3; i++) {
        std::cin >> c[i];
    }
    i64 money;
    std::cin >> money;

    i64 left = 0, right = 2000000000000, ans = 0;
    while(left <= right) {
        i64 mid = (left + right) / 2;

        i64 cost = 0;
        for(int i = 0; i < 3; i++) {
            if(b[i] < mid * a[i]) {
                cost += (mid * a[i] - b[i]) * c[i];
            }
        }

        if(cost <= money) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    std::cout << ans;

    return 0;
}
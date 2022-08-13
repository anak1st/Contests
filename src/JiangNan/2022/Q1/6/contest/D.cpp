/**
 * @author: XiaFan
 * @date: 04-17 20:22
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

typedef long long i64;
typedef unsigned long long u64;

const double pi = std::acos(-1);

void solve() {
    int n, f;
    std::cin >> n >> f;
    std::vector<double> a(n);
    double mx = 0;
    for(int i = 0; i < n; i++) {
        double r;
        std::cin >> r;
        a[i] = r * r;
        mx = std::max(mx, a[i]);
    }

    double left = 0, right = mx;
    while(right - left > 1e-7) {
        double mid = (left + right) / 2;

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cnt += (int)(a[i] / mid);
            if(cnt > f) {
                break;
            }
        }
        if(cnt >= f + 1) {
            left = mid;
        } else {
            right = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(4) << left * pi << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
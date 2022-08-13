#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef std::pair<double, double> pair_dd;

bool cmp(pair_dd a, pair_dd b) {
    return a.second < b.second;
}

int solve() {
    int n, d;
    std::cin >> n >> d;
    if(n == 0 && d == 0) {
        return 0;
    }
    // point(x,y)
    std::vector<pair_dd> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
    }
    // size(left, right)
    std::vector<pair_dd> s(n);
    for(int i = 0; i < n; i++) {
        double x = a[i].first;
        double y = a[i].second;
        if(std::abs(y) > d) {
            return -1;
        }
        double dx = std::sqrt(d * d - y * y);
        s[i].first = x - dx;
        s[i].second = x + dx;
    }
    std::sort(s.begin(), s.end(), cmp);

    double radius = s[0].second;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(radius < s[i].first) {
            radius = s[i].second;
            ans++;
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    for(int i = 1; 1; i++) {
        int ans = solve();
        if(ans == 0) {
            return 0;
        }
        std::cout << "Case " << i << ": " << ans << '\n';
    }

    return 0;
}
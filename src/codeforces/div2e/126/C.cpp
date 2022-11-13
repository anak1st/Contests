/**
 * @author: XiaFan
 * @date: 2022-04-10 11:19:51
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

i64 judge(i64 day1, i64 day2) {
    if(day2 - day1 >= 2) {
        i64 tmp = (day2 - day1 - 2) / 3;
        day1 += 2 * tmp;
        day2 -= tmp;
    }
    while(day2 - day1 >= 2) {
        day1 += 2;
        day2 -= 1;
    }
    day1 = std::max(day1, day2);
    day2 = std::max(day2, day1 - 1);
    return day1 + day2;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 mx = 0;
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
        mx = std::max(mx, a[i]);
    }
    // 1
    i64 day1, day2;
    day1 = 0, day2 = 0;
    for(int i = 0; i < n; i++) {
        day1 += (mx - a[i]) % 2;
        day2 += (mx - a[i]) / 2;
    }
    i64 ans1 = judge(day1, day2);

    // 2
    day1 = 0, day2 = 0;
    for(int i = 0; i < n; i++) {
        day1 += (mx + 1 - a[i]) % 2;
        day2 += (mx + 1 - a[i]) / 2;
    }
    i64 ans2 = judge(day1, day2);
    std::cout << std::min(ans1, ans2) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
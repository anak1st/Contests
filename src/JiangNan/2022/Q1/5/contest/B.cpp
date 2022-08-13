/**
 * @author: XiaFan
 * @date: 2022-04-10 18:55:16
 * @brief: contest
 **/
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::map<std::pair<int, int>, int> mp;
    int x = 0, y = 0, ans = n + 1, left = 0, right = 0;
    mp[{0, 0}] = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') {
            x--;
        } else if(s[i] == 'R') {
            x++;
        } else if(s[i] == 'U') {
            y++;
        } else if(s[i] == 'D') {
            y--;
        }
        if(mp.count({x, y})) {
            int l = mp[{x, y}] + 1;
            int r = i + 1;
            if(r - l < ans) {
                left = l;
                right = r;
                ans = right - left;
            }
        }
        mp[{x, y}] = i + 1;
    }
    if(ans == n + 1) {
        std::cout << "-1\n";
        return;
    }
    std::cout << left << ' ' << right << '\n';
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
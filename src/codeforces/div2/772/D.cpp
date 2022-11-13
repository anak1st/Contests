#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, p;
    std::cin >> n >> p;
    std::vector<int> s(n);
    for(auto &it : s) std::cin >> it;
    std::sort(s.begin(), s.end());

    std::set<int> useful;
    for(auto &it : s) {
        int temp = it;

        bool appear = false;
        while(temp > 0) {
            if(useful.count(temp)) {
                appear = true;
                break;
            }

            if((temp & 1) == 1) {
                temp >>= 1;
            } else if((temp & 2) == 2) {
                break;
            } else {
                temp >>= 2;
            }
        }

        if(!appear) useful.insert(it);
    }

    constexpr int mod = 1e9 + 7;
    std::vector<int> dp(p, 0);
    int ans = 0;

    for(auto &it : useful) {
        // std::cout << it << '\n';

        int index = std::log2(it);
        if(index >= p) break;
        dp[index]++;
    }

    for(int i = 0; i < p; i++) {
        if(i >= 1) {
            dp[i] += dp[i - 1];
            dp[i] %= mod;
        }

        if(i >= 2) {
            dp[i] += dp[i - 2];
            dp[i] %= mod;
        }

        ans += dp[i];
        ans %= mod;
    }

    std::cout << ans << '\n';

    return 0;
}
/**
 * @author: XiaFan
 * @date: 2023-02-13 19:52
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> CNT(26);
    std::vector<bool> NO(26, true);
    for (auto c : s) {
        CNT[c - 'a']++;
        NO[c - 'a'] = false;
    }
    std::vector<int> id(26);
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int x, int y) {
        return CNT[x] > CNT[y];
    });

    int ans = n;
    std::string anss;
    for (int i = 1; i <= std::min(26, n); i++) {
        if (n % i != 0) continue;
        int x = n / i;
        std::string t = s;
        std::vector<int> target(26);
        for (int j = 0; j < 26; j++) {
            int k = id[j];
            if (j < i) {
                target[k] = x;
            } else {
                target[k] = 0;
            }
        }
        
        auto cnt = CNT;
        auto get_target = [&]() {
            for (int j = 0; j < 26; j++) {
                if (cnt[j] < target[j]) {
                    return j;
                }
            }
            return -1;
        };

        auto no = NO;
        auto get_no = [&]() {
            for (int j = 0; j < 26; j++) {
                if (no[j]) {
                    no[j] = false;
                    return j;
                }
            }
            return -1;
        };

        int tmpans = 0;
        for (int i = 0; i < n; i++) {
            int c = t[i] - 'a';

            if (cnt[c] > target[c]) {
                cnt[c]--;
                int k = get_target();
                tmpans++;
                if (k == -1) {
                    k = get_no();
                }
                assert(k != -1);
                cnt[k]++;
                t[i] = k + 'a';
            }
        }

        if (ans > tmpans) {
            ans = tmpans;
            anss = t;
        }
    }

    std::cout << ans << "\n";
    std::cout << anss << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
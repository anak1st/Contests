/**
 * @author: XiaFan
 * @date: 2023-03-03 15:25
 **/
#include <bits/stdc++.h>
using i64 = long long;

int f[1 << 26];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    std::vector<std::array<int, 26>> cnt(n);
    std::vector<int> mask(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        for (char c : s[i]) {
            cnt[i][c - 'a']++;
        }
        
        for (int c = 0; c < 26; c++) {
            mask[i] |= (cnt[i][c] % 2) << c;
        }
    }
    
    i64 ans = 0;
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < n; i++) {
            if (cnt[i][c] == 0) {
                ans += f[(1 << 26) - 1 - (1 << c) - mask[i]];
                f[mask[i]]++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (cnt[i][c] == 0) {
                f[mask[i]]--;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}
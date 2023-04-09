/**
 * @author: XiaFan
 * @date: 2023-04-09 10:30
 */
#include <bits/stdc++.h>

using i64 = long long;

int solve(std::string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; i + k <= j - k; k++) {
                if (s[i + k] > s[j - k]) {
                    ans++;
                    break;
                }
                if (s[i + k] < s[j - k]) {
                    break;
                }
            }
        }
    }
    return ans;
}

int fast_solve(std::string s) {
    int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] <= s[j]) {
                continue;
            }
            ans++;
            for (int k = 1; i - k >= 0 && j + k < n; k++) {
                if (s[i - k] == s[j + k]) {
                    ans++;
                } else {
                    break;
                }
            }
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    // std::cout << solve(s) << std::endl;
    // std::cerr << "\n";
    std::cout << fast_solve(s) << std::endl;
    

    return 0;
}
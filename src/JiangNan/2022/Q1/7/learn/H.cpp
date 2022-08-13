/**
 * @author: XiaFan
 * @date: 04-18 19:23
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

// The longest common subsequence
int LCS(std::string s1, std::string s2) {
    s1 = '0' + s1;
    s2 = '0' + s2;
    int n = s1.length();
    int m = s2.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s1, s2;
    while(std::cin >> s1 >> s2) {
        std::cout << LCS(s1, s2) << "\n";
    }

    return 0;
}
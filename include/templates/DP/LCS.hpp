#pragma once
#include "XCPC.h"

// Longest Common Subsequence
template <typename T>
std::pair<int, std::vector<T>> LCS(std::vector<T> s1, std::vector<T> s2) {
    int n = s1.size();
    int m = s2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    std::vector<T> res;
    {
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                res.push_back(s1[i - 1]);
                i--, j--;
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    i--;
                } else {
                    j--;
                }
            }
        }
    }
    std::reverse(res.begin(), res.end());
    return {dp[n][m], res};
}
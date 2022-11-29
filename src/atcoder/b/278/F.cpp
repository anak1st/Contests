/**
 * @author: XiaFan
 * @date: 11-22 16:47
 **/
#include <bits/stdc++.h>

using i64 = long long;
using bit = std::bitset<32>;

int main() {
    int N;
    std::cin >> N;

    // the first and last character of the i-th string
    std::vector<std::pair<int, int>> info(N);
    for (auto& [first, last] : info) {
        std::string S;
        std::cin >> S;
        first = S.front() - 'a';
        last = S.back() - 'a';
    }

    // the c-th significant bit of dp[S] = whether the first player wins when
    // unused words are S and the last character is c
    int MAX = 1 << N;
    std::vector dp(MAX, std::vector<int>(26));
    for (int S = 1; S < (MAX); S++) {
        for (int c = 0; c < N; c++) {
            auto [first, last] = info[c];
            auto bitS = bit(S);
            if (bitS[c]) {
                bitS[c] = false;
                int S_no_c = bitS.to_ulong();
                bitS[c] = true;
                dp[S][first] |= !dp[S_no_c][last];
            }
        }
    }
    // if any bit of dp[2^N - 1] is set, then the first player wins
    bool win = false;
    for (auto it : dp.back()) if (it) win = true;
    std::cout << (win ? "First" : "Second");

    return 0;
}

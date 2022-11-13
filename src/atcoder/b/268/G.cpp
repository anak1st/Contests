/**
 * @author: XiaFan
 * @date: 09-13 19:07
 **/
#include <bits/stdc++.h>
using i64 = long long;

constexpr i64 P = 998244353;

namespace Trie {
constexpr int N = 5E5 + 2;

int trie[N][26], have[N], sum[N];
int cnt = 1;

void insert(std::string s) {
    int p = 1;
    for (auto c : s) {
        int x = c - 'a';
        if (!trie[p][x]) {
            trie[p][x] = ++cnt;
        }
        p = trie[p][x];
        sum[p]++;
    }
    have[p] = 1;
}

bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        if (!trie[p][x]) {
            return false;
        }
        p = trie[p][x];
    }
    return have[p];
}

}  // namespace Trie

i64 fun(i64 x, i64 y) {
    for (i64 i = x; true; i += P) {
        if (i % y == 0) {
            return (i / y);
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    std::map<i64, i64> mp, ans; 
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
        Trie::insert(s[i]);
    }

    for (int i = 0; i < n; i++) {
        int p = 1;
        i64 ans = n;
        for (const auto c : s[i]) {
            int x = c - 'a';
            p = Trie::trie[p][x];
            ans = (ans + Trie::have[p]) % P;
        }
        ans = (ans - Trie::sum[p] + P) % P;
        std::cout << fun(ans + 1, 2) << "\n";
    }

    return 0;
}
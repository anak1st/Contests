#pragma once
#include <string>

using i64 = long long;

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
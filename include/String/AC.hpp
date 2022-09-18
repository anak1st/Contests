// Aho-Corasick Automaton
#pragma once
#include <queue>
#include <string>

namespace Trie {
constexpr int N = 5e5, M = 26;

int trie[N][M];
int fail[N], have[M];
int cnt = 1;

void init() {
    std::fill(trie[0], trie[0] + M, 1);
}

void insert(std::string t) {
    int p = 1;
    for (auto c : t) {
        int x = c - 'a';
        if (!trie[p][x]) {
            trie[p][x] = ++cnt;
        }
        p = trie[p][x];
    }
    have[p] = 1;
}

void build() {
    std::queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        have[x] |= have[fail[x]];
        for (int i = 0; i < M; i++) {
            if (trie[x][i]) {
                fail[trie[x][i]] = trie[fail[x]][i];
                q.push(trie[x][i]);
            } else {
                trie[x][i] = trie[fail[x]][i];
            }
        }
    }
}

bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        p = trie[p][x];
        if (have[p]) {
            return true;
        }
    }
    return false;
}

}  // namespace Trie
#pragma once
#include "XCPC.h"

// Aho-Corasick Automaton
constexpr int N = 5e5, M = 26;
int tree[N][M];
int fail[N], have[M];
int cnt = 1;
void init() {
    std::fill(tree[0], tree[0] + M, 1);
}
void insert(std::string t) {
    int p = 1;
    for (auto c : t) {
        int x = c - 'a';
        if (!tree[p][x]) {
            tree[p][x] = ++cnt;
        }
        p = tree[p][x];
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
            if (tree[x][i]) {
                fail[tree[x][i]] = tree[fail[x]][i];
                q.push(tree[x][i]);
            } else {
                tree[x][i] = tree[fail[x]][i];
            }
        }
    }
}
bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        p = tree[p][x];
        if (have[p]) {
            return true;
        }
    }
    return false;
}
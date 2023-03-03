#pragma once
#include "XCPC.h"

// Aho-Corasick Automaton
constexpr int N = 5e5;
int tree[N][26];
int fail[N], have[N];
int cnt = 0;
void insert(std::string t) {
    int p = 0;
    for (auto c : t) {
        int x = c - 'a';
        if (!tree[p][x]) {
            tree[p][x] = ++cnt;
        }
        p = tree[p][x];
    }
    have[p]++;
}
void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (tree[0][i]) {
            fail[tree[0][i]] = 0;
            q.push(tree[0][i]);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; i++) {
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
    int p = 0;
    for (const auto c : s) {
        int x = c - 'a';
        p = tree[p][x];
        if (have[p]) {
            return true;
        }
    }
    return false;
}
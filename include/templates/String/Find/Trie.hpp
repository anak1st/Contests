#pragma once
#include "XCPC.h"

constexpr int N = 5E5 + 2;
int tree[N][26], have[N], sum[N];
int cnt = 1;
void insert(std::string s) {
    int p = 1;
    for (auto c : s) {
        int x = c - 'a';
        if (!tree[p][x]) {
            tree[p][x] = ++cnt;
        }
        p = tree[p][x];
        sum[p]++;
    }
    have[p] = 1;
}
bool find(const std::string &s) {
    int p = 1;
    for (const auto c : s) {
        int x = c - 'a';
        if (!tree[p][x]) {
            return false;
        }
        p = tree[p][x];
    }
    return have[p];
}

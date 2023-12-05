#pragma once
#include "XCPC.h"


constexpr int LOG = 20;


struct Trie {
    std::vector<std::array<int, 2>> t;

    Trie() { t.push_back({-1, -1}); }

    void insert(int x) {
        int v = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (t[v][j] == -1) {
                t[v][j] = t.size();
                t.push_back({-1, -1});
            }
            v = t[v][j];
        }
    }

    int max_xsum(int x) {
        int v = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            int j = (x >> i) & 1;
            if (t[v][j ^ 1] != -1) j ^= 1;
            x ^= j << i;
            v = t[v][j];
        }
        return x;
    }
};
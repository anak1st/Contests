#pragma once
#include <bits/stdc++.h>

using i64 = long long;


constexpr int N = 1E5;
 
std::vector<std::vector<int>> divs;
std::vector<int> phi;

void init() {
    divs.resize(N + 1);
    phi.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        phi[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            phi[j] -= phi[i];
        }
    }
}
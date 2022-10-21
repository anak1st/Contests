#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "DataStructure/DSU.hpp"
#include "Graph/base.hpp"

template <typename T> 
T Kruskal(int n, std::vector<edge<T>> &e) {
    int m = e.size();
    std::sort(e.begin(), e.end());
    DSU dsu(n);
    int count = 0;
    T sum = 0;
    for (int i = 0; i < m; i++) {
        if (dsu.merge(e[i].a, e[i].b)) {
            sum += e[i].c;
            count++;
            // std::cerr << e[i].a << " " << e[i].b << "\n";
            if (count == (n - 1)) {
                break;
            }
        }
    }
    if (count != (n - 1)) {
        return -1;
    }
    return sum;
}
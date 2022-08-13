#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

#include "algorithm/DisjointSet.hpp"
#include "graph/base.hpp"

template <typename T> 
T Kruskal(int n, std::vector<edge<T>> &e) {
    int m = e.size();
    std::sort(e.begin(), e.end());
    DisjointSet st(n);
    int count = 0;
    T sum = 0;
    for (int i = 0; i < m; i++) {
        if (!st.unity(e[i].a, e[i].b)) {
            st.merge(e[i].a, e[i].b);
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
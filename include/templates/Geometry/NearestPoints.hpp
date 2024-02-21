#pragma once
#include <bits/stdc++.h>

using i64 = long long;
#include "Vector2.hpp"


double NearestPoints(std::vector<Vector2<double>> &p) {
    std::stable_sort(p.begin(), p.end());
    constexpr double inf = 1e18;
    auto merge = [&](auto &&merge, int l, int r) -> double {
        if (r - l == 1) return inf;
        if (r - l == 2) {
            return point_dis(p[l], p[l + 1]);
        }

        int mid = (l + r) / 2;

        double d = inf;
        d = std::min(d, merge(merge, l, mid));
        d = std::min(d, merge(merge, mid, r));
        
        std::vector<int> tmp;
        for (int i = l; i < r; i++) {
            if (point_disx(p[mid - 1], p[i]) < d) {
                tmp.push_back(i);
            }
        }
        std::sort(tmp.begin(), tmp.end(), [&](int i, int j) {
            return p[i].y < p[j].y;
        });
        int m = tmp.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m && point_disy(p[tmp[i]], p[tmp[j]]) < d; j++) {
                d = std::min(d, point_dis(p[tmp[i]], p[tmp[j]]));
            }
        }

        return d;
    };

    return merge(merge, 0, p.size());
}
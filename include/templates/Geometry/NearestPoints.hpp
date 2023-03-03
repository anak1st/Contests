#pragma once
#include "XCPC.h"
#include "Vector2d.hpp"

double NearestPoints(std::vector<Vector2d> &p) {
    std::stable_sort(p.begin(), p.end());

    constexpr double inf = 1e18;

    auto merge = [&](auto &&merge, int l, int r) -> double {
        if (r - l == 1) {
            return inf;
        }
        if (r - l == 2) {
            return dis(p[l], p[l + 1]);
        }

        int mid = (l + r) / 2;

        double d = inf;
        d = std::min(d, merge(merge, l, mid));
        d = std::min(d, merge(merge, mid, r));
        
        std::vector<int> tmp;
        for (int i = l; i < r; i++) {
            if (disx(p[mid - 1], p[i]) < d) {
                tmp.push_back(i);
            }
        }
        std::sort(tmp.begin(), tmp.end(), [&](int i, int j) {
            return p[i].y < p[j].y;
        });
        int m = tmp.size();
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m && disy(p[tmp[i]], p[tmp[j]]) < d; j++) {
                d = std::min(d, dis(p[tmp[i]], p[tmp[j]]));
            }
        }

        return d;
    };

    return merge(merge, 0, p.size());
}
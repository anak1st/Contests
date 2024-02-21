#pragma once
#include <bits/stdc++.h>

using i64 = long long;
#include "Vector2.hpp"

/// Get the convex hull of a set of points, using the Andrew algorithm.
template <typename T>
std::vector<int> Convex_Andrew(std::vector<Vector2<T>> &p) {
    std::sort(p.begin(), p.end(), [](const Vector2<T> &lhs, const Vector2<T> &rhs) {
        return lhs.x < rhs.x || (lhs.x == rhs.x && lhs.y < rhs.y);
    });
    std::vector<int> res;
    for (int i = 0; i < p.size(); i++) {
        while (res.size() >= 2 && cross(p[i] - p[res[res.size() - 2]], p[res[res.size() - 1]] - p[res[res.size() - 2]]) <= 0) {
            res.pop_back();
        }
        res.push_back(i);
    }
    int t = res.size();
    for (int i = p.size() - 2; i >= 0; i--) {
        while (res.size() > t && cross(p[i] - p[res[res.size() - 2]], p[res[res.size() - 1]] - p[res[res.size() - 2]]) <= 0) {
            res.pop_back();
        }
        res.push_back(i);
    }
    res.pop_back();
    for (int i = 0; i < res.size(); i++) p[res[i]].is_convex = true;
    return res;
}


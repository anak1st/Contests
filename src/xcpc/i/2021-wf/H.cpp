/**
 * @author: XiaFan
 * @date: 11-10 13:58
 **/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    auto fun = [](const std::string &s) -> std::array<int, 3> {
        int res = 0, left = s.length(), right = -s.length();
        for (int i = 0, j = 0; i < (int)s.length(); i++) {
            if (s[i] == '(') {
                j++;
            } else {
                j--;
            }
            res = j;
            left = std::min(left, j);
        }
        for (int i = s.length() - 1, j = 0; i >= 0; i--) {
            if (s[i] == '(') {
                j++;
            } else {
                j--;
            }
            right = std::max(right, j);
        }
        return {res, left, right};
    };

    std::vector<std::array<int, 3>> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        v[i] = fun(s[i]);
        sum += v[i][0];
    }

    if (sum != 0) {
        std::cout << "impossible\n";
        return 0;
    }

    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int x, int y) -> bool {
        return v[x][0] > v[y][0];
    });

    int mid = 0;
    for (int i = 0; i < n; i++) {
        if (v[p[i]][0] < 0) {
            break;
        }
        mid = i;
    }

    std::sort(p.begin(), p.begin() + mid + 1, [&](int x, int y) -> bool {
        return v[x][1] > v[y][1];
    });
    std::sort(p.begin() + mid + 1, p.end(), [&](int x, int y) -> bool {
        return v[x][2] > v[y][2];
    });


    for (int i = 0, k = 0; i < n; i++) {
        for (int j = 0; j < s[p[i]].length(); j++) {
            if (s[p[i]][j] == '(') {
                k++;
            } else {
                k--;
            }
            if (k < 0) {
                std::cout << "impossible\n";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << p[i] + 1 << "\n";
    }
    
    return 0;
}
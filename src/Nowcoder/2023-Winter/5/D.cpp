/**
 * @author: XiaFan
 * @date: 2023-02-01 18:13
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
}

using priority_queue = std::priority_queue<std::pair<int, int>,
                                           std::vector<std::pair<int, int>>,
                                           std::greater<std::pair<int, int>>>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n), b(n);
    for (auto &[x, y] : a) {
        std::cin >> x >> y;
    }
    for (auto &[x, y] : b) {
        std::cin >> x >> y;
    }

    priority_queue q1, q2;
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n; i++) {
        q1.push(a[i]);
        q2.push(b[i]);
        while (!q1.empty() && p1 + 1 >= q1.top().first) {
            p1 = std::max(p1, q1.top().second);
            q1.pop();
        }
        while (!q2.empty() && p2 + 1 >= q2.top().first) {
            p2 = std::max(p2, q2.top().second);
            q2.pop();
        }
        // std::cerr << p1 << " " << p2 << "\n";
        if (p1 == p2) {
            std::cout << "win_win!\n" << 0 << "\n";
        } else if (p1 > p2) {
            std::cout << "sa_win!\n" << p1 - p2 << "\n";
        } else {
            std::cout << "ya_win!\n" << p2 - p1 << "\n";
        }
    }

    return 0;
}
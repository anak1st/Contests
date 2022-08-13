#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

struct good {
    int p, d;
};

bool cmp(const good &a, const good &b) {
    return a.d < b.d;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while(std::cin >> n) {
        std::vector<good> g(n);
        int day = 0;
        for(int i = 0; i < n; i++) {
            std::cin >> g[i].p >> g[i].d;
            day = std::max(day, g[i].d);
        }
        std::sort(g.begin(), g.end(), cmp);
        // for(int i = 0; i < n; i++) {
        //     std::cerr << g[i].p << ' ' << g[i].d << '\n';
        // }

        int ans = 0;
        std::priority_queue<int, std::vector<int>, std::less<int>> q;
        for(int index = n - 1; day >= 1; day--) {
            while(index >= 0 && g[index].d >= day) {
                q.push(g[index].p);
                index--;
            }
            if(q.empty()) {
                continue;
            }
            ans += q.top();
            q.pop();
        }
        std::cout << ans << '\n';
    }
    return 0;
}
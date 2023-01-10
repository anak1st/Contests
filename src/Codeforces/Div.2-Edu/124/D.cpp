#include <bits/stdc++.h>

using point = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<point, int> id;
    std::set<point> all;

    const int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        id[{x, y}] = i;

        for(auto [dx, dy] : move) {
            int nx = x + dx;
            int ny = y + dy;
            // all.emplace(nx, ny);
            all.insert({nx, ny});
        }
    }

    std::vector<point> ans(n, {-1, -1});
    std::queue<std::array<int, 4>> edge;
    for(auto [x, y] : all) {
        if(!id.count({x, y})) {
            edge.push({x, y, x, y});
        }
    }
    // from b to a
    while(!edge.empty()) {
        auto [x, y, fx, fy] = edge.front();
        // fx -> b.x fy -> b.y
        edge.pop();

        for(auto [dx, dy] : move) {
            int nx = x + dx;
            int ny = y + dy;
            // over egde
            if(!id.count({nx, ny})) continue;

            ans[id[{nx, ny}]] = {fx, fy};
            // a -> egde
            id.erase({nx, ny});  // find!
            edge.push({nx, ny, fx, fy});
        }
    }

    for(auto [x, y] : ans) {
        std::cout << x << " " << y << "\n";
    }

    return 0;
}
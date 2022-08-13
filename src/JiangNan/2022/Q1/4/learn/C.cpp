#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

namespace KM {
// KM算法 求完备二分图匹配下的最大权匹配
const int inf = 1e9;
const int maxN = 123;     // a,b[max]
int match[maxN];          // a[match]
double edge[maxN][maxN];  // 记录每个 a 和 b 的 edge
double la[maxN];          // a 期望值
double lb[maxN];          // b 期望值
double lack[maxN];        // 记录每个 b 能 a link还需要最小期望值
bool visa[maxN];          // 记录每一轮匹配匹配过的 a
bool visb[maxN];          // 记录每一轮匹配匹配过的 b

bool dfs(int n, int a) {
    visa[a] = true;
    for(int b = 0; b < n; b++) {
        if(visb[b]) {  // 每一轮匹配 每个 b 只尝试一次
            continue;
        }

        double d = la[a] + lb[b] - edge[a][b];
        if(std::abs(d) <= 1e-8) {
            visb[b] = true;
            // 找到一个没有匹配 b[i] 或者 b[i]->a[match[b]] 可以找到其他 b
            if(match[b] == -1 || dfs(n, match[b])) {
                match[b] = a;
                return true;
            }
        } else {
            // lack = b[i]->a[0~n] 最小缺口期望值
            lack[b] = std::min(lack[b], d);
        }
    }
    return false;
}

void doing(int n) {
    for(int i = 0; i < n; i++) {
        match[i] = -1;  // 初始 没有匹配
        lb[i] = 0;      // 初始 b期望 = 0
        la[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 初始 a期望 = max(edge[a][0~n])
            la[i] = std::max(la[i], edge[i][j]);
        }
    }

    for(int girl = 0; girl < n; girl++) {
        for(int i = 0; i < n; i++) {
            lack[i] = inf;
        }
        while(1) {
            // 为每个 a[i] 找 b[0~n]
            for(int i = 0; i < n; i++) {
                visa[i] = false;
                visb[i] = false;
            }
            // 找到b 为 a[i+i] 找 b[0~n]
            if(dfs(n, girl)) {
                break;
            }
            // 找不到 降低 所有参与的a[i], b[i]的 最小的 缺口期望值d
            double d = inf;
            for(int i = 0; i < n; i++) {
                if(!visb[i]) {
                    d = std::min(d, lack[i]);
                }
            }
            for(int i = 0; i < n; i++) {
                if(visa[i]) {
                    la[i] -= d;
                }
                if(visb[i]) {
                    lb[i] += d;
                } else {
                    // 没有访问过的b 因为 a 的期望值降低，b->a缺口期望值减小
                    lack[i] -= d;
                }
            }
        }
    }

    std::vector<int> ans(n, -1);  // b[match]
    for(int i = 0; i < n; i++) {
        if(match[i] == -1) {
            continue;
        }
        ans[match[i]] = i + 1;
    }
    for(int i = 0; i < n; i++) {
        std::cout << ans[i] << '\n';
    }
}
}  // namespace KM

struct point {
    double x, y;
    point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
double dist(point a, point b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    while(std::cin >> n) {
        std::vector<point> a(n), b(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i].x >> a[i].y;
        }
        for(int i = 0; i < n; i++) {
            std::cin >> b[i].x >> b[i].y;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                KM::edge[i][j] = -dist(a[i], b[j]);
            }
        }
        KM::doing(n);
    }

    return 0;
}
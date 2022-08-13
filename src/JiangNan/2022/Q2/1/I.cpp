/**
 * @author: XiaFan
 * @date: 06-22 18:15
 **/
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long i64;

class DisjointSet {
private:
    int n;
    std::vector<int> f;

public:
    DisjointSet(int _n) : n(_n), f(_n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
    }

    int find(int x) {
        if (f[x] != x) {
            f[x] = find(f[x]);
        }
        return f[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        f[rx] = ry;
    }

    bool unity(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        return rx == ry;
    }
};

struct edge {
    int a, b, c;
    edge() : a(0), b(0), c(0) {}
    edge(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        int n, m;
        cin >> n >> m;
        vector<edge> e(m);
        int left = 1000000, right = 0;
        for (int i = 0; i < m; i++) {
            cin >> e[i].a >> e[i].b >> e[i].c;
            e[i].a--, e[i].b--;
            left = min(left, e[i].c);
            right = max(right, e[i].c);
        }

        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            DisjointSet djs(n);
            for(int i = 0; i < m; i++) {
                if(mid <= e[i].c) {
                    djs.merge(e[i].a, e[i].b);
                }
            }
            if(djs.unity(0, n - 1)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << "Scenario #" << t << ":\n";
        cout << ans << "\n\n";
    }

    return 0;
}
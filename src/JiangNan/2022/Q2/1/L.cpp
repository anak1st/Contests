/**
 * @author: XiaFan
 * @date: 06-22 17:22
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
    int a, b;
    double c;
    edge() : a(0), b(0), c(0) {}
    edge(int a_, int b_, double c_) : a(a_), b(b_), c(c_) {}
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

struct point {
    double x, y;
    point() : x(0), y(0) {}
    point(double x_, double y_) : x(x_), y(y_) {}
};

double dis(point a, point b) {
    double x = abs(a.x - b.x);
    double y = abs(a.y - b.y);
    return sqrt(x * x + y * y);
}

void solve() {
    int s, n;
    cin >> s >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    std::vector<edge> e;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            e.push_back(edge(i, j, dis(p[i], p[j])));
        }
    }
    int m = e.size();
    std::sort(e.begin(), e.end());
    int count = 0;
    DisjointSet st(n);
    for (int i = 0; i < m; i++) {
        if (!st.unity(e[i].a, e[i].b)) {
            st.merge(e[i].a, e[i].b);
            count++;
            // std::cerr << e[i].a << " " << e[i].b << "\n";
            if (count == (n - s)) {
                cout << fixed << setprecision(2) << e[i].c << "\n";
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
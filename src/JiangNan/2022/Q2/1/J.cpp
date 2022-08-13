/**
 * @author: XiaFan
 * @date: 06-22 17:48
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

struct node {
    double x, y, z, r;
    node() : x(0), y(0), z(0), r(0) {}
    node(double x_, double y_, double z_, double r_) : x(x_), y(y_), z(z_), r(r_) {}
};

double dis(node a, node b) {
    double x = abs(a.x - b.x);
    double y = abs(a.y - b.y);
    double z = abs(a.z - b.z);
    return max(0.0, sqrt(x * x + y * y + z * z) - a.r - b.r);
}

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

double Kruskal(int n, std::vector<edge> &e) {
    int m = e.size();
    std::sort(e.begin(), e.end());
    DisjointSet st(n);
    int count = 0;
    double sum = 0;
    for (int i = 0; i < m; i++) {
        if (!st.unity(e[i].a, e[i].b)) {
            st.merge(e[i].a, e[i].b);
            sum += e[i].c;
            count++;
            // std::cerr << e[i].a << " " << e[i].b << "\n";
            if (count == (n - 1)) {
                break;
            }
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<node> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z >> a[i].r;
        }
        vector<edge> e;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                e.push_back(edge(i, j, dis(a[i], a[j])));
            }
        }
        double ans = Kruskal(n, e);
        cout << fixed << setprecision(3) << ans << "\n";
    }

    return 0;
}
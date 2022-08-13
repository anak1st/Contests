/**
 * @author: XiaFan
 * @date: 06-22 14:50
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
#include <cassert>

using namespace std;
typedef long long i64;
// const int inf = 1e9;

struct edge {
    int a, b;
    double r, c;
    edge() : a(0), b(0), r(0), c(0) {}
    edge(int a_, int b_, double r_, double c_) : a(a_), b(b_), r(r_), c(c_) {}
};

bool BellmanFord(int n, int start, double val, std::vector<edge> e) {
    std::vector<double> d(n, -1);
    // assert(start < n);
    d[start] = val;
    int m = e.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int a = e[j].a, b = e[j].b;
            double r = e[j].r, c = e[j].c;
            double next = (d[a] - c) * r;
            // assert(a < n && b < n);
            d[b] = std::max(d[b], next);
        }
    }
    for (int j = 0; j < m; j++) {
        int a = e[j].a, b = e[j].b;
        double r = e[j].r, c = e[j].c;
        double next = (d[a] - c) * r;
        if (d[b] < next) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;
    s--;
    vector<edge> e;
    for (int i = 0; i < m; i++) {
        int a, b;
        double r1, c1, r2, c2;
        cin >> a >> b >> r1 >> c1 >> r2 >> c2;
        a--, b--;
        e.push_back(edge(a, b, r1, c1));
        e.push_back(edge(b, a, r2, c2));
    }
    bool res = BellmanFord(n, s, v, e);
    if(res) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
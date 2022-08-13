/**
 * @author: XiaFan
 * @date: 06-23 09:11
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
const double inf = 1e9;

template <typename T> struct point_base {
    T x, y;
    point_base() : x(0), y(0) {}
    point_base(T x_, T y_) : x(x_), y(y_) {}
};
typedef point_base<int> point;

double dis(point a, point b) {
    double x = abs(a.x - b.x);
    double y = abs(a.y - b.y);
    return sqrt(x * x + y * y);
}

vector<double> Dijkstra(const vector<vector<double> > &g) {
    int n = g.size();
    vector<double> d(n, inf);
    d[0] = 0;
    vector<bool> vis(n);
    for (int i = 0; i < n; i++) {
        int k = -1;
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            if (k == -1 || d[j] < d[k]) {
                k = j;
            }
        }
        vis[k] = true;
        for (int j = 0; j < n; j++) {
            // if (vis[j]) continue;
            // d[j] = min(d[j], d[k] + g[t][j]);
            d[j] = min(d[j], max(d[k], g[k][j]));
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int t = 1; true; t++) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<point> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
        }
        vector<vector<double> > g(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                g[i][j] = dis(p[i], p[j]);
                g[j][i] = g[i][j];
            }
        }
        vector<double> res = Dijkstra(g);
        cout << "Scenario #" << t << "\nFrog Distance = ";
        cout << fixed << setprecision(3) << res[1] << "\n\n";
    }

    return 0;
}
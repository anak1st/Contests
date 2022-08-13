/**
 * @author: XiaFan
 * @date: 06-22 10:48
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
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

int Kruskal(int n, int m, std::vector<edge> &e) {
    std::sort(e.begin(), e.end());
    DisjointSet st(n);
    int count = 0;
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (!st.unity(e[i].a, e[i].b)) {
            st.merge(e[i].a, e[i].b);
            sum += e[i].c;
            count++;
            if (count == (n - 1)) {
                break;
            }
        }
    }
    if (count != (n - 1)) {
        return -1;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n, m;
        cin >> m >> n;
        if (m == 0) {
            break;
        }

        vector<edge> e(m);
        for (int i = 0; i < m; i++) {
            cin >> e[i].a >> e[i].b >> e[i].c;
            e[i].a--, e[i].b--;
        }

        int res = Kruskal(n, m, e);
        if (res == -1) {
            cout << "?\n";
        } else {
            cout << res << "\n";
        }
    }

    return 0;
}
/**
 * @author: XiaFan
 * @date: 06-22 18:47
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
    int c;
    edge() : a(0), b(0), c(0) {}
    edge(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {}
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

int Kruskal(int n, std::vector<edge> &e) {
    int m = e.size();
    std::sort(e.begin(), e.end());
    DisjointSet st(n);
    int count = 0;
    int sum = 0;
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

    int n;
    while (cin >> n) {
        vector<vector<int> > mat(n, vector<int>(n));
        vector<edge> e;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
                if(i < j) {
                    e.push_back(edge(i, j, mat[i][j]));
                }
            }
        }
        int res = Kruskal(n, e);
        cout << res << "\n";
    }

    return 0;
}
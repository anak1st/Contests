/**
 * @author: XiaFan
 * @date: 06-22 16:46
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
    edge(int a_, int b_, double c_) : a(a_), b(b_), c(c_) {}
    friend bool operator<(const edge &lhs, const edge &rhs) {
        return lhs.c < rhs.c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int> > city(n);
    for(int i = 0; i < n; i++) {
        cin >> city[i].first >> city[i].second;
    }

    int t;
    cin >> t;
    DisjointSet st(n);
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        st.merge(x, y);
    }

    vector<edge> e;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(st.unity(i, j)) {
                continue;
            }
            int x = abs(city[i].first - city[j].first);
            int y = abs(city[i].second - city[j].second);
            double dis = sqrt(x * x + y * y);
            e.push_back(edge(i, j, dis));
        }
    }
    int m = e.size();
    std::sort(e.begin(), e.end());
    
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (!st.unity(e[i].a, e[i].b)) {
            st.merge(e[i].a, e[i].b);
            count++;
            cout << e[i].a + 1 << " " << e[i].b + 1 << "\n";
            if (count == (n - 1)) {
                break;
            }
        }
    }

    return 0;
}
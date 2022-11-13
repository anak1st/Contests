/**
 * @author: XiaFan
 * @date: 05-15 15:19
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T> class Fenwick {
private:
    int n;
    T init;
    std::vector<T> fen;  // 1...n
    int lowbit(int x) {
        return x & -x;
    }

public:
    Fenwick(int _n, T _init = 0) : n(_n), init(_init), fen(_n + 1, _init) {}
    void add(int pos, T val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            fen[i] += val;
        }
    }
    T sum(int pos) {
        T val = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            val += fen[i];
        }
        return val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> b(n), c(n);
    Fenwick<int> fb(n), fc(n);

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (b[x - 1] == 0) fb.add(x, 1);
            if (c[y - 1] == 0) fc.add(y, 1);
            b[x - 1]++, c[y - 1]++;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            if (b[x - 1] == 1) fb.add(x, -1);
            if (c[y - 1] == 1) fc.add(y, -1);
            b[x - 1]--, c[y - 1]--;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int j1 = fb.sum(x2) - fb.sum(x1 - 1);
            int j2 = fc.sum(y2) - fc.sum(y1 - 1);
            if (j1 == x2 - x1 + 1 || j2 == y2 - y1 + 1) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
/**
 * @author: XiaFan
 * @date: 06-28 10:51
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T> class FenwickTree {
private:
    int n;
    std::vector<T> a;

    int lowbit(int x) {
        return x & -x;
    }

    T sum(int pos) {
        T val = 0;
        pos++;
        for (int i = pos; i > 0; i -= lowbit(i)) {
            val += a[i - 1];
        }
        return val;
    }

public:
    FenwickTree(int size) : n(size), a(n) {}

    FenwickTree(const std::vector<T> &v) : n(int(v.size())), a(n) {
        for (int i = 0; i < n; i++) {
            add(i, v[i]);
        }
    }

    void add(int pos, T val) {
        pos++;
        for (int i = pos; i <= n; i += lowbit(i)) {
            a[i - 1] += val;
        }
    }

    T sum(int left, int right) {
        assert(0 <= left && left <= right && right < n);
        if (left == 0) {
            return sum(right);
        } else {
            return sum(right) - sum(left - 1);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    FenwickTree<int> fa(n), fb(n);
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (a[x] == 0) fa.add(x, 1);
            if (b[y] == 0) fb.add(y, 1);
            a[x]++;
            b[y]++;
        } else if (op == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (a[x] == 1) fa.add(x, -1);
            if (b[y] == 1) fb.add(y, -1);
            a[x]--;
            b[y]--;
        } else if (op == 3) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;
            bool j1 = fa.sum(x1, x2) == x2 - x1 + 1;
            bool j2 = fb.sum(y1, y2) == y2 - y1 + 1;
            if (j1 || j2) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}
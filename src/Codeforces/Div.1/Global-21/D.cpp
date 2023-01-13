/**
 * @author: XiaFan
 * @date: 07-11 20:20
 **/
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

template <typename T, class F = std::function<T(const T&, const T&)>> 
class SparseTable {
private:
    int n;
    std::vector<std::vector<T>> mat;
    F func;

public:
    SparseTable(const std::vector<T>& a, const F& f) : n(int(a.size())), func(f) {
        assert(n > 0);
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int i = 1; i < max_log; i++) {
            int m = n - (1 << i) + 1;
            mat[i].resize(m);
            for (int j = 0; j < m; j++) {
                mat[i][j] = func(mat[i - 1][j], mat[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T get(int from, int to) const {
        assert(0 <= from && from <= to && to < n);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n - 1 << "\n";
        return;
    }

    vector<int> b(n);
    iota(b.begin(), b.end(), 0);

    SparseTable<int> stmin(b, [&](int i, int j) { return a[i] < a[j] ? i : j; });
    SparseTable<int> stmax(b, [&](int i, int j) { return a[i] > a[j] ? i : j; });

    function<int(int, int)> fun = [&](int left, int right) -> int {
        // assert(left < right); 
        int i = stmin.get(left, right);
        int j = stmax.get(left, right);
        // cerr << left << " " << right << " " << i << " " << j << "\n";
        if (i > j) swap(i, j);
        if (i == left && j == right) {
            return 1;
        }

        int res = 0;
        if (left < i) {
            res += fun(left, i);
        }
        if (i < j) {
            res += fun(i, j);
        }
        if (j < right) {
            res += fun(j, right);
        }
        return res;
    };

    int ans = fun(0, n - 1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

    return 0;
}
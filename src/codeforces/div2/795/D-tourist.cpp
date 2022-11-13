#include <bits/stdc++.h>

using namespace std;

template <typename T, class F = function<T(const T&, const T&)>> class SparseTable {
private:
    int n;
    vector<vector<T>> mat;
    F func;

public:
    SparseTable(const vector<T>& a, const F& f) : n(int(a.size())), func(f) {
        assert(n > 0);
        // int max_log = 32 - __builtin_clz(n);
        int max_log = int(log2(n)) + 1;
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
        assert(0 <= from && from <= to && to <= n - 1);
        // int lg = 32 - __builtin_clz(to - from + 1) - 1;
        int lg = int(log2(to - from + 1));
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<i64> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<i64> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i]; // 1 ... n
        }
        vector<int> b(n);
        iota(b.begin(), b.end(), 0);
        SparseTable<int> sa(b, [&](int i, int j) { return a[i] > a[j] ? i : j; });
        SparseTable<i64> smin(pref, [&](i64 i, i64 j) { return min(i, j); });
        SparseTable<i64> smax(pref, [&](i64 i, i64 j) { return max(i, j); });
        
        bool ok = true;
        function<void(int, int)> Dfs = [&](int l, int r) {
            if (l > r) {
                return;
            }
            int x = sa.get(l, r);
            i64 mn = smin.get(l, x); // l .. x-1
            i64 mx = smax.get(x + 1, r + 1); // x+1 ... r
            if (a[x] < mx - mn) {
                ok = false;
            }
            Dfs(l, x - 1);
            Dfs(x + 1, r);
        };
        Dfs(0, n - 1);

        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
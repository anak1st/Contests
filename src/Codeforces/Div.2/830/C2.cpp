#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> p;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            p.push_back(i);
        }
    }
    
    const int m = p.size();
    
    std::vector<i64> sum(m + 1);
    std::vector<int> xsum(m + 1);
    for (int i = 0; i < m; i++) {
        sum[i + 1] = sum[i] + a[p[i]];
        xsum[i + 1] = xsum[i] ^ a[p[i]];
    }
    
    for (int i = 0; i < q; i++) {
        int L, R;
        std::cin >> L >> R;
        L--;
        int u = L, v = R;
        int l = std::lower_bound(p.begin(), p.end(), L) - p.begin();
        int r = std::lower_bound(p.begin(), p.end(), R) - p.begin();
        
        i64 val = sum[r] - sum[l] - (xsum[r] ^ xsum[l]);
        if (!val) {
            v = u + 1;
        }
        
        for (int x = l; x <= std::min(r, l + 31); x++) {
            for (int y = std::max(x + 1, r - 31); y <= r; y++) {
                i64 cur = sum[y] - sum[x] - (xsum[y] ^ xsum[x]);
                if (cur == val) {
                    int l = p[x];
                    int r = p[y - 1] + 1;
                    if (r - l < v - u) {
                        u = l;
                        v = r;
                    }
                }
            }
        }
        
        std::cout << u + 1 << " " << v << "\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

/**
 * @author: XiaFan
 * @date: 2023-11-15 18:56
 */
#include <bits/stdc++.h>

using i64 = long long;


template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <typename T>
using max_heap = std::priority_queue<T, std::vector<T>, std::less<T>>;


void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    if (n < m) {
        std::cout << -1 << "\n";
        return;
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int dif = 0;
    for (int i = 0; i < m; i++) {
        if (b[i] < a[i + n - m]) {
            std::cout << -1 << "\n";
            return;
        }
        dif += b[i] - a[i + n - m];
    }

    std::vector<int> ans;

    if (dif > n - m) {
        std::cout << -1 << "\n";
        return;
    }

    int size = n;
    for (int i = 0, j = 0; i < n && size > dif + m && dif >= 0; ) {
        if (j < i) j = i;

        for (; j + 1 < n && a[j + 1] == a[i]; j++) ;

        ans.push_back(a[j]);
        a[j]++;
        if (j >= n - m) dif--;
        j--;
        a[i] = -1;
        i++;
        size--;

        // std::cerr << dif << " " << size << "\n";
        // for (auto x : a) std::cerr << x << " ";
        // std::cerr << "\n";
    }

    for (int i = 0; i < m; i++) {
        if (a[i + n - m] > b[i]) {
            std::cout << -1 << "\n";
            return;
        }

        if (a[i + n - m] == -1) {
            std::cout << -1 << "\n";
            return;
        }

        for (int j = a[i + n - m]; j < b[i]; j++) {
            ans.push_back(j);
        }
    }

    std::cout << ans.size() << "\n";
    for (auto x : ans) {
        std::cout << x << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
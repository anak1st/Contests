/**
 * @author: XiaFan
 * @date: 2023-04-09 23:13
 */
#include <bits/stdc++.h>

using i64 = long long;

int add(int x) {
    std::cout << "+ " << x << std::endl;
    int res;
    std::cin >> res;
    return res;
}

int ask(int x, int y) {
    std::cout << "? " << x + 1 << " " << y + 1 << std::endl;
    int res;
    std::cin >> res;
    return res;
}

std::vector<int> gen(int n) {
    std::vector<int> a(n);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = r--;
        } else {
            a[i] = l++;
        }
    }
    return a;
}

void solve() {
    int n;
    std::cin >> n;
    add(n);
    add(n + 1);
    int maxd = 0;
    int id = -1;
    for (int i = 1; i < n; i++) {
        int d = ask(0, i);
        if (d > maxd) {
            maxd = d;
            id = i;
        }
    }
 
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int d = (i == id ? 0 : ask(id, i));
        a[i] = {d, i};
    }
    std::sort(a.begin(), a.end());

    std::vector<int> ans1(n), ans2(n);
    std::vector<int> seq = gen(n);
    for (int i = 0; i < n; i++) {
        ans1[a[i].second] = seq[i];
        ans2[a[i].second] = seq[n - i - 1];
    }

    std::cout << "! ";
    for (int i = 0; i < n; i++) {
        std::cout << ans1[i] + 1 << " ";
    }
    for (int i = 0; i < n; i++) {
        std::cout << ans2[i] + 1 << " ";
    }
    std::cout << std::endl;
    int ok;
    std::cin >> ok;
    if (ok != 1) {
        exit(0);
    }
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
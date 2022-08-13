#include <bits/stdc++.h>

void solve() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> a(n + 1);
    int p, rest = d;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        int temp = a[i] - a[i - 1] - 1;
        if(rest > temp) {
            rest = temp;
            p = i;
        }
    }

    int ans = 0;
    for(int x : {p - 1, p}) {
        if(x < 1) {
            continue;
        }
        std::vector<int> b(a);
        b.erase(b.begin() + x);

        int max_rest = 0;
        int min_rest = d;
        for(int i = 1; i <= n - 1; i++) {
            max_rest = std::max(max_rest, b[i] - b[i - 1] - 1);
            min_rest = std::min(min_rest, b[i] - b[i - 1] - 1);
        }

        int new_rest = std::max(d - b[n - 1] - 1, (max_rest - 1) / 2);
        ans = std::max(ans, std::min(min_rest, new_rest));
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        solve();
    }

    return 0;
}
/**
 * @author: XiaFan
 * @date: 2023-11-26 23:25
 */
#include <bits/stdc++.h>

using i64 = long long;


constexpr int N = 1E5;
 
std::vector<std::vector<int>> divs;
std::vector<int> phi;

void init() {
    divs.resize(N + 1);
    phi.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divs[j].push_back(i);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        phi[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            phi[j] -= phi[i];
        }
    }
}


void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    i64 ans = 0;
    std::array<int, N + 1> f{};
    for (int i = 0; i < n; i++) {
        for (auto d : divs[a[i]]) {
            ans += 1LL * phi[d] * f[d] * (n - 1 - i);
            f[d] += 1;
        }
    }
    std::cout << ans << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    // for (int i = 1; i <= 100; i++) {
    //     std::cerr << "phi[" << i << "] = " << phi[i] << '\n';
    // }

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
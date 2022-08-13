#include <bits/stdc++.h>

using i64 = long long;

int find(int i, std::vector<int> &f) {
    if(f[i] != i) {
        f[i] = find(f[i], f);
    }
    return f[i];
}

void unity(int i, int j, std::vector<int> &f) {
    int fi = find(i, f);
    int fj = find(j, f);
    if(fi != fj) {
        f[fi] = fj;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> f(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        f[i] = i;
    }

    for(int i = 0; i < n - 1; i++) {
        if(std::abs(a[i] - a[i + 1]) <= k) {
            unity(i, i + 1, f);
        }
        if(std::abs(a[i] - b[i + 1]) <= k) {
            unity(i, n + i + 1, f);
        }
        if(std::abs(b[i] - b[i + 1]) <= k) {
            unity(n + i, n + i + 1, f);
        }
        if(std::abs(b[i] - a[i + 1]) <= k) {
            unity(n + i, i + 1, f);
        }
    }

    // clang-format off
    if(find(0, f) == find(n - 1, f) || 
       find(0, f) == find(2 * n - 1, f) || 
       find(n, f) == find(n - 1, f) ||
       find(n, f) == find(2 * n - 1, f))
    // clang-format on
    {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}
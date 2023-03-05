#include <bits/stdc++.h>

typedef long long i64;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::array<int, 4>> b;

    for(int i = -1, j = 0, cur = 0, nega = 0; j <= n; j++) {
        if(j == n) {
            if(i + 1 <= n - 1) {
                b.push_back({i + 1, n - 1, cur, nega});
            }
            break;
        }

        std::cin >> a[j];
        if(std::abs(a[j]) == 2) {
            cur++;
        }
        if(a[j] < 0) {
            nega++;
        }

        if(a[j] == 0) {
            if(i + 1 <= j - 1) {
                b.push_back({i + 1, j - 1, cur, nega});
            }
            i = j;
            cur = 0;
            nega = 0;
        }
    }

    if(b.size() == 0) {
        std::cout << n << ' ' << 0 << '\n';
        return;
    }

    int left = 0, right = n - 1, sum = -1;
    for(auto [begin, end, cur, nega] : b) {
        // std::cerr << begin << end << cur << nega << '\n';
        if(nega % 2 == 0) {
            if(cur > sum) {
                sum = cur;
                left = begin;
                right = end;
            }
            continue;
        }

        int ccur = cur;
        int r = 0, l = 0;
        for(int i = begin; i <= end; i++) {
            if(std::abs(a[i]) == 2) {
                ccur--;
            }
            if(a[i] < 0) {
                l = i;
                break;
            }
        }
        if(ccur > sum) {
            sum = ccur;
            left = l + 1;
            right = end;
        }

        ccur = cur;
        for(int i = end; i >= begin; i--) {
            if(std::abs(a[i]) == 2) {
                ccur--;
            }
            if(a[i] < 0) {
                r = i;
                break;
            }
        }
        if(ccur > sum) {
            sum = ccur;
            left = begin;
            right = r - 1;
        }
    }

    std::cout << left << ' ' << n - 1 - right << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
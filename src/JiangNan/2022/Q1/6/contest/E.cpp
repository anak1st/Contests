/**
 * @author: XiaFan
 * @date: 04-17 21:45
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    i64 l;
    std::cin >> n >> m >> l;
    std::vector<i64> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int ans = 0;
    for(int p = 0; p < n - 1; p++) {
        if(a[p] > l && a[p + 1] <= l) {
            ans++;
        }
    }
    if(a[n - 1] > l) {
        ans++;
    }

    for(int i = 0; i < m; i++) {
        i64 t;
        std::cin >> t;
        if(t == 0) {
            std::cout << ans << "\n";
        } else {
            int p;
            i64 d;
            std::cin >> p >> d;
            p--;

            if(a[p] <= l && a[p] + d > l) {
                if(n == 1) {
                    ans++;
                } else if(p >= 1 && p < n - 1) {
                    i64 left = a[p - 1];
                    i64 right = a[p + 1];
                    if(left > l && right > l) {
                        ans--;
                    }
                    if(left <= l && right <= l) {
                        ans++;
                    }
                } else if(p == 0) {
                    i64 right = a[p + 1];
                    if(right <= l) {
                        ans++;
                    }
                } else if(p == n - 1) {
                    i64 left = a[p - 1];
                    if(left <= l) {
                        ans++;
                    }
                }
            }

            a[p] += d;
        }
    }

    return 0;
}
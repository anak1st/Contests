#include <bits/stdc++.h>

#define ALL(NAME) NAME.begin(), NAME.end()

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    while(T--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) {
            int x;
            std::cin >> x;
            a[x] = i;
        }

        std::vector<int> ans(n + 2);
        for(int i = n; i >= 1; i--) {
            int p = a[i];
            for(int j = n; j >= i + 1; j--) {
                p -= ans[j];
                if(p <= 0) {
                    p += j;
                }
            }

            if(p == i) {
                ans[i] = 0;
            } else {
                ans[i] = p;
            }
        }

        for(int i = 1; i <= n; i++) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

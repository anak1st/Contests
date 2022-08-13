#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::set<int> v;
    int ans = n;
    for(int i = 1; i <= n; i++) {
        std::set<int> u;
        if(v.count(i)) {
            continue;
        }

        u.insert(i);
        int p = i;

        bool flag = false;
        while(1) {
            p = a[p];
            if(v.count(p)) {
                flag = true;
                break;
            }
            if(u.count(p)) {
                break;
            }
            u.insert(p);
        }

        if(flag) {
            continue;
        }

        v.insert(u.begin(), u.end());

        int cur = 0;
        int start = p;
        while(1) {
            p = a[p];
            cur++;
            if(p == start) {
                break;
            }
        }

        ans = std::min(ans, cur);
    }
    std::cout << ans << '\n';

    return 0;
}
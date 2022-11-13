/**
 * @author: XiaFan
 * @date: 09-13 20:38
 **/
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::priority_queue<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        a.push(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        b.push(x);
    }
    int ans = 0;
    while (!a.empty()) {
        // std::cout << a.top() << " " << b.top() << "\n";
        if (a.top() == b.top()) {
            a.pop();
            b.pop();
        } else if (a.top() > b.top()) {
            int x = a.top();
            a.pop();
            x = log10(x) + 1;
            a.push(x);
            ans++;
        } else {
            int x = b.top();
            b.pop();
            x = log10(x) + 1;
            b.push(x);
            ans++;
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt;
    std::cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}
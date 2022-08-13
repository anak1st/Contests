/**
 * @author: XiaFan
 * @date: 04-19 09:36
 **/
#include <bits/stdc++.h>

typedef long long i64;
typedef unsigned long long u64;

void solve() {
    int n, r, b;
    std::cin >> n >> r >> b;

    int remain = r;
    for(int i = 1; i <= b; i++) {
        // r b[i] r ... b[last] r
        // ^
        int num = remain / (b - (i - 1) + 1);
        std::cout << std::string(num, 'R');
        remain -= num;
        std::cout << 'B';
    }
    std::cout << std::string(remain, 'R');

    std::cout << '\n';
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
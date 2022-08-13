#include <algorithm>
#include <iostream>
#include <vector>

struct cow {
    int l, r;
    bool operator<(const cow& a) {
        return l < a.l;
    }
};

int main() {
    int n, T;
    std::cin >> n >> T;
    std::vector<cow> c(n);
    for(int i = 0; i < n; i++) {
        std::cin >> c[i].l >> c[i].r;
    }
    std::sort(c.begin(), c.end());
    int ans = 0, end = 0, p = 0;
    while(end < T && p < n) {
        int start = end + 1;
        for(int i = p; i < n; i++) {
            if(c[i].l <= start) {
                end = std::max(end, c[i].r);
            } else {
                p = i;
                break;
            }
        }
        if(start > end) {
            std::cout << -1 << '\n';
            return 0;
        } else {
            ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
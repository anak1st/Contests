#include <bits/stdc++.h>

using i64 = long long;

i64 fun(i64 x) {
    return (i64)std::sqrt(x / 2 + 1);
}

struct num {
    i64 x;
    int l, r;

    num(i64 x_, int l_, int r_) : x(x_), l(l_), r(r_) {}

    friend bool operator<(const num &lhs, const num &rhs) {
        if(lhs.x == rhs.x) {
            return (lhs.l > rhs.l);
        }
        return (lhs.x < rhs.x);
    }

    void debug() {
        std::cout << "x:" << x << " l:" << l << " r:" << r << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::priority_queue<num> q;
    for(int i = 1; i <= n; i++) {
        i64 x;
        std::cin >> x;
        if(x > 1) {
            q.push(num(x, i, i));
        }
    }

    i64 ans = 0;
    while(!q.empty()) {
        num now = q.top();
        q.pop();

        while(!q.empty() && now.r + 1 == q.top().l && now.x == q.top().x) {
            now.r = q.top().r;
            q.pop();
        }
        // now.debug();

        ans++;
        now.x = fun(now.x);
        if(now.x > 1) {
            q.push(now);
        }
    }
    std::cout << ans << '\n';

    return 0;
}
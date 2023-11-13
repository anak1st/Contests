#include<bits/stdc++.h>
#define speed std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define endl '\n'
#define ms(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const long double pi = std::acos(-1.0);
constexpr long double eps = 1e-8;
constexpr ll mod = 998244353;
constexpr int Mx = 2e5 + 7;
typedef std::pair<int, int> pii;

struct Point {
    ll x, y;
    void input() {
        std::cin >> x >> y;;
    }
    ll dis(Point t) {
        return abs(t.x - x) + abs(t.y - y);
    }
}A, B, C;
ll solve() {
    A.input();
    B.input();
    C.input();
    if ((B.x - A.x) * (C.x - A.x) < 0) {
        if ((B.y - A.y) * (C.y - A.y) <= 0)
            return 1;
        else
            return std::min(abs(B.y - A.y), abs(C.y - A.y)) + 1;
    }
    else {
        if ((B.y - A.y) * (C.y - A.y) <= 0)
            return std::min(abs(B.x - A.x), abs(C.x - A.x)) + 1;
        return std::min(A.dis(B), A.dis(C)) + 1;
    }
}
int main() {
    speed;
    int t;
    std::cin >> t;
    while (t--)
        std::cout << solve() << endl;
    return 0;
}
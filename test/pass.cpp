#include<bits/stdc++.h>
#define speed std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0)
#define endl '\n'
#define ms(a, b) memset(a, b, sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
const int INF = 0x3f3f3f3f;
const long double pi = std::acos(-1.0);
constexpr long double eps = 1e-10;
constexpr ll mod = 998244353;
constexpr int Mx = 2e5 + 7;
typedef std::pair<int, int> pii;

struct seg {
    int l, r;
    bool operator<(seg& t) {
        return l < t.l;
    }
}rain[Mx];
int minus[Mx];
int solve() {
    int n, m, k, i, ans = 0, point = 1;
    std::map<pii, int> seg_num;
    std::cin >> n >> m >> k;  //cities days power_days
    for (i = 1; i <= n + 1; ++i)
        minus[i] = 0;
    for (i = 1; i <= m; ++i) {
        std::cin >> rain[i].l >> rain[i].r;
        ++minus[rain[i].l], --minus[rain[i].r + 1];
    }
    for (i = 1; i <= n; ++i) {
        minus[i] += minus[i - 1];
        if (minus[i] == 0)
            ++ans;
    }
    int zero = ans;
    std::sort(rain + 1, rain + 1 + m);
    for (i = 1; i <= n; ++i) {
        if (minus[i] == 1) {
            int seg1 = 0;
            for (; point <= m; ++point)
                if (rain[point].r >= i && rain[point].l <= i && seg1 == 0) {
                    seg1 = point;
                    break;
                }
            ++seg_num[{seg1, 0}];
        }
        else if (minus[i] == 2) {
            int seg1 = 0, seg2 = 0;
            for (; point <= m; ++point)
                if (rain[point].r >= i && rain[point].l <= i && seg1 == 0)
                    seg1 = point;
                else if (rain[point].r >= i && rain[point].l <= i) {
                    seg2 = point;
                    break;
                }
            ++seg_num[{seg1, seg2}];
            point = seg1;
        }
    }
    for (auto p : seg_num) {
        auto [seg1, seg2] = p.first;
        if (seg2 == 0)
            ans = std::max(ans, zero + p.second);
        else
            ans = std::max(ans, zero + p.second + seg_num[{seg1, 0}] + seg_num[{seg2, 0}]);
    }
    return ans;

}
int main() {
    speed;
    int t;
    std::cin >> t;
    while (t--)
        std::cout << solve() << endl;
    return 0;
}
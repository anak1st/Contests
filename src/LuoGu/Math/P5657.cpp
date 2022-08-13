#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using std::cin, std::cout, std::vector;

u64 pow2(u64 x) {
    return ((u64)1 << x);
}

std::string get_ans(u64 n, u64 k) {
    std::string ans;
    for(u64 i = n; i >= 1; i--) {
        if(k < pow2(i - 1)) {
            ans.push_back('0');
        } else {
            ans.push_back('1');
            if(i == 64) {
                k = std::numeric_limits<u64>::max() - k;
            } else {
                k = pow2(i) - k - 1;
            }
        }
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    u64 n, k;
    cin >> n >> k;
    cout << get_ans(n, k) << '\n';

    /*
    std::cout << "-----\n";
    for(u64 i = 0; i < pow2(n); i++) {
        std::cout << get_ans(n, i) << '\n';
    }
    */

    return 0;
}
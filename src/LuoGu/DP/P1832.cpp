// P1832 A+B Problem (再升级) 普及-
// 动态规划,dp 数论,数学 递推 背包 素数判断,质数,筛法
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Prime {
    vector<int> num;
    Prime(int x) {
        num.push_back(2);
        for(int i = 3; i <= x; i += 2) {
            bool flag = true;
            for(auto j : num) {
                if(i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                num.push_back(i);
            }
        }
    }
    void print() {
        for(auto i : num) {
            cout << i << endl;
        }
    }
};

constexpr int maxN = 1234;
i64 dp[maxN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    Prime p(x);
    for(auto i : p.num) {
        dp[i]++;
        for(int j = i; j <= x; j++) {
            dp[j] += dp[j - i];  //
        }
    }
    cout << dp[x] << endl;
    return 0;
}
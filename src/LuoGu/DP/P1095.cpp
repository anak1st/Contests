// P1095 守望者的逃离 普及/提高-
// 动态规划,dp 贪心
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

constexpr int maxN = 1234;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, S, T;
    cin >> M >> S >> T;
    int s1 = 0, s2 = 0;
    for(int t = 1; t <= T; t++) {
        s1 += 17;
        if(M >= 10) {
            M -= 10;
            s2 += 60;
        } else {
            M += 4;
        }
        if(s2 > s1) {
            s1 = s2;
        }
        if(s1 >= S) {
            cout << "Yes\n" << t << endl;
            return 0;
        }
    }
    cout << "No\n" << s1 << endl;
    return 0;
}